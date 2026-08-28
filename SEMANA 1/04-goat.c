#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
    char *linha = (char *)malloc(1000000 * sizeof(char));
    char *palavra = (char *)malloc(1000000 * sizeof(char));
    char *palavra_modificada = (char *)malloc(1000000 * sizeof(char));
    if (!linha || !palavra || !palavra_modificada) {
        return 1;
    }
    // Começa a ler até o fim da linha
    while (scanf(" %[^\n]", linha) == 1) {
        int soma = 0;
        int atual = 0;
        int tem_numero = 0;
        // Calcula a soma total dos números da linha
        for (int i = 0; linha[i] != '\0'; i ++) {
            if (isdigit(linha[i])) {
                atual = atual * 10 + (linha[i] - '0');
                tem_numero = 1;
            } else {
                if (tem_numero) {
                    soma += atual;
                    atual = 0;
                    tem_numero = 0;
                }
            }
        }
        if (tem_numero) {
            soma += atual;
        }
        // Imprime o início certo
        if (soma == 1) {
            printf("1 goat says:");
        } else {
            printf("%d goats say:", soma);
        }
        // Processa e imprime cada palavra
        int letra = 0;
        // Passa caractere por caractere da linha
        for (int i = 0; ; i ++) {
            // Se não for fim de linha nem espaço é armazenado
            if (linha[i] != ' ' && linha[i] != '\0') {
                palavra[letra] = linha[i];
                letra ++;
            }
            else if (letra > 0) {
                // Se é espaço vazio fecha a string da anterior
                palavra[letra] = '\0';
                int indice_modificada = 0;
                // Mantém apenas as letras da palavra
                for (int j = 0; palavra[j] != '\0'; j ++) {
                    if (isalpha(palavra[j])) {
                        palavra_modificada[indice_modificada ++] = palavra[j];
                    }
                }
                palavra_modificada[indice_modificada] = '\0';
                if (indice_modificada > 0) {
                    int tamanho = indice_modificada;
                    printf(" ");
                    // Confere se começa com vogal
                    if (strchr("aeiouAEIOU", palavra_modificada[0]) != NULL) {
                        printf("%s", palavra_modificada);
                    }
                    // Imprime a palavra com a letra no fim
                    else {
                        printf("%s%c", palavra_modificada + 1, palavra_modificada[0]);
                    }
                    // Imprime o sufixo "ma"
                    printf("ma");
                    // Imprime 'a' repetido com base no tamanho original
                    for (int k = 0; k < tamanho; k ++) {
                        printf("a");
                    }
                }
                // Reseta pra ler a próxima palavra
                letra = 0;
            }
            // Se for o fim da linha encerra o loop
            if (linha[i] == '\0') {
                break;
            }
        }
        printf("\n");
    }
    free(linha);
    free(palavra);
    free(palavra_modificada);
    return 0;
}