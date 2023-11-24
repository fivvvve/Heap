#include <stdio.h>
#include "heap.h"
#include <stdlib.h>
#include <time.h>

int maior(int *vet, int inicio, int fim) {
    if(fim == inicio) return vet[fim];

    int k = (inicio+fim)/2;
    int m1 = maior(vet, inicio, k);
    int m2 = maior(vet, k+1, fim);

    if(m1 > m2) return m1;
    else return m2;
}

int maior1(int *vet, int fim) {
    int maior = vet[0];
    for(int i=1; i<fim+1; i++) {
        if(vet[i] > maior) {
            maior = vet[i];
        }
    }

    return maior;
}

int main() {

    // heap *h;
    // int dados[10] = {1, 2, 3, 4, 5, 6, 7};
    // int n = 7;

    // h = cria_heap();
    
    // for(int i=0; i<n; i++) {
    //     heap_top(h, dados[i]);
    // }

    // for(int i=0; i<n; i++) {
    //     printf("%d\n", heap_down(h));
    // }

    // free(h);

    int n = 2000000;
    int vet[n];
    clock_t inicio, fim;
    int m, m1;
    srand(time(NULL));

    for(int i=0; i<n; i++) {
        vet[i] = rand() % 10000000;
    }

    inicio = clock();
    m = maior(vet, 0, n-1);
    fim = clock();
    printf("Maior: %d Tempo: %.8f\n", m, (float)(fim-inicio)/CLOCKS_PER_SEC);
    inicio = clock();
    m1 = maior1(vet, n-1);
    fim = clock();
    printf("Maior: %d Tempo: %.8f\n", m1, (float)(fim-inicio)/CLOCKS_PER_SEC);

    return 0;
}