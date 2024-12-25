<?php
include 'header.php'; 
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="Style/accueil.css">
    <title>Accueil - Suivi des Dépenses</title>
</head>
<body>
    <!-- Section de présentation -->
    <section id="presentation">
        <h2>Bienvenue sur l'application de Suivi des Dépenses</h2>
        <p>Gérez vos finances de manière intelligente grâce à notre outil de suivi des dépenses. Visualisez vos données avec des graphiques interactifs et recevez des alertes pour respecter votre budget.</p>
    </section>



    
    <!-- Section des fonctionnalités principales -->
    <section id="fonctionnalites">
        <h2>Fonctionnalités Clés</h2>
        <div class="card">

        
            <h3>Ajouter des Dépenses</h3>
            <p>Enregistrez vos dépenses quotidiennes en quelques clics.</p>
        </div>
        <div class="card">
            <h3>Visualiser les Graphiques</h3>
            <p>Analysez vos dépenses grâce à des graphiques interactifs.</p>
        </div>
        <div class="card">
            <h3>Recevoir des Alertes</h3>
            <p>Restez informé des dépassements de budget en temps réel.</p>
        </div>
    </section>

    <!-- Section résumé du mois -->
    <section id="resume">
        <h2>Résumé du Mois</h2>
        <ul>
            <li>Total Dépenses : <strong>500 DHs</strong></li>
            <li>Catégorie la plus dépensée : <strong>Alimentation</strong></li>
            <li>Budget Restant : <strong>200 DHs</strong></li>
        </ul>
    </section>

    <!-- Section appel à l'action (CTA) -->
    <section id="cta">
        <button onclick="window.location.href='depenses.php'">Ajouter une Dépense</button>
        <button onclick="window.location.href='parametres.php'">Configurer le Budget</button>
    </section>
</body>
</html>

<?php
include 'footer.php';
?>
