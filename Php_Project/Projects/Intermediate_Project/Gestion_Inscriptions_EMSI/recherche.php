lusion des fonctions
include 'fonction.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $first_name = $_POST['search_first_name'];
    $last_name = $_POST['search_last_name'];

    if (rechercherEtudiant($first_name, $last_name)) {
        echo "L'étudiant $first_name $last_name a été trouvé.";
    } else {
        echo "Aucun étudiant avec ce nom et prénom n'a été trouvé.";
    }
}

include 'retour.php';
?>



