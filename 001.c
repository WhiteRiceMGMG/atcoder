#include <stdio.h>

#define MAX_N 100010

int N, L, K;
int A[MAX_N];

int solve(int M) {
    int cut_count = 0;
    int prev = 0;
    int total_cut_length = 0;

    for (int i = 1; i <= N; i++) {
        prev += A[i] - A[i - 1];
        if (prev >= M) {
            cut_count++;
            total_cut_length += prev;
            prev = 0;
        }
    }

    if (cut_count > K) return 1;
    if (cut_count == K && (L - total_cut_length) >= M) return 1;
    return 0;
}

int main() {
    // 入力
    scanf("%d %d %d", &N, &L, &K);
    A[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    int ok = 0;
    int ng = L + 1;
    while ((ng - ok) > 1) {
        int mid = (ok + ng) / 2;
        if (solve(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    printf("%d\n", ok);
    return 0;
}
