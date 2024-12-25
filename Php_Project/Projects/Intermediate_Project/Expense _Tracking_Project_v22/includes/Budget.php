<?php
class Budget {
    // Attributs privés de la classe Budget
    private $id; // Identifiant unique du budget
    private $montantMax; // Montant maximal alloué au budget pour une période
    private $periode; // Période (par ex. "2024-12") associée au budget

    // Constructeur pour initialiser les attributs de la classe
    public function __construct($id, $montantMax, $periode) {
        $this->id = $id; // Initialise l'ID du budget
        $this->montantMax = $montantMax; // Initialise le montant maximum
        $this->periode = $periode; // Initialise la période
    }

    // Getters et Setters pour accéder et modifier les attributs

    // Getter pour l'ID du budget (lecture seule)
    public function getId() {
        return $this->id;
    }

    // Getter pour le montant maximal du budget
    public function getMontantMax() {
        return $this->montantMax;
    }

    // Setter pour modifier le montant maximal du budget
    public function setMontantMax($montantMax) {
        $this->montantMax = $montantMax;
    }

    // Getter pour la période du budget
    public function getPeriode() {
        return $this->periode;
    }

    // Setter pour modifier la période du budget
    public function setPeriode($periode) {
        $this->periode = $periode;
    }

    // Méthode pour ajouter un nouveau budget dans la base de données
    public function ajouterBudget($pdo) {
        // Préparation de la requête SQL pour insérer un budget
        $stmt = $pdo->prepare("INSERT INTO Budgets (montant_max, periode) VALUES (?, ?)");
        // Exécution de la requête avec les valeurs de l'objet actuel
        $stmt->execute([$this->montantMax, $this->periode]);
    }

    // Méthode statique pour récupérer un budget par sa période
    public static function getBudgetParPeriode($pdo, $periode) {
        // Préparation de la requête pour chercher un budget par période
        $stmt = $pdo->prepare("SELECT * FROM Budgets WHERE periode = ?");
        $stmt->execute([$periode]); // Exécution avec la période donnée
        $row = $stmt->fetch(); // Récupération de la ligne correspondante
        if ($row) {
            // Retourne un objet Budget si un résultat est trouvé
            return new Budget($row['id_budget'], $row['montant_max'], $row['periode']);
        }
        return null; // Retourne null si aucun budget n'existe pour cette période
    }

    // Méthode statique pour vérifier si les dépenses dépassent le budget pour une période
    public static function checkDepassementBudget($pdo, $periode) {
        // Récupère le budget correspondant à la période donnée
        $budget = Budget::getBudgetParPeriode($pdo, $periode);
        if ($budget) {
            // Préparation de la requête pour calculer le total des dépenses
            $stmt = $pdo->prepare("SELECT SUM(montant) AS total_depenses FROM Depenses WHERE date_depense LIKE ?");
            $stmt->execute([$periode . '%']); // Filtre par période
            $row = $stmt->fetch(); // Récupère le total des dépenses
            if ($row && $row['total_depenses'] > $budget->getMontantMax()) {
                // Retourne vrai si le total des dépenses dépasse le montant maximal
                return true;
            }
        }
        // Retourne faux si le budget n'est pas dépassé ou s'il n'existe pas
        return false;
    }
}
?>
