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


/*
#include <stdio.h>

#define MAX_VAL 1000001

int N;
int baseArray[100010];
int flagArray[100010];   // 重複マーク
int duplArray[100010];   // 倍数マーク
int countArray[MAX_VAL]; // 値ごとの出現回数

void flag_check();
void dupl_check();
int  final_check();

int main(void) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &baseArray[i]);
        countArray[baseArray[i]]++;
    }

    flag_check();  // 重複のある値にマーク
    dupl_check();  // baseArray[i] が他の値の倍数ならマーク
    int count = final_check();

    printf("%d\n", count);
    return 0;
}

// 値の重複チェック（O(1)で出現回数見られる）
void flag_check() {
    for(int i = 0; i < N; i++) {
        if(countArray[baseArray[i]] > 1) {
            flagArray[i] = 1; // 重複がある値
        }
    }
}

// 値の倍数関係チェック（エラトステネス風）
void dupl_check() {
    static char exists[MAX_VAL] = {0};

    // 存在フラグを立てる（入力で使われた値のみ）
    for(int i = 0; i < N; i++) {
        exists[baseArray[i]] = 1;
    }

    // 各 baseArray[i] について、倍数が存在すればマーク
    for(int i = 0; i < N; i++) {
        int val = baseArray[i];
        for(int j = val * 2; j < MAX_VAL; j += val) {
            if(exists[j]) {
                duplArray[i] = 1;  // 倍数が配列に存在
                break;
            }
        }
    }
}

// 両方の条件を満たす要素数をカウント
int final_check() {
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(flagArray[i] == 0 && duplArray[i] == 0) {
            count++;
        }
    }
    return count;
}


*/