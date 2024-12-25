<?php
// Fonction pour calculer l'âge de l'étudiant
function calculerAge($date_naissance) {
    $timestamp_naissance = strtotime($date_naissance);
    $date_actuelle = date('Y-m-d');
    $age = date('Y') - date('Y', $timestamp_naissance);
    if (date('m-d', strtotime($date_actuelle)) < date('m-d', $timestamp_naissance)) {
        $age--;
    }
    return $age;
}

// Fonction pour enregistrer l'étudiant dans le fichier correspondant
function enregistrerEtudiant($first_name, $last_name, $date_of_birth, $email, $telephone, $niveau) {
    switch ($niveau) {
        case '1re_annee':
            $fichier = "1re_annee.txt";
            break;
        case '2me_annee':
            $fichier = "2me_annee.txt";
            break;
        default:
            $fichier = "3me_annee.txt";
            break;
    }

    $ligne = "$first_name,$last_name,$date_of_birth,$email,$telephone,$niveau\n";
    file_put_contents($fichier, $ligne, FILE_APPEND | LOCK_EX);
}

// Fonction pour afficher les étudiants par niveau
function afficherEtudiantsParNiveau($niveau) {
    $file = "$niveau.txt";

    if (file_exists($file)) {
        $students = file($file, FILE_IGNORE_NEW_LINES);
        if (count($students) > 0) {
            echo "<table><tr><th>Nom</th><th>Prénom</th><th>D_Naissance</th><th>Email</th><th>Téléphone</th><th>Age</th></tr>";
            foreach ($students as $student) {
                $studentInfo = explode(",", $student);
                $age = calculerAge($studentInfo[2]);
                echo "<tr><td>{$studentInfo[0]}</td><td>{$studentInfo[1]}</td><td>{$studentInfo[2]}</td><td>{$studentInfo[3]}</td><td>{$studentInfo[4]}</td><td>$age</td></tr>";
            }
            echo "</table>";
        } else {
            echo "Aucun étudiant n'est enregistré dans ce niveau.";
        }
    } else {
        echo "Le fichier pour ce niveau n'existe pas.";
    }
}

// Fonction pour rechercher un étudiant par nom et prénom
function rechercherEtudiant($first_name, $last_name) {
    $levels = ['1re_annee', '2me_annee', '3me_annee'];
    foreach ($levels as $niveau) {
        $file = "$niveau.txt";
        if (file_exists($file)) {
            $students = file($file, FILE_IGNORE_NEW_LINES);
            foreach ($students as $student) {
                $studentInfo = explode(",", $student);
                if ($studentInfo[0] == $first_name && $studentInfo[1] == $last_name) {
                    return true;
                }
            }
        }
    }
    return false;
}
function rechercherEtudiantByInfo($first_name, $last_name, $date_of_birth, $email, $telephone, $niveau) {
    $levels = ['1re_annee', '2me_annee', '3me_annee'];
    foreach ($levels as $niveau) {
        $file = "$niveau.txt";
        if (file_exists($file)) {
            $students = file($file, FILE_IGNORE_NEW_LINES);
            foreach ($students as $student) {
                $studentInfo = explode(",", $student);
                if ($studentInfo[0] == $first_name && $studentInfo[1] == $last_name && $studentInfo[2] == $date_of_birth && $studentInfo[3] == $email && $studentInfo[4] ==$telephone && $studentInfo[5] ==$niveau) {
                    //$ligne = "$first_name,$last_name,$date_of_birth,$email,$telephone,$niveau\n";
                    return true;
                }
            }
        }
    }
    return false;
}
?>
