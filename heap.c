#include <stdio.h>
#include "heap.h"
#include <stdlib.h>

struct heap {
    int dados[50];
    int n;
};


heap* cria_heap() {
    heap *h = (heap*) malloc(sizeof(heap));
    h->n = 0;
    return h;    
}

int heap_top(heap *h, int dado) {
    if(h == NULL) return -1;

    int pai = (h->n-1)/2;
    int pos = h->n, aux;

    h->dados[pos] = dado;
    h->n++;

    while(pai > 0 && dado > h->dados[pai]) {
        aux = h->dados[pai];
        h->dados[pai] = dado;
        h->dados[pos] = aux;

        pos = pai;
        pai = (pai-1)/2;
    }

    if(dado > h->dados[pai]) {
        aux = h->dados[pai];
        h->dados[pai] = dado;
        h->dados[pos] = aux;
    }

    return 0;
}

int heap_down(heap *h) {
    if(h == NULL) return -1515;

    int retorno = h->dados[0];
    int pos = 0, aux;

    h->dados[0] = h->dados[h->n-1];
    h->n--;

    while(2*pos+1 < h->n) {

        if(2*pos+2 >= h->n) {

            if(h->dados[pos] < h->dados[2*pos+1]) {
                aux = h->dados[pos];
                h->dados[pos] = h->dados[2*pos+1];
                h->dados[2*pos+1] = aux;
                pos = 2*pos+1;
            } else break;

        } else {

            if(h->dados[pos] > h->dados[2*pos+1] && h->dados[pos] > h->dados[2*pos+2]) break;

            if(h->dados[2*pos+1] >= h->dados[2*pos+2]) {
                aux = h->dados[pos];
                h->dados[pos] = h->dados[2*pos+1];
                h->dados[2*pos+1] = aux;
                pos = 2*pos+1;
            } else {
                aux = h->dados[pos];
                h->dados[pos] = h->dados[2*pos+2];
                h->dados[2*pos+2] = aux;
                pos = 2*pos+2;
            }

        }

    }

    return retorno;
}

void imprime_heap(heap *h) {
    if(h == NULL) return;

    if(h->n == 0) printf("Heap vazia");
    else {
        for(int i=0; i<h->n; i++) {
                printf("%d ", h->dados[i]);
        }
    }
    
    printf("\n\n");
}