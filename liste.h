#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//definition du type point
    typedef struct Point{

        int x;
        int y;
        int z;

    }Point;

//définition du type Maillon
    typedef struct Maillon{

        Point valeur;
        struct Maillon *suivant;

    }Maillon;

//définition du type Liste
    typedef struct Liste
    {

      Maillon *debut;
      Maillon *fin;
      int taille;

    }Liste;

//prototypes
    void initialisation (Liste * liste);
    void affiche(Liste * liste);
    int insListeVide(Liste * ListePoint,Point * pt);
    int insDebutListe (Liste * liste, Point *donnee);
    int insFinListe (Liste * liste, Maillon * courant, Point *donnee);
    int insListe (Liste * liste, Point *donnee, int pos);
    int suppDebut (Liste * liste);
    int suppDansListe (Liste * liste, int pos);
    void detruire (Liste * liste);
    int menu (Liste *liste,int *k);

#endif

