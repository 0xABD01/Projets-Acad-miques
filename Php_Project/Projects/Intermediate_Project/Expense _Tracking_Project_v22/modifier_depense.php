<?php
include 'header.php';
include 'includes/config.php';
include 'includes/Depense.php';
include 'includes/Categorie.php';

// Vérifier si l'ID de la dépense est passé via l'URL
if (isset($_GET['id']) && !empty($_GET['id'])) {
    $id_depense = $_GET['id'];

    try {
        // Récupérer les informations de la dépense à modifier
        $stmt = $pdo->prepare("SELECT * FROM Depenses WHERE id_depense = ?");
        $stmt->execute([$id_depense]);
        $depense = $stmt->fetch(PDO::FETCH_ASSOC);

        // Si la dépense n'existe pas
        if (!$depense) {
            die("Dépense non trouvée.");
        }
    } catch (PDOException $e) {
        die("Erreur lors de la récupération de la dépense : " . $e->getMessage());
    }
} else {
    
    die("ID de dépense manquant.");
}



// Récupérer les catégories existantes
try {
    $categories = Categorie::getCategories($pdo);
} catch (PDOException $e) {
    die("Erreur lors de la récupération des catégories : " . $e->getMessage());
}

// Traitement de la modification
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['action']) && $_POST['action'] === 'modify_depense') {
    $montant = $_POST['montant'];
    $date_depense = $_POST['date_depense'];
    $id_categorie = $_POST['id_categorie'];

    try {
        // Mise à jour de la dépense dans la base de données
        $stmt = $pdo->prepare("
            UPDATE Depenses
            SET montant = ?, date_depense = ?, id_categorie = ?
            WHERE id_depense = ?
        ");
        $stmt->execute([$montant, $date_depense, $id_categorie, $id_depense]);

        // Rediriger vers la page des dépenses avec un message de succès
        header("Location: depenses.php?success=depense-modifiee");
        exit;
    } catch (PDOException $e) {
        die("Erreur lors de la mise à jour de la dépense : " . $e->getMessage());
    }
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Modifier Dépense</title>
    <link rel="stylesheet" href="Style/depenses.css">
</head>
<body>
    <h1>Modifier la Dépense</h1>

    <!-- Affichage du message de succès -->
    <?php if (isset($_GET['success'])): ?>
        <p class="success-message">
            <?php if ($_GET['success'] === 'depense-modifiee') echo "Dépense modifiée avec succès !"; ?>
        </p>
    <?php endif; ?>

    <!-- Formulaire pour modifier la dépense -->
    <section>
        <form method="post">
            <input type="hidden" name="action" value="modify_depense">
            <label>Montant :</label>
            <input type="number" step="0.01" name="montant" value="<?= htmlspecialchars($depense['montant']); ?>" required>

            <label>Date :</label>
            <input type="date" name="date_depense" value="<?= htmlspecialchars($depense['date_depense']); ?>" required>

            <label>Catégorie :</label>
            <select name="id_categorie" required>
                
                <option value="">-- Choisir une catégorie --</option>
                <?php foreach ($categories as $categorie): ?>
                    <option value="<?= $categorie->getId(); ?>" <?= $categorie->getId() == $depense['id_categorie'] ? 'selected' : ''; ?>>
                        <?= htmlspecialchars($categorie->getNom()); ?>
                    </option>
                <?php endforeach; ?>
            </select>

            <button type="submit">Modifier</button>
        </form>
    </section>

    <a href="depenses.php">Retour à la liste des dépenses</a>
</body>
</html>

<?php include 'footer.php'; ?>
