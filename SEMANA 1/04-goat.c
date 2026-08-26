#include <stdio.h>
#include <string.h>


int main(void) {
    char linha[300000];
    while (scanf(" %[^\n]", linha) == 1) {
        char palavras[200000][100];
        int palavra = 0;
        int letra = 0;
        // Percorre toda a frase dividindo as palavras
        for (int i = 0; linha[i] != '\0'; i ++) {
            // Percorre a palavra enquanto não acaba
            if (linha[i] != ' ') {
                palavras[palavra][letra] = linha[i];
                letra ++;
            }
            // Se achou espaço acabou a palavra
            else {
                palavras[palavra][letra] = '\0';
                palavra ++;
                letra = 0;
            }
        }
        // Contabiliza a última palavra considerando seu fim
        if (letra > 0) {
            palavras[palavra][letra] = '\0'
            palavra ++;
        }
        for (int j = 0; j < palavra; j ++) {
            // Procura se a primeira letra é vogal
            if (strchr("aeiouAEIOU", palavras[j][0]) != NULL) {
                strcat(palavras[j], "ma");
            }
            // Caso não seja, ela cria uma cópia da palavra sem contar a primeira letra, adiciona ela no fim
            else {
                char copia[100];
                strcpy(copia, palavras[j] + 1);
                char primeira[2] = {palavras[j][0], '\0'};
                strcat(copia, primeira);
                strcat(copia, "ma");
                strcpy(palavras[j], copia);
            }
            // Adiciona o sufixo de acordo com a regra
            int tamanho = strlen(palavras[j]);
            strcat(palavras[j], 'a' * tamanho);
        }
    }
    return 0;
}