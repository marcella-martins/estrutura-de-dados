#include <stdio.h>
#include <stdlib.h>

// Representa o vetor coordenadas falado
typedef struct {
    int linha;
    int coluna;
    int valor;
} Elemento;
// Função de comparação pro qsort
static int comparar(const void *a, const void *b) {
    const Elemento *ea = (const Elemento *) a;
    const Elemento *eb = (const Elemento *) b;
    if (ea->linha != eb->linha) {
        return ea->linha - eb->linha;
    }
    return ea->coluna - eb->coluna;
}
int main(void) {
    // Faz a leitura inicial e aloca espaço para n Elementos
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }
    Elemento *vc = malloc((size_t) n * sizeof(Elemento));
    // Guarda a maior linha, pra ver o tamanho da matriz
    int maximo_linha = 0;
    for (int k = 0; k < n; k ++) {
        scanf("%d %d %d", &vc[k].linha, &vc[k].coluna, &vc[k].valor);
        if (vc[k].linha > maximo_linha) {
            maximo_linha = vc[k].linha;
        }
    }
    // Ordena os Elementos de vc por linha, depois coluna
    qsort(vc, (size_t) n, sizeof(Elemento), comparar);
    // Aloca o segundo vetor, com as posições zeradas
    int *ia = calloc((size_t) (maximo_linha + 2), sizeof(int));
    int posicao = 0;
    // Conta por linha quantos elementos tem antes
    for (int li = 0; li < maximo_linha + 1; li ++) {
        ia[li] = posicao;
        while (posicao < n && vc[posicao].linha == li) {
            posicao ++;
        }
    }
    ia[maximo_linha + 1] = n;
    int l, c;
    while (scanf("%d %d", &l, &c) == 2) {
        // Se for o par (-1,-1) a consulta acaba
        if (l == -1 && c == -1) {
            break;
        }
        int v = 0;
        // Já confere se a linha existe dentro do intervalo
        if (l >= 0 && l < maximo_linha + 1) {
            int inicio = ia[l];
            int fim = ia[l + 1];
            for (int p = inicio; p < fim; p ++) {
                if (vc[p].coluna == c) {
                    v = vc[p].valor;
                    break;
                }
            }
        }
        printf("(%d,%d) = %d\n", l, c, v);
    }
    free(vc);
    free(ia);
    return 0;
}