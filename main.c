#include "liste.h"

int main (void)
{
    //déclaration des variables
        char choix;
        Point pt;
        Liste *liste;
        int pos, k;

    //initialisation des variables
        if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
            return -1;
        choix = 'o';
        initialisation (liste);

    //temps que l'utilisateur ne quitte pas
        while (choix != 7){
            //clear screen
                system("@cls||clear");

            //menu et choix de l'utilisateur
                choix = menu (liste, &k);

            //action en fonction du choix de l'utilisateur
                switch (choix){
                    case 1:
                        //demande d'entrer un élément
                          printf ("Entrez un element : ");
                          scanf ("%d",&pt.x);
                          scanf ("%d",&pt.y);
                          scanf ("%d",&pt.z);
                          getchar ();

                        //si la liste est vide alors on l'initialisa avec le point, sinon on ajoute le point au début
                          if (liste->taille == 0)
                            insListeVide(liste,&pt);
                          else
                            insDebutListe (liste,&pt);

                        //affichage de la liste
                          printf ("%d elements:deb=%d - %d - %d ,fin=%d - %d - %d\n", liste->taille,
                                  liste->debut->valeur.x,liste->debut->valeur.y,liste->debut->valeur.z,
                                  liste->fin->valeur.x,liste->fin->valeur.y,liste->fin->valeur.z);
                          affiche (liste);
                        break;
                    case 2:
                        //demande d'entrer un élément
                          printf ("Entrez un element : ");
                          scanf ("%d",&pt.x);
                          scanf ("%d",&pt.y);
                          scanf ("%d",&pt.z);
                          getchar ();

                        //Insertion
                            insFinListe (liste, liste->fin, &pt);

                        //affichage de la liste
                          printf ("%d elements:deb=%d - %d - %d ,fin=%d - %d - %d\n", liste->taille,
                                  liste->debut->valeur.x,liste->debut->valeur.y,liste->debut->valeur.z,
                                  liste->fin->valeur.x,liste->fin->valeur.y,liste->fin->valeur.z);
                          affiche (liste);
                        break;
                    case 3:
                        //demande d'entrer un élément
                          printf ("Entrez un element : ");
                          scanf ("%d",&pt.x);
                          scanf ("%d",&pt.y);
                          scanf ("%d",&pt.z);
                          getchar ();

                        //demande de position
                          do{
                              printf ("Entrez la position : ");
                              scanf ("%d", &pos);
                          }
                          while (pos < 1 || pos > liste->taille);
                          getchar ();

                        //si érreur
                          if (liste->taille == 1 || pos == liste->taille){
                              k = 1;
                              printf("-----------------------------------------------\n");
                              printf("Insertion echouée.Utilisez le menu {1|2}  \n");
                              printf("-----------------------------------------------\n");
                              break;
                          }

                        //Insertion
                          insListe (liste,&pt, pos);

                        //affichage de la liste
                          printf ("%d elements:deb=%d - %d - %d ,fin=%d - %d - %d\n", liste->taille,
                                  liste->debut->valeur.x,liste->debut->valeur.y,liste->debut->valeur.z,
                                  liste->fin->valeur.x,liste->fin->valeur.y,liste->fin->valeur.z);
                          affiche (liste);
                        break;
                    case 4:
                        //suppression
                          suppDebut (liste);
                        //affichage de la liste
                          if (liste->taille != 0)
                            printf ("%d elements:deb=%d - %d - %d ,fin=%d - %d - %d\n", liste->taille,
                                  liste->debut->valeur.x,liste->debut->valeur.y,liste->debut->valeur.z,
                                  liste->fin->valeur.x,liste->fin->valeur.y,liste->fin->valeur.z);
                          else
                            printf ("liste vide\n");
                          affiche (liste);
                      break;
                    case 5:
                        //demande de position
                          do{
                              printf ("Entrez la position : ");
                              scanf ("%d", &pos);
                          }
                          while (pos < 1 || pos > liste->taille);
                          getchar ();

                        //suppression
                          suppDansListe (liste, pos);

                        //affichage de la liste
                          if (liste->taille != 0)
                            printf ("%d elements:deb=%d - %d - %d ,fin=%d - %d - %d\n", liste->taille,
                                  liste->debut->valeur.x,liste->debut->valeur.y,liste->debut->valeur.z,
                                  liste->fin->valeur.x,liste->fin->valeur.y,liste->fin->valeur.z);
                          else
                            printf ("liste vide\n");
                          affiche (liste);
                        break;
                    case 6:
                        //destruction de la liste
                          detruire (liste);
                          printf ("la liste a ete detruite : %d elements\n", liste->taille);
                        break;
                  }

          system("pause");

        }
    return 0;
}
