# Projet C++ - Algorithmes et Matrices

Ce projet regroupe deux exercices d'implémentation en C++ :
1. **Exercice 1 (`ex1`)** : Implémentation de différents algorithmes de recherche (Linéaire, Binaire, par Saut).
2. **Exercice 2 (`ex2`)** : Création d'une classe de manipulation de matrices numériques et calculs associés.

---

## 📂 Structure du Projet

Voici l'arborescence du projet[cite: 2] (incluant les Makefiles par exercice) :

```text
.
├── README.md
└── src/
    ├── ex1/
    │   ├── Makefile                 # Fichier de compilation pour l'exercice 1
    │   ├── main.cpp                 # Point d'entrée de l'exercice 1
    │   ├── SearchingAlgorithm.h/.cpp # Classe de base pour les algorithmes
    │   ├── LinearSearch.h/.cpp       # Algorithme de recherche linéaire
    │   ├── BinarySearch.h/.cpp       # Algorithme de recherche dichotomique
    │   ├── JumpSearch.h/.cpp         # Algorithme de recherche par saut
    │   └── exec.png                  # Capture d'écran d'exécution
    │
    └── ex2/
        ├── Makefile                 # Fichier de compilation pour l'exercice 2
        ├── main.cpp                 # Point d'entrée de l'exercice 2
        ├── Matrix.hpp               # Déclaration et implémentation de la classe Matrix
        ├── main                     # Exécutable généré
        └── exec.png                 # Capture d'écran d'exécution 