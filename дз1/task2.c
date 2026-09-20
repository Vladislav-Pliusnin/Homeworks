#include <stdio.h>
int main() {
    int first;
    int last;
    scanf("%X %X", &first, &last);
    printf("    ");
    for (int i = 0; i < 16; i++) {
        printf(" %X ", i);
    }
    printf("\n");
    for (int i = first; i <= last; i += 16) {
        printf( "%02X  ", i & 0xF0);
        for (int j = 0; j < 16; j++) {
            int number = i + j;
            if (number > last  || number < first) {
                printf("   ");
            }
            else if (number >= 32 && number <= 126) {
                printf(" %c ", number);
            }
            else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    return 0;
}