/*
入力
5
24 11 8 3 16

出力
3

→配列内のある数で他の数が割り切れない，という数を算出．
配列全体を見ると，計算量が膨大になる
ある配列の要素Xについて注目した時，
配列内にそのXの倍数がいるかどうか調べる．
→エラトステネスの篩

・数列の重複を調べるための配列を用意する．
　→ {0,0,2,0,0,2,1,1,0,0,}みたいな．
・for一回で，配列内のある数に対する倍数をマークする．
　→ {0,0,1,1,0,1,0,0,0,}みたいにフラグを管理する．
・配列の重複関数が0かつ，フラグ配列が0の数をカウント．
*/

#include <stdio.h>

#define MAX_ARRAY 100010


int N;

void flag_check(int *baseArray, int *flagArray);
void dupl_check(int *baseArray, int *duplArray);
int  final_check(int *flagArray, int *duplArray);

int main(void) {
    int baseArray[100010] = {0};
    int flagArray[100010] = {0};
    int duplArray[100010] = {0};
    int i = 0;
    int count = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &baseArray[i]);
    }
    flag_check(baseArray, flagArray);
    dupl_check(baseArray, duplArray);
    count = final_check(flagArray, duplArray);
    printf("%d", count);

    return 0;
}

void flag_check(int *baseArray, int *flagArray) {
    int i = 0;
    int j = 0;
    for(i = 0; i < N - 1; i++) {
        for(j = i + 1; j < N; j++) {
            if(baseArray[i] == baseArray[j]) {
                flagArray[i] = 1;
                flagArray[j] = 1;            
            }
        }
    }
}

void dupl_check(int *baseArray, int *duplArray) {
    int i = 0;
    int j = 0;
    for(i = 0; i < N - 1; i++) {
        for(j = i + 1; j < N; j++) {
            if (i == j) {
                continue;
            }
            if(baseArray[i] % baseArray[j] == 0) {
                duplArray[i] = 1;
                duplArray[j] = 1;
                break;
            }
        }
    }
}

int final_check(int *flagArray, int *duplArray) {
    int i = 0;
    int j = 0;
    int count = 0;
    for(i = 0; i < N; i++) {
        if((flagArray[i] != 0) && (duplArray[i] != 0)) {
            count++;
        }
    }
    return count;
}


