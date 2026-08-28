#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void) {
    char linha[10500];
    // Começa a ler até o fim da linha
    while (scanf(" %[^\n]", linha) == 1) {
        char validas[1000][10000];
        int soma = 0;
        int total_validas = 0;
        char palavra[10000];
        int letra = 0;
        // Passa caractere por caractere
        for (int i = 0; ; i ++) {
            // Se não for fim de linha nem espaço, é armazenado
            if (linha[i] != ' ' && linha[i] != '\0') {
                palavra[letra] = linha[i];
                letra ++;
            }
            else if (letra > 0) {
                // Se é espaço vazio fecha a string da palavra anterior
                palavra[letra] = '\0';
                char palavra_modificada[10000];
                int indice_modificada = 0;
                int atual = 0;
                int tem_numero = 0;
                // Filtra os números e símbolos, enquanto soma os caracteres numéricos
                for (int j = 0; palavra[j] != '\0'; j ++) {
                    if (isdigit(palavra[j])) {
                        atual = atual * 10 + (palavra[j] - '0');
                        tem_numero = 1;
                    }
                    else {
                        // Se era um número lido vai somar no total
                        if (tem_numero) {
                            soma += atual;
                            atual = 0;
                            tem_numero = 0;
                        }
                        // Se era uma letra é adicionado a uma "cópia" da palavra
                        if (isalpha(palavra[j])) {
                            palavra_modificada[indice_modificada ++] = palavra[j];
                        }
                    }
                }
                // Se o número tá no fim
                if (tem_numero) {
                    soma += atual;
                }
                palavra_modificada[indice_modificada] = '\0';
                if (indice_modificada > 0) {
                    int tamanho = indice_modificada;
                    char modificado[10000];
                    modificado[0] = '\0';
                    // Confere se é vogal
                    if (strchr("aeiouAEIOU", palavra_modificada[0]) != NULL) {
                        strcpy(modificado, palavra_modificada);
                    }
                    // Se consoante muda a primeira letra pro fim
                    else {
                        strcpy(modificado, palavra_modificada + 1);
                        char primeira[2] = {palavra_modificada[0], '\0'};
                        strcat(modificado, primeira);
                    }
                    strcat(modificado, "ma");
                    // Adiciona a repetido do tamanho de vezes
                    int tamanho_atual = strlen(modificado);
                    for (int k = 0; k < tamanho; k ++) {
                        modificado[tamanho_atual ++] = 'a';
                    }
                    modificado[tamanho_atual] = '\0';
                    // Salva nas palavras modificadas
                    strcpy(validas[total_validas ++], modificado);
                }
                // Reseta pra ler a próxima
                letra = 0;
            }
            // Se fim encerra o loop
            if (linha[i] == '\0') {
                break;
            }
        }
        if (soma == 1) {
            printf("1 goat says:");
        }
        else {
            printf("%d goats say:", soma);
        }
        for (int m = 0; m < total_validas; m ++) {
            printf(" %s", validas[m]);
        }
        printf("\n");
    }
    return 0;
}