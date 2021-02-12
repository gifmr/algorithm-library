#include <bits/stdc++.h>
using namespace std;

// ダイクストラ法 (計算量改善前)
// O(|V|^2)

const int INF = 1e9;
const int MAXV = 1005;

int cost[MAXV][MAXV]; // cost[u][v]: 辺(u,v)のコスト(存在しない場合はINF)
int d[MAXV];          // 頂点sからの最短距離
bool used[MAXV];      // すでに使われたかのフラグ
int V;                // 頂点数

void dijkstra(int s){
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[s] = 0;
  
  // 全頂点についてのループ
  // 1回のイテレーションで未処理の頂点の中で頂点sから最短距離のものを処理する.
  while(true){
    int v = -1; // 未処理の頂点のうち、頂点sから最短距離であるものを格納する. -1は全ての頂点について処理済みであることを意味する
    for(int u = 0; u < V; u++){
      // 未処理の頂点のうち、sから最短距離である頂点をvに格納する
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    
    // 全ての頂点が処理済みならば、ループを抜ける
    if(v == -1) break;
    
    used[v] = true;
    
    for(int u = 0; u < V; u++){
      // 計算済みの頂点uの最短距離より短い場合、最短距離を更新する. 存在しない辺は、cost[v][u] = INFとなる
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }
}