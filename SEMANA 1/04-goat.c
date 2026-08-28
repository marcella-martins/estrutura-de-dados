#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char linha[10500];
    // Começa a ler até o fim da linha
    while (scanf(" %[^\n]", linha) == 1) {
        int soma = 0;
        int atual = 0;
        int tem_numero = 0;
        // Calcula a soma total dos números da linha
        for (int i = 0; linha[i] != '\0'; i++) {
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
        char palavra[2000];
        int letra = 0;
        // Passa caractere por caractere da linha
        for (int i = 0; ; i++) {
            // Se não for fim de linha nem espaço é armazenado
            if (linha[i] != ' ' && linha[i] != '\0') {
                palavra[letra] = linha[i];
                letra++;
            }
            else if (letra > 0) {
                // Se é espaço vazio fecha a string da anterior
                palavra[letra] = '\0';
                char palavra_modificada[2000];
                int indice_modificada = 0;
                // Mantém apenas as letras da palavra
                for (int j = 0; palavra[j] != '\0'; j++) {
                    if (isalpha(palavra[j])) {
                        palavra_modificada[indice_modificada++] = palavra[j];
                    }
                }
                palavra_modificada[indice_modificada] = '\0';
                if (indice_modificada > 0) {
                    int tamanho = indice_modificada;
                    char modificado[4000];
                    modificado[0] = '\0';
                    // Confere se começa com vogal
                    if (strchr("aeiouAEIOU", palavra_modificada[0]) != NULL) {
                        strcpy(modificado, palavra_modificada);
                    }
                    // Se consoante move a primeira letra para o fim
                    else {
                        strcpy(modificado, palavra_modificada + 1);
                        char primeira[2] = {palavra_modificada[0], '\0'};
                        strcat(modificado, primeira);
                    }
                    // Adiciona o sufixo "ma"
                    strcat(modificado, "ma");
                    // Adiciona 'a' repetido com base no tamanho original
                    int tamanho_atual = strlen(modificado);
                    for (int k = 0; k < tamanho; k++) {
                        modificado[tamanho_atual++] = 'a';
                    }
                    modificado[tamanho_atual] = '\0';
                    // Imprime a palavra modificada
                    printf(" %s", modificado);
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
    return 0;
}