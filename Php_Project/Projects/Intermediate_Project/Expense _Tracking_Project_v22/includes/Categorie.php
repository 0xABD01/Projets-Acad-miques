<?php
// Classe pour gérer les catégories
class Categorie {
    // Attributs privés de la classe
    private $id; // Identifiant unique de la catégorie
    private $nom; // Nom de la catégorie
    private $description; // Description de la catégorie

    // Constructeur pour initialiser les attributs de la classe
    public function __construct($id, $nom, $description) {
        $this->id = $id; // Initialise l'ID de la catégorie
        $this->nom = $nom; // Initialise le nom de la catégorie
        $this->description = $description; // Initialise la description de la catégorie
    }

    // **Getters et Setters** : méthodes pour accéder et modifier les attributs

    // Getter pour l'ID (lecture seule)
    public function getId() {
        return $this->id;
    }

    // Getter pour le nom de la catégorie
    public function getNom() {
        return $this->nom;
    }

    // Setter pour modifier le nom de la catégorie
    public function setNom($nom) {
        $this->nom = $nom;
    }

    // Getter pour la description de la catégorie
    public function getDescription() {
        return $this->description;
    }

    // Setter pour modifier la description de la catégorie
    public function setDescription($description) {
        $this->description = $description;
    }

    // **Méthode pour ajouter une catégorie dans la base de données**
    public function ajouterCategorie($pdo) {
        // Préparation de la requête SQL pour insérer une nouvelle catégorie
        $stmt = $pdo->prepare("INSERT INTO Categories (nom_categorie, description) VALUES (?, ?)");
        // Exécution de la requête avec les valeurs du nom et de la description de l'objet actuel
        $stmt->execute([$this->nom, $this->description]);
    }

    // **Méthode statique pour récupérer toutes les catégories**
    public static function getCategories($pdo) {
        // Exécution d'une requête pour sélectionner toutes les catégories
        $stmt = $pdo->query("SELECT * FROM Categories");

        // Tableau pour stocker les objets Categorie récupérés
        $categories = [];

        // Parcours des résultats et création d'objets Categorie pour chaque ligne
        while ($row = $stmt->fetch()) {
            $categories[] = new Categorie($row['id_categorie'], $row['nom_categorie'], $row['description']);
        }

        // Retourne un tableau contenant toutes les catégories
        return $categories;
    }
}
?>
