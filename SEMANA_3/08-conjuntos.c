#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No *prox;
} No;
No *vazia() {
    No *inicio = malloc(sizeof(No));
    inicio->prox = NULL;
    return inicio;
}
void liberar(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}
void inserir(No *lista, int elemento) {
    No *anterior = lista;
    while (anterior->prox!= NULL && anterior->prox->numero < elemento) {
        anterior = anterior->prox;
    }
    if (anterior->prox != NULL && anterior->prox->numero == elemento) {
        return;
    }
    No *novo = malloc(sizeof(No));
    novo->numero = elemento;
    novo->prox = anterior->prox;
    anterior->prox = novo;
}
void apagar(No *lista, int elemento) {
    No *anterior = lista;
    while (anterior->prox != NULL && anterior->prox->numero < elemento) {
        anterior = anterior->prox;
    }
    if(anterior->prox != NULL && anterior->prox->numero == elemento) {
        No *apaga = anterior->prox;
        anterior->prox = apaga->prox;
        free(apaga);
    }
}
int incluso(No *lista, int elemento) {
    No *atual = lista->prox;
    while (atual != NULL && atual->numero < elemento) {
        atual = atual->prox;
    }
    return atual != NULL && atual->numero == elemento;
}
void imprimir(No *lista, int conjunto) {
    printf("C%d = {", conjunto);
    No *atual = lista->prox;
    while (atual != NULL) {
        printf("%d", atual->numero);
        if (atual->prox != NULL) {
            printf(", ");
        }
        atual = atual->prox;
    }
    printf("}\n");
}
No *resultado(No *primeiro, No *segundo, char conta) {
    No *resposta = vazia();
    No *atual;
    for (atual = primeiro->prox; atual != NULL; atual = atual->prox) {
        if (conta == 'u') {
            inserir(resposta, atual->numero);
        }
        else if (conta == 'n' && incluso(segundo, atual->numero)) {
            inserir(resposta, atual->numero);
        }
        else if (conta == 'm' && !incluso(segundo, atual->numero)) {
            inserir(resposta, atual->numero);
        }
    }
    if (conta == 'u') {
        for (atual = segundo->prox; atual != NULL; atual = atual->prox) {
            inserir(resposta, atual->numero);
        }
    }
    return resposta;
}
int main() {
    No *conjuntos[128];
    char comando;
    int i, j, k, t, x, n;
    for (n = 0; n < 128; n ++) {
        conjuntos[n] = NULL;
    }
    while (scanf(" %c", &comando) == 1 && comando != 't') {
        if (comando == 'c') {
            scanf("%d", &i);
            liberar(conjuntos[i]);
            conjuntos[i] = vazia();
        }
        else if (comando == 'i') {
            scanf("%d %d", &j, &t);
            for (n = 0; n < t; n ++) {
                scanf("%d", &x);
                inserir(conjuntos[j], x);
            }
        }
        else if (comando == 'r') {
            scanf("%d %d", &j, &t);
            for (n = 0; n < t; n ++) {
                scanf("%d", &x);
                apagar(conjuntos[j], x);
            }
        }
        else if (comando == 'u' || comando == 'n' || comando == 'm') {
            scanf("%d %d %d", &i, &j, &k);
            No *novo = resultado(conjuntos[j], conjuntos[k], comando);
            liberar(conjuntos[i]);
            conjuntos[i] = novo;
        }
        else if (comando == 'e') {
            scanf("%d %d", &i, &x);
            if (incluso(conjuntos[i], x)) {
                printf("%d esta em C%d\n", x, i);
            }
            else {
                printf("%d nao esta em C%d\n", x, i);
            }
        }
        else if (comando == 'p') {
            scanf("%d", &i);
            imprimir(conjuntos[i], i);
        }
    }
    for (n = 0; n < 128; n ++) {
        liberar(conjuntos[n]);
    }
    return 0;
}