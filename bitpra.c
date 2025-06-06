#include <stdio.h>

int main(void) {
    int x = 0;
    int count;
    scanf("%d", &x);
    while(x > 0) {
        if(x & 1) {
            count++;
        }
        x = x >> 1;
    }
    printf("%d", count);
    return 0;

}
