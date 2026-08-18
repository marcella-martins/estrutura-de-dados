#include <stdio.h>


int main(void) {
    int depositos = 1;
    int joaozinho = 0;
    int zezinho = 0;
    int n_teste = 0;
    scanf("%d", &depositos);
    while (depositos != 0) {
        n_teste += 1;
        printf("Teste %d\n", n_teste);
        int cents_j = 0;
        int cents_z = 0;
        for (int i = 1; i <= depositos; i++) {
            scanf("%d %d", &joaozinho, &zezinho);
            int diferenca;
            cents_j += joaozinho;
            cents_z += zezinho;
            diferenca = cents_j - cents_z;
            printf("%d\n", diferenca);
        }
        scanf("%d", &depositos);
        printf("\n");
    }
}
