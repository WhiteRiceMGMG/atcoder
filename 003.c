#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005  // 最大ノード数

// 隣接リスト用
int edges[MAXN][100];  // 各ノードに最大100個まで隣接ノードを持てる（問題により調整）
int edge_count[MAXN];  // 各ノードの隣接ノード数

// スタック
int stack[MAXN];
int top;

// 距離配列
int dist[MAXN];

// DFS（スタック使って非再帰で書く）
void dfs(int start, int N) {
    for (int i = 0; i < N; i++) dist[i] = -1;
    dist[start] = 0;
    
    top = 0;
    stack[top++] = start;

    while (top > 0) {
        int v = stack[--top];
        for (int i = 0; i < edge_count[v]; i++) {
            int nv = edges[v][i];
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                stack[top++] = nv;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // グラフ作成
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;  // 0-indexed にする
        edges[a][edge_count[a]++] = b;
        edges[b][edge_count[b]++] = a;
    }

    // 1回目のDFS（仮に頂点0から）
    dfs(0, N);
    int farthest = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > dist[farthest]) {
            farthest = i;
        }
    }

    // 2回目のDFS（farthestから）
    dfs(farthest, N);
    int diameter = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > diameter) {
            diameter = dist[i];
        }
    }

    // 答え：直径 + 1
    printf("%d\n", diameter + 1);
    return 0;
}
