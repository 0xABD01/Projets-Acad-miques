<?php
// Classe pour gérer les dépenses
class Depense {
    // Attributs privés de la classe
    private $id; // Identifiant unique de la dépense
    private $montant; // Montant de la dépense
    private $date; // Date de la dépense
    private $categorie; // Identifiant de la catégorie associée à la dépense

    // **Constructeur** : Initialise les attributs de la classe
    public function __construct($id, $montant, $date, $categorie) {
        $this->id = $id; // Initialise l'identifiant
        $this->montant = $montant; // Initialise le montant
        $this->date = $date; // Initialise la date
        $this->categorie = $categorie; // Initialise la catégorie
    }

    // **Getters et Setters** : Accéder et modifier les attributs

    public function getId() {
        return $this->id; // Retourne l'identifiant
    }

    public function getMontant() {
        return $this->montant; // Retourne le montant
    }

    public function setMontant($montant) {
        $this->montant = $montant; // Modifie le montant
    }

    public function getDate() {
        return $this->date; // Retourne la date
    }

    public function setDate($date) {
        $this->date = $date; // Modifie la date
    }

    public function getCategorie() {
        return $this->categorie; // Retourne la catégorie
    }

    public function setCategorie($categorie) {
        $this->categorie = $categorie; // Modifie la catégorie
    }

    // **Méthodes pour les opérations sur la base de données**

    // Méthode pour ajouter une dépense dans la table `Depenses`
    public function ajouterDepense($pdo) {
        // Préparer la requête SQL pour insérer une dépense
        $stmt = $pdo->prepare("INSERT INTO Depenses (montant, date_depense, id_categorie) VALUES (?, ?, ?)");
        // Exécuter la requête avec les valeurs actuelles de l'objet
        $stmt->execute([$this->montant, $this->date, $this->categorie]);
    }

    // Méthode statique pour récupérer toutes les dépenses de la base de données
    public static function getDepenses($pdo) {
        // Exécuter une requête pour sélectionner toutes les lignes de la table `Depenses`
        $stmt = $pdo->query("SELECT * FROM Depenses");

        // Tableau pour stocker les objets `Depense`
        $depenses = [];

        // Parcourir les résultats et créer un objet `Depense` pour chaque ligne
        while ($row = $stmt->fetch()) {
            $depenses[] = new Depense($row['id_depense'], $row['montant'], $row['date_depense'], $row['id_categorie']);
        }

        // Retourner le tableau des dépenses
        return $depenses;
    }

    // Méthode pour modifier une dépense existante
    public function modifierDepense($pdo) {
        // Préparer la requête SQL pour mettre à jour une dépense
        $stmt = $pdo->prepare("UPDATE Depenses SET montant = ?, date_depense = ?, id_categorie = ? WHERE id_depense = ?");
        // Exécuter la requête avec les valeurs actuelles de l'objet
        $stmt->execute([$this->montant, $this->date, $this->categorie, $this->id]);
    }

    // Méthode pour supprimer une dépense
    public function supprimerDepense($pdo) {
        // Préparer la requête SQL pour supprimer une dépense
        $stmt = $pdo->prepare("DELETE FROM Depenses WHERE id_depense = ?");
        // Exécuter la requête en utilisant l'identifiant de l'objet
        $stmt->execute([$this->id]);
    }
}

?>
