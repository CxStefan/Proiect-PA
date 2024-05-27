#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Fisier-Header-Homari.h"
#define NUMAR_GENERARE_HOMARI 100 ///Am definit global aceasta variabila pentru a fi ulterior folosita sau schimbata
                                  /// pentru a da valori diferite homarilor generate aleatoriu %n (in acest caz %100)

///Functie care genereaza homarii la intamplare cu valorii aleatorii
void generare_homari(struct homar *homari, int numar_homari)
{
    int iterator;
    time_t t;

    srand((unsigned) time(&t));
    for(iterator = 0; iterator < numar_homari; iterator++)
    {
        homari[iterator].id = iterator + 1;
        homari[iterator].greutate = rand() % NUMAR_GENERARE_HOMARI + 1;
        homari[iterator].valoare = rand() % NUMAR_GENERARE_HOMARI + 1;
    }
}

///Functie care afiseaza trasaturile homarilor ( id, greutate , valoare)
void afisare_homari(struct homar *homari, int numar_homari)
{
    int iterator;

    printf("\n           Homari");
    for (iterator = 0; iterator < numar_homari ; iterator++)
    {
        printf("\n >Id: %d Greutate: %d Valoare: %d",homari[iterator].id,homari[iterator].greutate,homari[iterator].valoare);
    }
}


///Functie care determina la sfarsitul parcurgerii matricei valoarea cea mai optima
int afla_valoare_matrice(struct matrice_homari matrice , int rand_indice, int coloana_indice)
{
    int pozitie;
    pozitie = rand_indice*matrice.numar_coloane + coloana_indice;
    return *(matrice.matrice + pozitie);
}


///Functie care determina maximul dintre 2 valori
int maxim_valori(int numar_1, int numar_2){
    if (numar_1 > numar_2)
    {
        return numar_1;
    }
    else
    {
        return numar_2;
    }
}

///Functia principala care calculeaza valuare cea mai optima a valorii homarilor
void calculare_valoare_maxima_si_optima(struct homar *homari, int numar_homari, int capacitate_plasa)
{
    struct matrice_homari matrice;
    int valoare_plasa;
    int iterator_homari;
    int iterator_greutate;
    int valoare_curenta_fara_homarul_curent;
    int valoare_ramasa_fara_homarul_curent;
    int valoare_homar_curent_plus_valoare_ramasa;
    int maximul;
    int capacitate_ramasa_plasa;

    matrice.numar_randuri = numar_homari + 1;   ///Definirea matricei unde se calculeaza valoarea rucsacului
    matrice.numar_coloane = capacitate_plasa + 1;
    matrice.matrice = calloc((matrice.numar_coloane) * (matrice.numar_randuri), sizeof(int));

    ///Aici am folosit algoritmul rucsacului 0 1 pentru a calcula o valoare maxima acumulata pe homari
    for(iterator_homari=1;iterator_homari<matrice.numar_randuri;iterator_homari++)
    {
        for(iterator_greutate=1;iterator_greutate<matrice.numar_coloane;iterator_greutate++)
        {
            capacitate_ramasa_plasa=iterator_greutate-homari[iterator_homari-1].greutate;
            if(capacitate_ramasa_plasa<0)
            {
                ///Aici luam cazul in care greutatea homarului nu incape in plasa si o introducem pe cea anterioara
                matrice.matrice[iterator_homari*matrice.numar_coloane+iterator_greutate]=matrice.matrice[(iterator_homari-1)*matrice.numar_coloane+iterator_greutate];
            }
            else
            {
                ///In cazul asta greutatea corpului incape in plasa si calculam maximul dintre valoarea anterioara si valoarea curenta + valoarea care mai incape
                valoare_curenta_fara_homarul_curent=matrice.matrice[(iterator_homari-1)*matrice.numar_coloane+iterator_greutate];
                valoare_ramasa_fara_homarul_curent=matrice.matrice[(iterator_homari-1)*matrice.numar_coloane+capacitate_ramasa_plasa];
                valoare_homar_curent_plus_valoare_ramasa=valoare_ramasa_fara_homarul_curent+homari[iterator_homari-1].valoare;
                maximul=maxim_valori(valoare_homar_curent_plus_valoare_ramasa,valoare_curenta_fara_homarul_curent);
                matrice.matrice[iterator_homari*matrice.numar_coloane+iterator_greutate]=maximul;
            }
        }
    }

    ///Preluare valoare din matricea formata pentru a se afisa ulterior rezultatul.
    valoare_plasa = afla_valoare_matrice(matrice, matrice.numar_randuri - 1, matrice.numar_coloane- 1);
    free(matrice.matrice);

    printf("\n\n### Valoarea maxima a homarilor este: %d monede de aur###\n\n", valoare_plasa);
}
