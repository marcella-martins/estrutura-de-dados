#include <stdio.h>
#include <stdlib.h>


int main(void) {
    scanf("%d", &conjuntos);
    for (int c = 0; c < conjuntos; c ++) {
        scanf("", &linha);
        scanf("%d %d", &elementos, &cadeias);
        for (int k = 0; k < cadeias; k ++) {
            scanf("%s", &voucriar);
            printf("%s\n", voucriar);
        }
        printf("\n");
    }
}