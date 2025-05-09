# Projet Info2

Ce projet implémente en C une **simulation de combats mythologiques au tour par tour** pour 2 joueurs.  
Chaque joueur constitue son équipe en sélectionnant des combattants prédéfinis, chargés depuis des fichiers `data/*.txt`, puis s’affronte jusqu’à ce qu’une équipe soit complètement mise K.O.

---

## Contenu du projet

Le dépôt contient les fichiers suivants :

- **README.md** : documentation (ce fichier).
- **Makefile** : script de compilation et exécution.
- **Fichiers source en C** : code source en C :
  - `combat.c`, `combat.h` : logique de simulation de combat
  - `combattant.c`, `combattant.h` : chargement et gestion des entités
  - `equipe.c`, `equipe.h` : assemblage des équipes
  - `environnement.c`, `environnement.h` : effets et modificateurs globaux
  - `technique.c`, `technique.h` : stratégies de combat
  - `interface.c`, `interface.h` : affichage et options CLI
  -  main.c
  -  couleurs_console.h
- **Fichiers de données** (`.txt`) décrivant les divinités et environnements :
  - Artémis.txt, Atlas.txt, Déméter.txt, Héphaistos.txt, Ouranos.txt, Poséidon.txt, Téthys.txt, Zeus.txt, etc.
  - Aulis.txt, Keraunos.txt, Nysa.txt, Olympe.txt, Thalassa.txt, Orage.txt, etc.
---

## Installation

Cloner le dépôt :
   ```bash
   git clone https://<votre-repo>/Projet_info2.git
   cd Projet_info2


Compiler le projet
make
La commande `make` compile le code et exécute immédiatement l’exécutable `projet`.



## Utilisation
Au lancement, l’application demande successivement à chaque joueur de choisir ses combattants à partir de la liste affichée.  
Suivez les instructions à l’écran et entrez les indices correspondant aux divinités pour constituer vos équipes.

Lancer le programme :
./projet

# Fichiers de données
Les fichiers .txt du dossier data/ contiennent les caractéristiques des divinités et des environnements.

Exemple de fichier divinité :
Zeus 100 100 25 10 15 20 Foudre


Exemple de fichier environnement :
Montagne -10 0 5

couleurs_console.h
## Configuration des données
* Les fichiers `.txt` contiennent les caractéristiques des divinités (ex. : `Zeus.txt`, `Artémis.txt`, …) et des environnements (`montagne.txt`, `orage.txt`, …).
* Pour ajouter ou modcouleurs_console.hifier un combattant ou un environnement, éditez ou créez un fichier `.txt` au même format.

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
Ce projet étant universitaire, aucune contribution extérieure n’est prévue.


## Auteur
- THOMAS Milo
- BOTNARI Alexandru
- KI-ZERBO William



