<?php
// Inclusion des fonctions
include 'fonction.php';
echo"<h1>1re_annee</h1><hr>";
afficherEtudiantsParNiveau("1re_annee");
echo"<h1>2me_annee</h1><hr>";
afficherEtudiantsParNiveau("2me_annee");
echo"<h1>3me_annee</h1><hr>";
afficherEtudiantsParNiveau("3me_annee");
echo"<hr>";

include 'retour.php';

?>
