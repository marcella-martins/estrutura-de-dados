#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int indice;
    struct No* e;
    struct No* d;
} No;
// Cria o nó sem filho
No* criar(int indice) {
    No* novo = malloc(sizeof(No));
    novo->indice = indice;
    novo->e = NULL;
    novo->d = NULL;
    return novo;
}
// Dá free na árvore toda, filhos e depois o nó
void liberar(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberar(raiz->e);
    liberar(raiz->d);
    free(raiz);
}
// Constrói a árvore, guardando o mais a direita
No* arvore(int* a, int n) {
    No** pilha = malloc(n * sizeof(No*));
    int topo = 0;
    No* raiz;
    for (int i = 0; i < n; i ++) {
        No* novo = criar(i);
        No* ultimo = NULL;
        // Remove maiores que o elemento
        while (topo > 0 && a[pilha[topo - 1]->indice] > a[i]) {
            ultimo = pilha[topo - 1];
            topo --;
        }
        //O removido vira filho da esquerda do novo
        novo->e = ultimo;
        // O novo vira filho da direita de quem sobra
        if (topo > 0) {
            pilha[topo - 1]->d = novo;
        }
        pilha[topo] = novo;
        topo ++;
    }
    raiz = pilha[0];
    free(pilha);
    return raiz;
}
// Dá a saída por nível usando fila
void imprimir(No* raiz, int n) {
    No** fila = malloc(n * sizeof(No*));
    int i = 0, f = 0;
    fila[f ++] = raiz;
    while (i < f) {
        int tamanho = f - i;
        for (int k = 0; k < tamanho; k ++) {
            No* atual = fila[i ++];
            printf("%d ", atual->indice);
            if (atual->e != NULL) {
                fila[f ++] = atual->e;
            }
            if (atual->d != NULL) {
                fila[f ++] = atual->d;
            }
        }
        printf("\n");
    }
    free(fila);
}
int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int* a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        No* raiz = arvore(a, n);
        imprimir(raiz, n);
        printf("\n");
        liberar(raiz);
        free(a);
    }
    return 0;
}