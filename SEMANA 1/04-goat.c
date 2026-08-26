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
    }
    return 0;
}