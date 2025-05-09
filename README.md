# Projet Info2

Ce projet implémente en C une **simulation de combats mythologiques au tour par tour** pour 2 joueurs.  
Chaque joueur constitue son équipe en sélectionnant des combattants prédéfinis, chargés depuis des fichiers `data/*.txt`, puis s’affronte jusqu’à ce qu’une équipe soit complètement mise K.O.

---

## Contenu du projet

Le dépôt contient les fichiers suivants :

- **README.md** : documentation (ce fichier).
- **Makefile** : script de compilation et exécution.
- **Fichiers source en C** : code source en C :
  - `main.c` : point d'entrée 
  - `combat.c`, `combat.h` : logique de simulation de combat
  - `combattant.c`, `combattant.h` : chargement et gestion des entités
  - `equipe.c`, `equipe.h` : assemblage des équipes
  - `environnement.c`, `environnement.h` : effets et modificateurs globaux
  - `technique.c`, `technique.h` : stratégies de combat
  - `interface.c`, `interface.h` : affichage
  
- **Fichiers de données** (`.txt`) décrivant les divinités et environnements :
  - Artémis.txt, Atlas.txt, Déméter.txt, Héphaistos.txt, Ouranos.txt, Poséidon.txt, Téthys.txt, Zeus.txt, etc.
  - Aulis.txt, Keraunos.txt, Nysa.txt, Olympe.txt, Thalassa.txt, Orage.txt, etc.
---

## Installation & Compilation

Cloner le dépôt :
   ```bash
   git clone https://<votre-repo>/Projet_info2.git
   cd Projet_info2


Compiler le projet
make
La commande `make` compile le code et exécute immédiatement l’exécutable `./projet`.
```

## Utilisation
Au lancement, l’application demande successivement à chaque joueur de choisir ses combattants à partir de la liste affichée.  
Suivez les instructions à l’écran et entrez les indices correspondant aux divinités pour constituer vos équipes.

Lancer le programme :
./projet

## Fichiers de données
Les fichiers .txt du dossier data/ contiennent les caractéristiques des divinités et des environnements.

Exemple de fichier divinité :
Zeus 100 100 62 28 42 4 0 foudre jugement_écla```ir 115 0 "Frappe l’ennemi d’un éclair dévastateur" 0 5 0


### Exemple de fichier environnement

```txt
olympe terre foudre 1.2 0.8
```

## Configuration des données
* Les fichiers `.txt` contiennent les caractéristiques des divinités (ex. : `Zeus.txt`, `Artémis.txt`, …) et des environnements (`montagne.txt`, `orage.txt`, …).
* Pour ajouter un combattant ou un environnement, éditez ou créez un fichier `.txt` au même format.

## Structure du projet
```
Projet_info2/
├── src/                  # Code source et en-têtes
│   ├── main.c
│   ├── combat.c, combat.h
│   ├── combattant.c, combattant.h
│   ├── equipe.c, equipe.h
│   ├── environnement.c, environnement.h
│   ├── technique.c, technique.h
│   ├── interface.c, interface.h
├── data/                 # Fichiers de configuration (.txt)
│   ├── Artémis.txt
│   ├── Atlas.txt
│   ├── …
│   └── Orage.txt
├── Makefile              # Compilation et exécution
└── README.md             # Documentation du projet
```

## Auteur
- BOTNARI Alexandru
- KI-ZERBO William
- THOMAS Milo







