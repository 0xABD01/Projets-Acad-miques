<?php
// **Configuration de la base de données**
$host = 'localhost'; // L'adresse de l'hôte du serveur MySQL (par défaut 'localhost')
$dbname = 'suivi_depenses'; // Nom de la base de données à laquelle se connecter
$username = 'root'; // Nom d'utilisateur pour se connecter à MySQL
$password = ''; // Mot de passe pour l'utilisateur MySQL (laisser vide si aucun mot de passe)

// **Bloc try-catch pour gérer la connexion à la base de données**
try {
    // Créer une instance PDO pour établir la connexion avec MySQL
    // Le DSN (Data Source Name) inclut l'hôte et le nom de la base
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    
    // **Définir le mode d'erreur de PDO**
    // `PDO::ATTR_ERRMODE` permet de configurer PDO pour qu'il lève des exceptions en cas d'erreur
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    // **Optionnel : Configurer l'encodage des caractères**
    // `SET NAMES 'UTF8'` assure que les échanges avec la base de données utilisent UTF-8
    $pdo->exec("SET NAMES 'UTF8'");
} catch (PDOException $e) {
    // **Gestion des erreurs**
    // Si la connexion échoue, afficher un message d'erreur et arrêter l'exécution
    die("La connexion à la base de données a échoué : " . $e->getMessage());
}

?>
