# Vectors Library

## Description

Un vecteur en C est une structure de données dynamique similaire à un tableau, mais avec la capacité de changer de taille automatiquement. Cette bibliothèque permet de créer et de manipuler des vecteurs génériques, facilitant la gestion de collections d'éléments de taille variable. Elle inclut des fonctions pour initialiser, détruire, ajouter, supprimer et accéder aux éléments d'un vecteur.

## Arborescence du Dossier

```
vectors/
├── include/
│   └── vectors.h        # Fichier d'en-tête contenant les déclarations des structures et des fonctions
├── src/
│   ├── vector_create.c   # Implémentation de la fonction de création de vecteur
│   ├── vector_destroy.c  # Implémentation de la fonction de destruction de vecteur
│   ├── vector_get_at.c   # Implémentation de la fonction d'accès à un élément
│   ├── vector_getlength.c # Implémentation de la fonction de récupération de la longueur
│   ├── vector_npushback.c # Implémentation de la fonction d'ajout de plusieurs éléments
│   ├── vector_popback.c  # Implémentation de la fonction de suppression du dernier élément
│   ├── vector_pushback.c # Implémentation de la fonction d'ajout d'un élément
│   ├── vector_pushback_dynamic.c # Implémentation de la fonction d'ajout dynamique
│   └── auto_free.c       # Implémentation de la fonction de nettoyage automatique
├── tests/
│   └── test_vectors.c    # Tests unitaires pour la bibliothèque de vecteurs
├── Makefile              # Fichier Makefile pour la compilation et les tests
└── README.md            # Fichier README (ce fichier)
```

## Exemple en Action

Voici un exemple simple montrant comment utiliser la bibliothèque de vecteurs :

```c
#include "vectors.h"
#include <stdio.h>

int main(void) {
    vector_t *my_vector = vector_create(5, sizeof(int));
    int value = 42;

    vector_pushback(&my_vector, &value);
    vector_pushback(&my_vector, &value);
    vector_pushback(&my_vector, &value);

    for (size_t i = 0; i < vector_getlength(my_vector); i++) {
        printf("- [%ld] = %d\n", i, *(int *)vector_get_at(my_vector, i));
    }

    vector_destroy(my_vector);
    return 0;
}
```

## Explication des Règles du Makefile

Le Makefile fourni permet de compiler la bibliothèque, d'exécuter des tests unitaires et de générer de la documentation. Voici une explication des principales règles :

- `all` : Compile la bibliothèque statique `libvectors.a`.
- `clean` : Supprime les fichiers objets générés.
- `clean_test` : Supprime les fichiers de test générés.
- `fclean` : Supprime tous les fichiers générés, y compris la bibliothèque et les fichiers de test.
- `re` : Nettoie et recompile tout.
- `debug` : Compile avec des informations de débogage.
- `asan` : Compile avec AddressSanitizer pour détecter les erreurs de mémoire.
- `unit_tests` : Compile les tests unitaires.
- `tests_run` : Exécute les tests unitaires.

## Utilisation

Pour utiliser cette bibliothèque, suivez ces étapes :

1. Clonez le dépôt :
   ```sh
   git clone https://github.com/Chezrush/lib_vectors.git
   cd vectors
   ```

2. Compilez la bibliothèque :
   ```sh
   make
   ```

3. Exécutez les tests unitaires :
   ```sh
   make tests_run
   ```
<br>

Made with ❤️ by [Valentin Miné](https://github.com/chezrush) 
