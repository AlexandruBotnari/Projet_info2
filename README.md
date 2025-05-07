# Projet Info2

Ce projet implémente en C une **simulation de combats mythologiques au tour par tour** pour 1 ou 2 joueurs.  
Chaque joueur constitue son équipe en sélectionnant des combattants prédéfinis, chargés depuis des fichiers `data/*.txt`, puis s’affronte jusqu’à ce qu’une équipe soit complètement mise K.O.

## Contenu du projet

Le dépôt contient :

- **README.md** : documentation (ce fichier).
- **Makefile** : script de compilation.
- **src/** : code source en C :
  - `combat.c`, `combat.h` : logique de simulation de combat
  - `combattant.c`, `combattant.h` : chargement et gestion des entités
  - `equipe.c`, `equipe.h` : assemblage des équipes
  - `environnement.c`, `environnement.h` : effets et modificateurs globaux
  - `technique.c`, `technique.h` : stratégies de combat
  - `interface.c`, `interface.h` : affichage et options CLI
- **data/** : fichiers `.txt` décrivant les divinités et les environnements :
  - `template_divinite.txt`
  - `template_env.txt`
- **bin/** : dossier contenant le binaire produit (`projet`).

## Installation

1. Cloner le dépôt :
   ```bash
   git clone https://<votre-repo>/Projet_info2.git
   cd Projet_info2


# Compiler le projet
gmake # ou make


## Usage
# Lancer le programme
./projet


## Configuration des données
* Les fichiers `.txt` contiennent les caractéristiques des divinités (ex. : `Zeus.txt`, `Artémis.txt`, …) et des environnements (`montagne.txt`, `orage.txt`, …).
* Pour ajouter ou modifier un combattant ou un environnement, éditez ou créez un fichier `.txt` au même format.

## Structure du projet
Projet_info2/
├── combat.c, combat.h               # Logique de simulation de combat
├── combattant.c, combattant.h       # Gestion des combattants
├── equipe.c, equipe.h               # Gestion des équipes
├── environnement.c, environnement.h # Définition des environnements
├── technique.c, technique.h         # Techniques et stratégies de combat
├── couleurs_console.h               # Configuration des couleurs de sortie
├── interface.c, interface.h         # Affichage sur la console
├── main.c                           # Point d'entrée
├── *.txt                            # Fichiers de données (divinités et environnements)
├── makefile                         # Script de compilation
└── README.md                        # Documentation du projet

## Contribuer
1. Forker le dépôt 
2. Créer une branche `feature/<nom_feature>` 
3. Soumettre une Pull Request

## Licence
Ce projet est sous licence MIT. Voir le fichier `LICENSE` pour plus de détails.

## Auteur


