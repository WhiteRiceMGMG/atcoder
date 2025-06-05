/***********************************************
* file name : 002.c
* ploblem   : Encyclopedia of Parentheses（★3）
* class     : AtcoderTypical90
* note      : output N is length of "()"
* example   : ()() (()) (((()()))) → ok;
*             ()) ))(( ((((((      →　ng; 
* メモ　
  '('を-1に，')'を1に置き換えて考える．
  判定中に負になったらbreak;
  最後まで見て0になっていること．
  これらの条件全てをクリアすること．
  メイン関数　配列定義　戻り値int 引数なし
  カッコを設定する関数　戻り値なし　引数 int N int *array
  カッコを判断する関数 戻り値なし　引数 int N int *array
  カッコを描画する関数を作る．戻り値なし　引数 int N int *array
  ◇フローチャート
  数値入力
  ビット配列定義→カッコ設定関数へ渡す
  得られた数値より，-1と1の配列を作り，判定関数に渡す．
  ビット配列について，途中で負になったらflag=0
  ビット配列の総和が0にならなければflag=0
  それ以外でflag=1，描写関数に渡す
  描写関数では1の時'('，-1の時')'を描写する．
  ビット演算子について　
  2^Nを作る　→  (i << N)
  特定のビットが立っているか　→ if((bit >> 1) & 1) {;}
  & AND 5 & 3 = 1;
  ' OR '5
  ^ XOR 5 ^ 3 = 6
  ~ NOT ~5 = -6　符号にも影響
  << 左シフト 5<<1 = 10 x2になる
  >> 右シフト 5>>1 = 2 /2になる
***********************************************/
#include <stdio.h>

void define_bracket(int n, int *array);
void judge_bracket(int n, int *array);
void print_bracket(int n, int *array);

int main(void) {
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    int bitArray[24] = {0};
    define_bracket(n, bitArray);

}

void define_bracket(int n, int *bitArray) {
    int i = 0;
    int j = 0;
    int bit = 0;
    for (bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            if ((bit >> i) & 1) {
                bitArray[i] = 1;
            } else {
                bitArray[i] = -1;
            }
        }
        // ここで array[] に 1/-1 の並びが入ってる！
    }
}

void judge_bracket(int n, int *bitArray) {
    int i = 0;
    int flag = 0;
    int totalVal = 0;
    for(i = 0; i < n; i++) {
        if(i == 0) {
            totalVal += *(bitArray + i);
            continue;
        } else {
            ;
        }
        if(totalVal < 0) {
            flag = 0;
            break;
        }
    }
    if(flag == 0) {
        printf("");
    }    

}











/*
#include <stdio.h>

int main(void) {
    int i = 0;
    int n = 0;
    int total;
    int flag = 0;//0の時ダメ
    char symbol[20] = "";
    int bitArray[20] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        if(*(symbol)+i == '(') {
            *(bitArray+i) = 1;
        } else if(*(symbol + i) == ')') {
            *(bitArray + i) = -1;
        } else {
            ;
        }
    }
    
    for(i = 0; i < n; i++) {
        if(i == 0) {
            total += *(bitArray + i);
            continue;
        } else {
            ;
        }
        if(total < 0) {
            flag = 0;
            break;
        }
    }
    if(flag == 0) {
        printf("")
    }

}
いや，ダメダメ．入力されるのは数値だけ
*/







