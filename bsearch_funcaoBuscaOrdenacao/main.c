#include <stdio.h>
#include <stdlib.h>

/* função de comparação de inteiros */
int comp_int (const void* p1, const void* p2)
{
    /* converte ponteiros genéricos para ponteiros de int */
    int *i1 = (int*)p1;
    int *i2 = (int*)p2;
    /* dados os ponteiros de int, faz a comparação */
    if (*i1 < *i2) return -1;
    else if (*i1 > *i2) return 1;
    else return 0;
}

/* programa que faz a busca em um vetor */
int main (void)
{
    int v[8] = {12,25,33,37,48,57,86,92};
    int e = 57; /* informação que se deseja buscar */
    int* p;
    p = (int*)bsearch(&e,v,8,sizeof(int),comp_int);
    if (p == NULL)
        printf("Elemento nao encontrado.\n");
    else
        printf("Elemento encontrado no indice: %d\n", p-v);
    return 0;
}
