/*Autor : Cumpanasu Stefan - Adrian
  Grupa : CR1.1B
  Scopul problemei: Maximizarea valorii homarilor fara a depasi
  capacitatea plasei
  Mod de rezolvare: Problema rucsacului 0/1
*/



#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Fisier-Header-Homari.h"


int main()
{

    struct homar *homari;
    int numar_homari;
    int capacitate_plasa;

    printf("Precizeaza capacitatea plasei pescarului: ");
    scanf("%d",&capacitate_plasa);

    printf("Precizeaza numarul homarilor: ");
    scanf("%d",&numar_homari);

    homari = malloc(numar_homari * sizeof(struct homar));
    generare_homari(homari, numar_homari);

    printf("\n### Homari generati ###\n");
    printf("##########################");
    afisare_homari(homari,numar_homari);

    calculare_valoare_maxima_si_optima(homari,numar_homari,capacitate_plasa);

    free(homari);

    return 0;
}
