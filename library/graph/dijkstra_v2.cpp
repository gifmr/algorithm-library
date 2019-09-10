#include <bits/stdc++.h>
using namespace std;

// ダイクストラ法 (計算量改善版)
// 改善前、隣接行列を使い未処理の頂点の中から最短距離のものを探す工程を効率化する
// 改善後では、隣接リストをヒープで構築することで効率化する
// ヒープの隣接リストの場合、要素の追加と取り出しに計算量に関わる. 要素数は頂点数|V|で、追加と取り出しの操作回数は最大で辺数|E|に対応するため計算量は以下のようになる
// O(|E| log |V|)

const int INF = 1e9;
const int MAXV = 1005;

struct edge { int to, cost; };  // 辺
typedef pair<int, int> P;       // first: sからの最短距離, second: 頂点番号

int V;                          // 頂点数
vector<edge> G[MAXV];           // グラフ
int d[MAXV];                    // 頂点sからの最短距離

void dijkstra(int s){
  // 最短距離の頂点を取得するために、priority_queueを昇順に設定している
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(s, 0)); // 始点を追加
  
  // whileのイテレーション:1つの頂点について, forのイテレーション:頂点から出る辺について  → while内全体で全ての辺についてのループとなる
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second; // 最短距離である頂点を取得
    
    // 仮の最短距離と頂点の組が更新されるたび、queにその組が追加される
    // そのため、同じ頂点について複数の要素が存在する場合があるが、最短距離でないなら処理をスルーする
    if(d[v] < p.first) continue;
    
    // 頂点vから出る辺についてのループ
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      // 最短距離を更新できる場合
      // ここは同じ頂点に対して、コストの大きい経路 → コストの小さい経路の順で評価した場合、辺の数だけ同じ頂点の要素がqueに追加される
      // この場合のqueに追加される要素数はO(|E|)となるが、上のcontinue文で同じ頂点の処理をスルーさせることにより、O(|E| log |V|)に近い計算量になる. (スルーさせない場合、O(|E| log |E|)となる)
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}