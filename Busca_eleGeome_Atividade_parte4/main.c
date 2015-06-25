/***********************************************************

    Nome: Bárbara Coelho.
    IFSC
    Engenharia Eletrônica
    Programação de Computadores II

                    Atividade Busca

***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura Circulo
typedef struct circulo Circulo;
struct circulo
{
    int cx;
    int cy;
};

/* Prototipos de funções */
void cria_vetor (Circulo* vet, int N);
int comp_circ_centro (const void * p1, const void * p2);
int busca_linear(int n, Circulo* vet, Circulo elem);

int main()
{
    clock_t start1, end1;
    clock_t start2, end2;
    clock_t start3, end3;
    double total1, total2, total3;

    int BL1, BL2, BL3;

    // Criação dos Vetores 50, 500 e 5000

    Circulo VetorBusca1[50];
    cria_vetor(VetorBusca1,50);
    Circulo VetorBusca2[500];
    cria_vetor(VetorBusca2,500);
    Circulo VetorBusca3[5000];
    cria_vetor(VetorBusca3,5000);

    //Ponteiros usados como retorno para a função bsearch

    Circulo *rbusca1;   // usado no vetor 50
    Circulo *rbusca2;   // usado no vetor 500
    Circulo *rbusca3;   // usado no vetor 5000

    //Valores usados para buscar nos vetores

    Circulo busca1 = {30,30};       // usado para buscar no vetor 50
    Circulo busca2 = {300,300};     // usado para buscar no vetor 500
    Circulo busca3 = {3000,3000};   // usado para buscar no vetor 5000

    /////////////////Ordenação dos circulos/////////////////

    qsort(VetorBusca1,50,sizeof(Circulo),comp_circ_centro);
    qsort(VetorBusca2,500,sizeof(Circulo),comp_circ_centro);
    qsort(VetorBusca3,5000,sizeof(Circulo),comp_circ_centro);

    ////////////////////Busca Circulo 1////////////////////

    printf("Busca para o vetor 50\n\n");

    start1 = clock();
    rbusca1 = bsearch(&busca1,VetorBusca1,50,sizeof(Circulo),comp_circ_centro);
    end1 = clock();
    total1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
    if (rbusca1 == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", rbusca1-VetorBusca1);
    printf("Tempo total1 bsearch: %g ns.\n",total1*1000000);

   /////////////////////Busca Linear 1/////////////////////

    start1 = clock();
    BL1 = busca_linear(50,VetorBusca1,busca1);
    end1 = clock();
    total1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
    if (BL1 == -1)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", BL1);
    printf("Tempo total1 Linear: %g ns.\n",total1*1000000);

    ////////////////////Busca Circulo 2////////////////////

    printf("\nBusca para o vetor 500\n\n");

    start2 = clock();
    rbusca2 = bsearch(&busca2,VetorBusca2,500,sizeof(Circulo),comp_circ_centro);
    end2 = clock();
    total2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    if (rbusca2 == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", rbusca2-VetorBusca2);
    printf("Tempo total2 bsearch: %g ns.\n",total2*1000000);

   /////////////////////Busca Linear 2/////////////////////

    start2 = clock();
    BL2 = busca_linear(500,VetorBusca2,busca2);
    end2 = clock();
    total2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    if (BL2 == -1)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", BL2);
    printf("Tempo total2 Linear: %g ns.\n",total2*1000000);

    ////////////////////Busca Circulo 2////////////////////

    printf("\nBusca para o vetor 5000\n\n");

    start3 = clock();
    rbusca3 = bsearch(&busca3,VetorBusca3,5000,sizeof(Circulo),comp_circ_centro);
    end3 = clock();
    total3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
    if (rbusca3 == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", rbusca3-VetorBusca3);
    printf("Tempo total3 bsearch: %g ns.\n",total3*1000000);

    /////////////////////Busca Linear 3/////////////////////

    start3 = clock();
    BL3 = busca_linear(5000,VetorBusca3,busca3);
    end3 = clock();
    total3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
    if (BL3 == -1)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", BL3);
    printf("Tempo total3 Linear: %g ns.\n",total3*1000000);

    return 0;
}

/* Função usada para criar vetores de tamanho N */
void cria_vetor (Circulo* vet, int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        vet[i].cx = i;
        vet[i].cy = i;
    }
}

/* Função que compara os valores do vetor para saber qual é maior */
int comp_circ_centro (const void * p1, const void * p2)
{
    const Circulo *f1 = p1;
    const Circulo *f2 = p2;
    if      (f1->cy < f2->cy) return -1;
    else if (f1->cy > f2->cy) return 1;
    else if (f1->cx < f2->cx) return -1;
    else if (f1->cx > f2->cx) return 1;
    else return 0;
}

/* Função de busca linear */
int busca_linear(int n, Circulo* vet, Circulo elem)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (elem.cy == vet[i].cy){
            if (elem.cx == vet[i].cx) return i; /* elemento encontrado */
        }
    }/* percorreu todo o vetor e não encontrou elemento */
    return -1;
}
