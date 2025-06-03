/*
長さ L の棒があり、途中の切れる位置が A[1] ~ A[N] に与えられる。
棒を K 回切って → K+1個 に分ける。
各ピースの長さは M以上にしたい
**Mが指定されたときに、M以上のピースがK+1個作れるか？**を確認したい。
*/
#include <stdio.h>

#define MAX_N 100010

int N,K,L;
int array[MAX_N];

/*最大値Mが成立する時1を返す*/
int judge(int score);

int main(void) {
  int i = 0;
  scanf("%d %d %d", &N, &K, &L);
  for(i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }
  
  /*二分探索，最大となるスコアを探す．
  right - left == 1になったら探索は終わり．
  この時のleftが最大のスコア，
  rightが条件を満たさない最小のM
  judge()ではスコアが見つかるたびに左が確定していく
  最後に条件をギリギリ満たす最大長がleftに残る*/
  int left = 0; /*絶対に条件を満たす最小値*/
  int right = L + 1　/*絶対に条件を満たさないギリギリ*/
  while(right - left > 0) {
    int mid = (left + right) / 2;
    if(judge(mid) != 0) {
      mid = left;
    } else {
      mid = right;
    }
  }

  printf("%d", left);
  return 0;
}

int judge(int score) {

}


