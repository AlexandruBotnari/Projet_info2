# Projet_info2

## Description
Ce projet propose une simulation de combats mythologiques en C.
Chaque divinité et environnement est décrit dans un fichier `.txt` et modélisé par des modules C dédiés.
L'objectif est de permettre à deux équipes de combattants de s'affronter dans différents environnements.

## Prérequis
* **GCC** (ou tout autre compilateur C compatible ANSI C)
* **make**
* Système d'exploitation Unix/Linux ou macOS

## Installation & Compilation
# Cloner le dépôt
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


