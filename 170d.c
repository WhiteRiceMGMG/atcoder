/*
Atcode begginer contest 170 D問題
Not Divisible

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
#define MAX_VAL 1000001


int N;

void flag_check(int *baseArray, int *flagArray, int *countArray);
void dupl_check(int *baseArray, int *duplArray, int *countArray);
int  final_check(int *flagArray, int *duplArray, int *countArray);

int main(void) {
    int baseArray[100010] = {0};
    int flagArray[100010] = {0};
    int duplArray[100010] = {0};
    int countArray[1000001] = {0};
    int i = 0;
    int count = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &baseArray[i]);
        countArray[baseArray[i]]++;
    }
    flag_check(baseArray, flagArray,countArray);
    dupl_check(baseArray, duplArray,countArray);
    count = final_check(flagArray, duplArray, countArray);
    printf("%d", count);

    return 0;
}

void flag_check(int *baseArray, int *flagArray, int *countArray) {
    int i = 0;
    for(i = 0; i < N; i++) {
        if(countArray[baseArray[i]] > 1) {
            {
            flagArray[i] = 1;
            }
        }
    }
}

void dupl_check(int *baseArray, int *duplArray, int *countArray) {
    int i = 0;
    int j = 0;
    static char exists[1000001] = {0};
    for(i = 0; i < N; i++){
        exists[baseArray[i]] = 1;
    }
    for(int i = 0; i < N; i++) {
        int val = baseArray[i];
        for(int j = val * 2; j < MAX_VAL; j += val) {
            if(exists[j]) {
                duplArray[i] = 1;  
                break;
            }
        }
    }
}

int final_check(int *flagArray, int *duplArray, int *countArray) {
    int i = 0;
    int j = 0;
    int count = 0;
    for(i = 0; i < N; i++) {
        if((flagArray[i] == 0) && (duplArray[i] == 0)) {
            count++;
        }
    }
    return count;
}
