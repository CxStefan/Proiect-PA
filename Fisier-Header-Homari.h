
#ifndef PROIECT_PA_PESCAR_CU_HOMARI_CUMPANASU_STEFAN_ADRIAN
#define PROIECT_PA_PESCAR_CU_HOMARI_CUMPANASU_STEFAN_ADRIAN

struct homar    ///Definirea structurii care caracterizeaza un homar
{              ///in acest caz (id-ul care reprezinta numarul homarului , greutatea si valoarea lui)
    int id;
    int greutate;
    int valoare;
};

struct matrice_homari   ///Definirea unei matrici sub forma de struct pentru a se folosi ulterior in aflarea valorii maxime a homarilor
{
    int numar_randuri;
    int numar_coloane;
    int *matrice;
};

void generare_homari(struct homar *homari, int numar_homari);
void afisare_homari(struct homar *homari, int numar_homari);
void calculare_valoare_maxima_si_optima(struct homar *homari, int numar_homari, int capacitate_plasa);
int afla_valoare_matrice(struct matrice_homari matrice, int rand_indice, int coloana_indice);
int maxim_valori(int numar_1, int numar_2);

#endif
