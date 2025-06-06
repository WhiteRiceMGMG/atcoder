#include <stdio.h>
int main(void) {
    int num;
    scanf("%d", &num);
    int lower8bit = num & 0xFF;
    int reverce8bit = ~lower8bit;
    reverce8bit = reverce8bit & 0xFF;
    printf("%d",reverce8bit);
    return 0;
}