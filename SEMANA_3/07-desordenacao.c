#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_CADEIA 51
#define MAXIMO_K 100


typedef struct {
    char cadeia[MAXIMO_CADEIA];
    int inversoes;
    int indice_original;
} Cadeia;
// Converte uma letra  para número respeitando a ordem, e se n for retorna -1
int indice_letra(char letra) {
    switch(letra) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return -1;
    }
}
// Conta as inversões da cadeia da direita pra esquerda, contando quantas vezes cada já apareceu
int conta_inversoes(const char *cadeia) {
    int tamanho = (int) strlen(cadeia);
    int contagem_letra[4] = {0, 0, 0, 0};
    int total_inversoes = 0;
    int i, indice_atual, letra_menor;
    for (i = tamanho - 1; i >= 0; i --) {
        indice_atual = indice_letra(cadeia[i]);
        for (letra_menor = 0; letra_menor < indice_atual; letra_menor ++) {
            total_inversoes += contagem_letra[letra_menor];
        }
        contagem_letra[indice_atual] ++;
    }
    return total_inversoes;
}
// Comparação com número de inversões, e se igual, considera o indice
int compara_cadeia(const void *a, const void *b) {
    const Cadeia *cadeiaA = (const Cadeia *) a;
    const Cadeia *cadeiaB = (const Cadeia *) b;
    if (cadeiaA->inversoes != cadeiaB->inversoes) {
        return cadeiaA->inversoes - cadeiaB->inversoes;
    }
    return cadeiaA->indice_original - cadeiaB->indice_original;
}
// lê um conjunto
int ler_conjunto(Cadeia vetorCadeias[]) {
    int tamanho_cadeia, quantidade_cadeias;
    int i;
    scanf("%d %d", &tamanho_cadeia, &quantidade_cadeias);
    for (i = 0; i < quantidade_cadeias; i ++) {
        scanf("%s", vetorCadeias[i].cadeia);
        vetorCadeias[i].inversoes = conta_inversoes(vetorCadeias[i].cadeia);
        vetorCadeias[i].indice_original = i;
    }
    return quantidade_cadeias;
}
// Imprime as cadeias já ordenadas
void imprime(Cadeia vetorCadeias[], int quantidade_cadeias) {
    int i;
    for (i = 0; i < quantidade_cadeias; i ++) {
        printf("%s\n", vetorCadeias[i].cadeia);
    }
    printf("\n");
}
int main(void) {
    int quantidade_conjuntos;
    int c;
    scanf("%d", &quantidade_conjuntos);
    for (c = 0; c < quantidade_conjuntos; c ++) {
        Cadeia cadeia[MAXIMO_K];
        int quantidade_cadeias;
        quantidade_cadeias = ler_conjunto(cadeia);
        qsort(cadeia, quantidade_cadeias, sizeof(Cadeia), compara_cadeia);
        imprime(cadeia, quantidade_cadeias);
    }
    return 0;
}