#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char letra;
    typedef struct {
        char nome[68];
        char endereco[100];
        char telefone[15];
        char aniversario[8];
    } Contato;
    int total_contatos = 0;
    char nome_busca[68];
    int quantidade = 0;
    int existe = 0;
    Contato *agenda = (Contato *)malloc(1000*sizeof(Contato));
    while (scanf(" %c", &letra) != 'f') {
        if (letra == 'i') {
            // Usar algoritmo de inserção
            scanf(" %[^\n]", agenda[total_contatos].nome);
            scanf(" %[^\n]", agenda[total_contatos].endereco);
            scanf(" %[^\n]", agenda[total_contatos].telefone);
            scanf(" %[^\n]", agenda[total_contatos].aniversario);
            printf("Contato para %s inserido.\n", agenda[total_contatos].nome);
            total_contatos ++;
        }
        if (letra == 'r') {
            // Usar algoritmo de remoção
            scanf(" %s", nome_busca);
            for (int i = 0; i < total_contatos; i ++) {
                if (agenda[i].nome == nome_busca) {
                    for (int j = i; j < total_contatos; j ++) {
                        if (j != total_contatos - 1) {
                            strcpy(agenda[j].nome, agenda[j + 1].nome);
                            strcpy(agenda[j].endereco, agenda[j + 1].endereco);
                            strcpy(agenda[j].telefone, agenda[j + 1].telefone);
                            strcpy(agenda[j].aniversario, agenda[j + 1].aniversario); 
                        }
                    }
                    total_contatos --;
                    quantidade ++;
                }
            }
            printf("Contatos de %s removidos: %d.\n", nome_busca, quantidade);
        }
        if (letra == 'p') {
            // Usar algoritmo de impressão
            printf("Listagem:\n");
            if (total_contatos != 0) {
                for (int i = 1; i <= total_contatos; i ++) {
                    printf("(%d) %s	%s %ld %s\n", i, agenda[i-1].nome, agenda[i-1].endereco, agenda[i-1].telefone, agenda[i-1].aniversario);
                }
            }
            else {
                printf("Nenhum contato.\n");
            }
        }
        if (letra == 'b') {
            // Usar algoritmo de busca
            scanf(" %s", nome_busca);
            printf("Resultado da busca:\n");
            for (int i = 0; i < total_contatos; i ++) {
                if (nome_busca == agenda[i].nome) {
                    // Conferir se está na listagem
                    printf("(%d) %s	%s %ld %s\n", i + 1, agenda[i].nome, agenda[i].endereco, agenda[i].telefone, agenda[i].aniversario);
                    existe ++;
                }
            }
            if (existe == 0) {
                printf("Nenhum contato.\n");
            }
        }
        printf("\n");
    }
    return 0;
}