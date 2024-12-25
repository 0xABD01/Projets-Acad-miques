<?php
include 'header.php';
include 'includes/config.php';
include 'includes/Depense.php';
include 'includes/Categorie.php';

// Récupérer les catégories existantes
try {
    $categories = Categorie::getCategories($pdo);
} catch (PDOException $e) {
    die("Erreur lors de la récupération des catégories : " . $e->getMessage());
}

// Récupérer les dépenses
try {
    $stmt = $pdo->prepare("
        SELECT 
            d.id_depense, 
            d.montant, 
            d.date_depense, 
            c.nom_categorie 
        FROM Depenses d
        LEFT JOIN Categories c ON d.id_categorie = c.id_categorie
        ORDER BY d.date_depense DESC
    ");
    $stmt->execute();
    $depenses = $stmt->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    die("Erreur lors de la récupération des dépenses : " . $e->getMessage());
}

// Ajouter une dépense
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['action']) && $_POST['action'] === 'add_depense') {
    $depense = new Depense(null, $_POST['montant'], $_POST['date_depense'], $_POST['id_categorie']);
    $depense->ajouterDepense($pdo);
    header("Location: depenses.php?success=depense-ajoutee");
    exit;
}

// Ajouter une catégorie
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['action']) && $_POST['action'] === 'add_categorie') {
    $categorie = new Categorie(null, $_POST['nom_categorie'], $_POST['description']);
    $categorie->ajouterCategorie($pdo);
    header("Location: depenses.php?success=categorie-ajoutee");
    exit;
}

// Suppression d'une dépense
if (isset($_GET['id']) && !empty($_GET['id'])) {
    $id_depense = $_GET['id'];
    try {
        $stmt = $pdo->prepare("DELETE FROM Depenses WHERE id_depense = ?");
        $stmt->execute([$id_depense]);
        header("Location: depenses.php?success=depense-supprimee");
        exit;
    } catch (PDOException $e) {
        die("Erreur lors de la suppression de la dépense : " . $e->getMessage());
    }
}

// Vérification des mois où le budget est dépassé
try {
    $budgets = $pdo->query("SELECT montant_max, periode FROM Budgets ORDER BY periode DESC")->fetchAll();
} catch (PDOException $e) {
    die("Erreur lors de la récupération des budgets : " . $e->getMessage());
}

$moisDepasses = []; // Tableau pour stocker les mois où le budget est dépassé
foreach ($budgets as $budget) {
    // Calcul du total des dépenses pour chaque période
    $totalDepenses = $pdo->query("SELECT SUM(montant) as total FROM Depenses 
                                  WHERE date_depense BETWEEN '{$budget['periode']}-01' AND '{$budget['periode']}-31'")->fetchColumn();
    
    // Comparaison des dépenses avec le budget
    if ($totalDepenses > $budget['montant_max']) {
        $depassement = $totalDepenses - $budget['montant_max']; // Calcul du dépassement
        $moisDepasses[] = ['mois' => $budget['periode'], 'depassement' => $depassement]; // Ajouter le mois et la valeur du dépassement
    }
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gestion des Dépenses</title>
    <link rel="stylesheet" href="Style/depenses.css">
</head>
<body>
    <h1>Gestion des Dépenses</h1>

    <!-- Affichage des messages de succès -->
    <?php if (isset($_GET['success'])): ?>
        <p class="success-message">
            <?php
                if ($_GET['success'] === 'depense-ajoutee') echo "Dépense ajoutée avec succès !";
                if ($_GET['success'] === 'categorie-ajoutee') echo "Catégorie ajoutée avec succès !";
                if ($_GET['success'] === 'depense-supprimee') echo "Dépense supprimée avec succès !";
            ?>
        </p>
        
    <?php endif; ?>

    <!-- Section pour afficher les mois où le budget est dépassé -->
    <section>
        <h2>Alertes de Dépenses Dépassées</h2>
        <?php if (count($moisDepasses) > 0): ?>
            <ul>
                <?php foreach ($moisDepasses as $moisDepasse): ?>
                    <li style="color: red;">
                        Alerte : Vous avez dépassé votre budget pour le mois de <?= htmlspecialchars($moisDepasse['mois']); ?> Avec un Montant du  : <?= number_format($moisDepasse['depassement'], 2, ',', ' ') . '          DHs'; ?>
                    </li>
                <?php endforeach; ?>
            </ul>
        <?php else: ?>
            <p>Aucun mois n'a dépassé le budget.</p>
        <?php endif; ?>
    </section>

    <!-- Section pour afficher les dépenses -->
    <section>
        <h2>Liste des Dépenses</h2>
        <?php if (count($depenses) > 0): ?>
            <table>
                <thead>
                    <tr>
                        <th>Date</th>
                        <th>Montant</th>
                        <th>Catégorie</th>
                        <th>Actions</th> <!-- Ajout d'une colonne pour les actions -->
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($depenses as $depense): ?>
                        <tr>
                            <td><?= htmlspecialchars($depense['date_depense']); ?></td>
                            <td><?= number_format($depense['montant'], 2, ',', ' ') . '         DHs'; ?></td>
                            <td><?= htmlspecialchars($depense['nom_categorie'] ?? 'Non spécifiée'); ?></td>
                            <td>
                                <!-- Lien pour modifier la dépense -->
                                <a href="modifier_depense.php?id=<?= $depense['id_depense']; ?>">Modifier</a> |
                                
                                <!-- Lien pour supprimer la dépense avec confirmation -->
                                <a href="?id=<?= $depense['id_depense']; ?>" onclick="return confirm('Êtes-vous sûr de vouloir supprimer cette dépense ?')">Supprimer</a>
                            </td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        <?php else: ?>
            <p>Aucune dépense enregistrée pour le moment.</p>
        <?php endif; ?>
    </section>

    <!-- Section pour ajouter une dépense -->
    <section>
        <h2>Ajouter une Dépense</h2>
        <form method="post">
            <input type="hidden" name="action" value="add_depense">
            <label>Montant :</label>
            <input type="number" step="0.01" name="montant" required>
            <label>Date :</label>
            <input type="date" name="date_depense" required>
            <label>Catégorie :</label>
            <select name="id_categorie" required>
                <option value="">-- Choisir une catégorie --</option>
                <?php foreach ($categories as $categorie): ?>
                    <option value="<?= $categorie->getId() ?>"><?= $categorie->getNom() ?></option>
                <?php endforeach; ?>
            </select>
            <button type="submit">Ajouter</button>
        </form>
    </section>

    <!-- Section pour ajouter une catégorie -->
    <section>
        <h2>Ajouter une Catégorie</h2>
        <form method="post">
            <input type="hidden" name="action" value="add_categorie">
            <label>Nom de la catégorie :</label>
            <input type="text" name="nom_categorie" required>
            <label>Description :</label>
            <input type="text" name="description">
            <button type="submit">Ajouter</button>
        </form>
    </section>
</body>
</html>

<?php
include 'footer.php';
?>
