#include <bits/stdc++.h>
using namespace std;

// ワーシャルフロイド法
// 全点対最短路問題(全ての2点間の最短路を求める問題)で使われる
// d[i][j]:頂点iから頂点jへの仮の最短路 とすると、d[i][j]は各頂点を中継した場合のコストを比較することで求められる
// O(|V|^3)

const int INF = 1e9;
const int MAXV = 105;

int d[MAXV][MAXV];  // d[u][v]:辺e=(u,v)のコスト(存在しない場合はINF、d[i][i]=0とする)
int V;              // 頂点数

// 頂点kを経由しない場合とする場合を比較し、各2頂点間の最短路を求める
void warshall_floyd(){
  for(int k = 0; k < V; k++) // 中継点についてのループ
    for(int i = 0; i < V; i ++) // 始点についてのループ
      for(int j = 0; j < V; j++) // 終点についてのループ
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}