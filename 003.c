/*
① グラフ（木）の入力を受け取る
     ↓
② 隣接リスト（edges）を作る
     ↓
③ DFS①（ノード0から）で最も遠いノードAを探す
     ↓
④ DFS②（Aから）で最も遠いノードBを探す
     ↓
⑤ AとBの距離（= 木の直径）を求める
     ↓
⑥ 直径 + 1（= ノード数）を出力

*/



#include <stdio.h>

#define MAXN 100005  // ノードの最大数（10^5まで対応）

// 隣接リスト：各ノードに隣接するノードを最大100個まで格納
int edges[MAXN][100];      

// 各ノードの隣接ノード数（何個つながっているか）
int edge_count[MAXN];

// スタック（DFSに使う）とスタックのサイズ
int stack[MAXN];
int stack_size;

// 各ノードの距離（-1は未訪問）
int dist[MAXN];

// 深さ優先探索（DFS）関数：スタックを使って非再帰で書く
void dfs(int start, int N) {
    // 距離を全て -1 に初期化（未訪問を意味する）
    for (int i = 0; i < N; i++) {
        dist[i] = -1;
    }

    // 始点ノードは距離0、自分自身だから
    dist[start] = 0;

    // スタックを初期化し、始点を積む
    stack_size = 0;
    stack[stack_size] = start;
    stack_size++;

    // スタックにノードがある限り繰り返す
    while (stack_size > 0) {
        // スタックの一番上のノードを取り出す
        int current = stack[stack_size - 1];
        stack_size--;

        // current に隣接する全てのノードを調べる
        for (int i = 0; i < edge_count[current]; i++) {
            int neighbor = edges[current][i];

            // まだ訪問していない場合
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;  // 距離を1増やす
                stack[stack_size] = neighbor;       // スタックに積む
                stack_size++;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);  // ノード数を読み込む

    // N-1 本の辺を読み込んで、グラフを作る
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        a--; b--;  // 0番から始まるように変換

        // 無向グラフなので両方に追加
        edges[a][edge_count[a]++] = b;
        edges[b][edge_count[b]++] = a;
    }

    // 1回目のDFS：仮にノード0から開始
    dfs(0, N);

    // 最も遠いノードを探す（最長距離を持つノード）
    int farthest_node = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > dist[farthest_node]) {
            farthest_node = i;
        }
    }

    // 2回目のDFS：最も遠かったノードから開始
    dfs(farthest_node, N);

    // 直径を求める（最長距離）
    int diameter = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > diameter) {
            diameter = dist[i];
        }
    }

    // 答えを出力：直径（辺の数） + 1 = ノード数
    printf("%d\n", diameter + 1);

    return 0;
}
