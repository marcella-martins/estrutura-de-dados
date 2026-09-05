#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void) {
    int n;
    // Tem que considerar quando não há entrada
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    int S[n];
    for (int i = 0; i < n; i ++) {
        scanf("%d", &S[i]);
    }
    // Usa o calloc para criar um ponteiro para um espaço preenchido de 0
    int m = ceil(sqrt(n));
    int *M = calloc(m, sizeof(int));
    // Preenche os espaços com a soma dos respectivos
    for (int k = 0; k < n; k ++) {
        M[k/m] += S[k];
    }

    char letra;
    int primeiro;
    int segundo;
    while (scanf(" %c %d %d", &letra, &primeiro, &segundo) == 3) {
        if (letra == 's') {
            int soma = 0;
            int f = primeiro;
            int second = segundo;
            int inicio = f / m;
            int fim = second / m;
            if (inicio == fim) {
                // Se estão no mesmo bloco, só vou somar tudo
                for (int a = f; a <= second; a ++) {
                    soma += S[a];
                }
            }
            else {
                // Calcula onde termina o primeiro bloco
                int fim_inicial = (inicio + 1) * m;
                // Vai calcular dentro do mesmo bloco as partes que quer "pegar"
                for (int a = f; a < fim_inicial; a ++) {
                    soma += S[a];
                }
                // Quando têm blocos inteiros, soma eles a partir dos valores salvos
                for (int b = inicio + 1; b < fim; b ++) {
                    soma += M[b];
                }
                // Calcula onde começa o último bloco
                int inicio_final = fim * m;
                // Vai calcular dentro do mesmo bloco a parte que quer
                for (int c = inicio_final; c <= second; c ++) {
                    soma += S[c];
                }
            }
            printf("%d\n", soma);
        }
        if (letra == 'a') {
            // Descobre o bloco onde o índice está
            int bloco = primeiro / m;
            // Atualiza a soma daquele bloco, que foi modificada com a mudança
            M[bloco] = M[bloco] - S[primeiro] + segundo;
            S[primeiro] = segundo;
        }
    }
    free(M);
    return 0;
}