#include <stdio.h>


int main(void) {
    int bandejas;
    scanf("%d", &bandejas);
    int latas, copos;
    int quebrados = 0;
    for (int i = 0; i < bandejas; i++) {
        scanf("%d %d", &latas, &copos);
        if (latas > copos) {
            quebrados += copos;
        }
    }
    printf("%d\n", quebrados);
    return 0;
}