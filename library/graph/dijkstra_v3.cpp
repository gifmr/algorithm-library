#include <bits/stdc++.h>
using namespace std;

// ダイクストラ法 (経路復元版)
// 最短距離が更新されるたびに、移動元の頂点をprevに保存することで、頂点sから頂点tへの最短路を復元できる
// 最短路の復元の計算量は、O(|V|)

const int INF = 1e9;
const int MAXV = 1005;

struct edge { int to, cost; };  // 辺
typedef pair<int, int> P;       // first: sからの最短距離, second: 頂点番号

int V;                          // 頂点数
vector<edge> G[MAXV];           // グラフ
int d[MAXV];                    // 頂点sからの最短距離

int pre[MAXV];                 // 最短路の直前の頂点

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  fill(pre, pre + V, -1);
  d[s] = 0;
  que.push(P(s, 0));
  
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    
    if(d[v] < p.first) continue;
    
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        pre[e.to] = v; // 最短路の直前の頂点を保存
      }
    }
  }
}

// 頂点sから頂点tへの最短路を返す
vector<int> get_path(int t){
  vector<int> path;
  // 頂点tから頂点sまで直前の頂点を遡る. 頂点sのprevは初期値の-1のままとなっている
  for(; t != -1; t = pre[t]) path.push_back(t);
  
  reverse(path.begin(), path.end());
  return path;
}