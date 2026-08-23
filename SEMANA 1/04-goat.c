#include <stdio.h> <string.h>


int main(void) {
    char linha[10500];
    while (scanf(" %[^\n]", linha) != EOF) {
        printf("%s\n", linha);
    }
    return 0;
}