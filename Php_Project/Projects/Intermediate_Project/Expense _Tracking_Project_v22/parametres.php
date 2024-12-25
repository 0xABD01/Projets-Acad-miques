<?php
// Inclusion de l'en-tête du site
include 'header.php'; 

// Inclusion du fichier de configuration pour la connexion à la base de données
include 'includes/config.php'; 

// Récupération de tous les budgets enregistrés dans la base de données
$budgets = $pdo->query("SELECT montant_max, periode FROM Budgets ORDER BY periode DESC")->fetchAll();

// Récupération du dernier budget enregistré pour vérifier un éventuel dépassement de budget
$dernierBudget = $pdo->query("SELECT montant_max, periode FROM Budgets ORDER BY periode DESC LIMIT 1")->fetch();

// Vérification si un dernier budget a été trouvé
if ($dernierBudget === false) {
    // Si aucun budget n'est trouvé, affichage d'un message d'erreur
    echo "<p style='color: red;'>Aucun budget trouvé pour cette période.</p>";
} else {
    // Si un dernier budget existe, calcul du total des dépenses pour la période
    $totalDepenses = $pdo->query("SELECT SUM(montant) as total FROM Depenses 
                                  WHERE date_depense BETWEEN '{$dernierBudget['periode']}-01' AND '{$dernierBudget['periode']}-31'")->fetchColumn();

    // Vérification si les dépenses dépassent le budget
    if ($totalDepenses > $dernierBudget['montant_max']) {
        // Si les dépenses dépassent le budget, affichage de l'alerte avec le montant du dépassement
        echo "<p style='color: red;'>Alerte : Vous avez dépassé votre budget de " . ($totalDepenses - $dernierBudget['montant_max']) . " DHs pour la période {$dernierBudget['periode']}.</p>";
    }
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <!-- Définition du charset et du viewport pour la mise en page responsive -->
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Paramètres de Budget</title>
    <!-- Lien vers le fichier CSS pour le style de la page -->
    <link rel="stylesheet" href="Style/parametres.css"> <!-- Remplacez par le chemin correct de votre fichier CSS -->
</head>
<body>

<h1>Paramètres de Budget</h1>

<?php
// Inclusion du fichier Budget.php contenant la logique de gestion des budgets
include 'includes/Budget.php';

// Vérification si le formulaire a été soumis via POST
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Création d'un objet Budget avec les données soumises
    $budget = new Budget(null, $_POST['montant_max'], $_POST['periode']);
    // Ajout du budget dans la base de données
    $budget->ajouterBudget($pdo);
    // Redirection vers la page d'accueil après l'ajout
    header("Location: index.php");
    exit;
}
?>

<!-- Affichage des budgets enregistrés dans un tableau -->
<h2>Budgets Enregistrés</h2>

<section>

<?php if (count($budgets) > 0): ?>
    <table>
        <thead>
            <tr>
                <th>Période</th>
                <th>Montant Max</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($budgets as $budget): ?>
                <tr>
                    <!-- Affichage des informations des budgets dans le tableau -->
                    <td><?= htmlspecialchars($budget['periode']); ?></td>
                    <td><?= number_format($budget['montant_max'], 2, ',', ' ') . ' DHs'; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
<?php else: ?>
    <!-- Message si aucun budget n'est enregistré -->
    <p>Aucun budget enregistré pour le moment.</p>
<?php endif; ?>

</section>

<!-- Formulaire d'ajout de budget -->
<h2>Ajouter un Budget</h2>
<section>

<form method="post">
    <!-- Champ pour saisir le montant maximum du budget -->
    <label>Montant Max :</label>
    <input type="number" step="0.01" name="montant_max" required>
    
    <!-- Champ pour saisir la période du budget -->
    <label>Période :</label>
    <input type="month" name="periode" required>
    
    <!-- Bouton pour soumettre le formulaire -->
    <button type="submit">Ajouter</button>
</form>

</section>

</body>
</html>

<?php
// Inclusion du pied de page
include 'footer.php'; 
?>
