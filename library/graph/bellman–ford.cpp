#include <bits/stdc++.h>
using namespace std;

// ベルマン–フォード法
// 負閉路を想定しない
// O(|V||E|)
// esに格納されている辺の順によっては1つずつ頂点のコストが決まっていくため、この場合のwhileループは、|V-1|回行われる
// |V-1|回のループに対して、各辺の数(|E|)だけコスト計算を行うため、計算量は、|V-1|*|E| すなわち O(|V||E|)
// 参考: https://nw.tsuda.ac.jp/lec/BellmanFord/

const int INF = 1e9;

struct edge { int from, to, cost; };

const int MAXE = 1005;
edge es[MAXE];          // 辺. edge struct

const int MAXV = 1005;
int d[MAXV];            // 最短距離格納用
int V, E;               // 頂点数, 辺数

// s番目の頂点から各頂点への最短経路を求める
void shortest_path(int s){
  
  for(int i = 0; i < V; i++) d[i] = INF;
  d[s] = 0;
  
  while(true){
    
    bool update = false; // コストが更新されたかの判定用
    
    // esの先頭から順に辺を取り出す. 頂点sをfromとする辺から計算が始まる
    for(int i = 0; i < E; i++){
      edge e = es[i]; // 辺を取り出す
      // 辺のfrom側の頂点がINFではない(つまり初期化もしくは計算済み)、かつ、辺のto側の頂点がfromからのコストより大きい場合、そのコストを更新する
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){ // 負の閉路があるならば、d[e.to] > d[e.from] + e.cost が常にtrueとなる無限ループとなる
        d[e.to] = d[e.from] + e.cost;
        update = true; // 頂点のコストが更新された
      }
    }
    
    if(!update) break; // 頂点が1つも更新されなかった場合、コストの計算が完了したことになる
  }
}

// 負の閉路が存在するかを判定する
bool find_negative_loop(){
  memset(d, 0, sizeof(d));
  
  // 負の閉路が存在しないならば、V-1(頂点数-1)回のループで更新は発生しなくなる. 
  // 1回のイテレーションでは、少なくとも1つの頂点が定まる. このうち始点となる頂点は初めからコストが定めているため、負閉路がない場合のループ回数はV-1回となる
  for(int i = 0; i < V; i++){
    for(int j =0; j < E; j++){
      edge e = es[j];
      if(d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        
        // V回目のループは全頂点についてのコスト計算を終え、2周目を意味する
        // 2周目で更新があるという事は、常にコストが減少し続ける負閉路が存在することになる
        if(i == V-1) return true;
      }
    }
  }
  return false;
}