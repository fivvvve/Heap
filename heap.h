typedef struct heap heap;

heap* cria_heap();

int heap_top(heap *h, int dado);

int heap_down(heap *h);

void imprime_heap(heap *h);