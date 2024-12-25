<?php
// Inclusion des fonctions
include 'fonction.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Vérifier si tous les champs sont remplis
    if (!empty($_POST['first_name']) && !empty($_POST['last_name']) && !empty($_POST['date_of_birth']) && !empty($_POST['email']) && !empty($_POST['telephone']) && !empty($_POST['niveau'])) {
        $first_name = $_POST['first_name'];
        $last_name = $_POST['last_name'];
        $date_of_birth = $_POST['date_of_birth'];
        $email = $_POST['email'];
        $telephone = $_POST['telephone'];
        $niveau = $_POST['niveau'];
        
        if(!rechercherEtudiantByInfo($first_name, $last_name, $date_of_birth, $email, $telephone, $niveau) ){
            
            // Calculer et afficher l'âge de l'étudiant
            $age = calculerAge($date_of_birth);
            
            // Affichage du message de bienvenue
            echo "Bienvenue, $first_name $last_name !<br>";
            echo "<p><strong>Date de Naissance :</strong> $date_of_birth</p>";
            echo "<p><strong>Age :</strong> $age</p>";
            echo "<p><strong>Email :</strong> $email</p>";
            echo "<p><strong>Téléphone :</strong> $telephone</p>";
            echo "<p><strong>Niveau :</strong> $niveau</p>";
            
            // Enregistrer les données de l'étudiant
            enregistrerEtudiant($first_name, $last_name, $date_of_birth, $email, $telephone, $niveau);
            
            echo "Votre inscription a été enregistrée avec succès !";
        }else{
            echo "L'étudiant $first_name $last_name est deja enregistrer .";
        }
    } else {
        echo "Veuillez compléter tous les champs.";
    }
}
include 'retour.php';

?>
