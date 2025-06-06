/*偶数か奇数かをビットで判定*/

#include <stdio.h>

int main(void) {
    int num = 0;
    int count = 0;
    scanf("%d", &num);
    if((num & 1) == 1) {
        printf("奇数");        
    } else if((num & 1) == 0) {
        printf("偶数");
    }
    return 0;
}