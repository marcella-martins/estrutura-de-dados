#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char letra;
    typedef struct {
        char nome[51];
        char endereco[101];
        char telefone[16];
        char aniversario[9];
    } Contato;
    int total_contatos = 0;
    char nome_busca[68];
    Contato *agenda = (Contato *)malloc(1000*sizeof(Contato));
    while (scanf(" %c", &letra) ==1 && letra != 'f') {
        if (letra == 'i') {
            // Usar algoritmo de inserção
            scanf(" %51[^\n]", agenda[total_contatos].nome);
            scanf(" %101[^\n]", agenda[total_contatos].endereco);
            scanf(" %16[^\n]", agenda[total_contatos].telefone);
            scanf(" %9[^\n]", agenda[total_contatos].aniversario);
            printf("Contato para %s inserido.\n\n", agenda[total_contatos].nome);
            total_contatos ++;
        }
        else if (letra == 'r') {
            // Usar algoritmo de remoção
            int quantidade = 0;
            scanf(" %51[^\n]", nome_busca);
            int i = 0;
            while (i < total_contatos) {
                if (strcmp(agenda[i].nome, nome_busca) == 0) {
                    for (int j = i; j < total_contatos - 1; j ++) {
                        agenda[j] = agenda[j + 1];
                    }
                    total_contatos --;
                    quantidade ++;
                }
                else {
                    i ++;
                }
            }
            printf("Contatos de %s removidos: %d.\n\n", nome_busca, quantidade);
        }
        else if (letra == 'p') {
            // Usar algoritmo de impressão
            printf("Listagem:\n");
            if (total_contatos != 0) {
                for (int i = 0; i < total_contatos; i ++) {
                    printf("(%d) %s  %s   %s %s\n", i + 1, agenda[i].nome, agenda[i].endereco, agenda[i].telefone, agenda[i].aniversario);
                }
            }
            else {
                printf("Nenhum contato.\n");
            }
            printf("\n");
        }
        else if (letra == 'b') {
            // Usar algoritmo de busca
            int existe = 0;
            scanf(" %51[^\n]", nome_busca);
            printf("Resultado da busca:\n");
            for (int i = 0; i < total_contatos; i ++) {
                if (strstr(agenda[i].nome, nome_busca) != NULL) {
                    // Conferir se está na listagem
                    printf("(%d) %s  %s   %s %s\n", i + 1, agenda[i].nome, agenda[i].endereco, agenda[i].telefone, agenda[i].aniversario);
                    existe ++;
                }
            }
            if (existe == 0) {
                printf("Nenhum contato.\n");
            }
            printf("\n");
        }
    }
    free(agenda);
    return 0;
}