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

void define_bracket(int n);
void print_bracket(int n, int *array);

int main(void) {
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    if (n % 2 != 0) {
        return 0;
    }
    define_bracket(n);

}
void define_bracket(int n) {
    int bit;
    int array[24]; 

    for (bit = 0; bit < (1 << n); bit++) {
        int sum = 0;
        int is_valid = 1;

        for (int i = 0; i < n; i++) {
            if ((bit >> (n - 1 - i)) & 1) {
                array[i] = 1; 
            } else {
                array[i] = -1; 
            }
            sum += array[i];
            if (sum < 0) {
                is_valid = 0;
                break;
            }
        }

        if (sum != 0) is_valid = 0;

        if (is_valid) {
            print_bracket(n, array);
        }
    }
}
void print_bracket(int n, int *array) {
    for (int i = 0; i < n; i++) {
        if (array[i] == 1) {
            printf("(");
        } else {
            printf(")");
        }
    }
    printf("\n");
}


