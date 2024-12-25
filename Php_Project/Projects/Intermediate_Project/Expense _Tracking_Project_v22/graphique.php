<?php
// Inclusion des fichiers nécessaires
include 'header.php'; 
include 'includes/config.php'; 

// Récupération des données pour les graphiques
try {
    $depenses = $pdo->query("
        SELECT c.nom_categorie, SUM(d.montant) as total 
        FROM Depenses d 
        JOIN Categories c ON d.id_categorie = c.id_categorie 
        
        GROUP BY c.nom_categorie
    ")->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    die("Erreur lors de la récupération des données : " . $e->getMessage());
}
?>



<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="Style/graphique.css"> <!-- CSS spécifique -->
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script> <!-- Chargement de Chart.js via CDN -->
    <title>Graphiques des Dépenses</title>
</head>
<body>
    <div class="container">
        <h1>Graphiques des Dépenses</h1>
        <canvas id="depensesChart"></canvas> <!-- Zone pour afficher le graphique -->
    </div>

    <script>
        // Données pour le graphique
        const data = {
            labels: <?= json_encode(array_column($depenses, 'nom_categorie')) ?>,
            datasets: [{
                label: 'Dépenses par catégorie',
                data: <?= json_encode(array_column($depenses, 'total')) ?>,
                backgroundColor: ['#FF6384', '#36A2EB', '#FFCE56', '#4BC0C0', '#9966FF'],
                hoverOffset: 4
            }]
        };

        // Configuration du graphique
        const config = {
            type: 'pie',
            data: data,
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        position: 'top',
                    },
                    tooltip: {
                        callbacks: {
                            label: function (context) {
                                const value = context.raw.toLocaleString('fr-FR', { style: 'currency', currency: 'EUR' });
                                return `${context.label}: ${value}`;
                            }
                        }
                    }
                }
            }
        };

        // Initialisation du graphique
        new Chart(document.getElementById('depensesChart'), config);
    </script>
</body>
</html>

<?php
include 'footer.php';
?>
