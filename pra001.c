/*
キーワード　二分探索　最適化判定問題　貪欲法
類似問題
ABC 165 D – Floor Function
ARC 090 C – Candies
Typical 90 – Problem 001 (Yokan Party)
ABC 070 D – Transit Tree Path
AOJ DSL_1_B – Union Find Tree
Binary Search – Allocate Minimum Number of Pages
Leetcode 410 – Split Array Largest Sum
*/




/*
長さ L の棒があり、途中の切れる位置が A[1] ~ A[N] に与えられる。
棒を K 回切って → K+1個 に分ける。
各ピースの長さは M以上にしたい
**Mが指定されたときに、M以上のピースがK+1個作れるか？**を確認したい。
*/
#include <stdio.h>

#define MAX_N 100010

int N, K, L;
int array[MAX_N];

// score以上の長さのピースをK+1個作れるか判定
int judge(int score) {
  int i;
  int count = 0;
  int prev = 0;

  for (i = 0; i < N; i++) {
    int len = array[i] - prev;
    if (len >= score) {
      count++;
      prev = array[i];
    }
  }

  // 最後のピース（L - prev）もscore以上ならカウント
  if (L - prev >= score) {
    count++;
  }

  return count >= K + 1; // K回切ってK+1ピースできるか？
}

int main(void) {
  int i;
  scanf("%d %d %d", &N, &K, &L);
  for (i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }

  int left = 0;
  int right = L + 1;

  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (judge(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }

  printf("%d\n", left);
  return 0;
}
