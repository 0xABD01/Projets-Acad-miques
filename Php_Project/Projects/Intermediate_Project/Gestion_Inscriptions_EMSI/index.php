<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>EMSI</title>
    <link rel="stylesheet" href="form_style.css">
</head>
<body>
    <div class="container">
        <hr>
        <h2>Formulaire d'Inscription</h2>
        <form action="traitement.php" method="POST">
            <div>
                <!-- Nom -->
                <div class="row">
                    <div class="col-25">
                        <label for="fName">Nom :</label>
                    </div>
                    <div class="col-75">
                        <input type="text" id="fName" name="first_name" placeholder="Nom.." required>
                    </div>
                </div>
                
                <!-- Prénom -->
                <div class="row">
                    <div class="col-25">
                        <label for="lName">Prénom :</label>
                    </div>
                    <div class="col-75">
                        <input type="text" id="lName" name="last_name" placeholder="Prénom.." required>
                    </div>
                </div>
                
                <!-- Date de naissance -->
                <div class="row">
                    <div class="col-25">
                        <label for="dBirth">Date de Naissance :</label>
                    </div>
                    <div class="col-75">
                        <input type="date" id="dBirth" name="date_of_birth" required>
                    </div>
                </div>
                
                <!-- Email -->
                <div class="row">
                    <div class="col-25">
                        <label for="Email">Email :</label>
                    </div>
                    <div class="col-75">
                        <input type="email" id="Email" name="email" placeholder="Email.." required>
                    </div>
                </div>
                
                <!-- Numéro de téléphone -->
                <div class="row">
                    <div class="col-25">
                        <label for="nPhone">Numéro de Téléphone :</label>
                    </div>
                    <div class="col-75">
                        <input type="tel" id="nPhone" name="telephone" placeholder="+212" pattern="^\+212\d{9}$" required>
                    </div>                                                               <!--pattern="+212[19][19][19][19][19][19][19][19][19]" -->
                </div>
                
                <!-- Niveau -->
                <div class="row">
                    <div class="col-25">
                        <label for="Niveau">Niveau :</label>
                    </div>
                    <div class="col-75">
                        <select id="Niveau" name="niveau">
                            <option value="1re_annee">1re année</option>
                            <option value="2me_annee">2me année</option>
                            <option value="3me_annee">3me année</option>
                        </select>
                    </div>
                </div>
            </div>
            <br>
            <div class="row">
                <input type="submit" value="Inscrire">
            </div>
            <br>  
        </form>
        <br>
        <hr>
        <!-- formulaire pour l'affichage des etudiant inscrit -->
        <h2>Afficher Des Etudiant Par Niveau</h2>
        <form action="affichage.php">
            <div class="row">
                <input type="submit" value="Afficher ">
            </div>
        </form>
        <hr>
        <h2>Recherche d'un Étudiant</h2>
        <form action="recherche.php" method="POST">
            <div class="row">
                <div class="col-25">
                    <label for="searchName">Nom :</label>
                </div>
                <div class="col-75">
                    <input type="text" id="searchName" name="search_first_name" required>
                </div>
            </div>
            <div class="row">
                <div class="col-25">    
                    <label for="searchLastName">Prénom :</label>
                </div>
                <div class="col-75">
                    <input type="text" id="searchLastName" name="search_last_name" required>
                </div>
            </div>
            <br>
            <div class="row">
                <input type="submit" value="Rechercher">
            </div>
        </form>
        <hr>
    </div>
</body>
</html>
