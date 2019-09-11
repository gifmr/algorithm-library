#include <bits/stdc++.h>
using namespace std;

// プリム法 (計算量改善前)
// 最小全域木問題で使われるアルゴリズム
// 元のグラフの頂点をすべて含む木を全域木と呼び、その中でも辺のコストの総和が最小ものを最小全域木と呼ぶ
// 辺をコストの小さい順に見ていき、閉路ができなければ追加していく

// 証明
// 参考: http://drken1215.hatenablog.com/entry/20121223/1356230697
// 1) 上記のように辺の取った全域木をTとすると、Tは自身に含まれない任意の辺eについて、基本閉路C(T,e)の任意の辺をfとすると、w(e) >= w(f) を満たすような全域木となる
//    これは全域木Tに辺eを追加すると必ず閉路ができるわけだが、その閉路内のe以外の任意の辺fは辺eよりもコストが小さいということを意味する
// 2) Tとは異なる全域木Sを考える. |S-T|=n(つまりSはTと共通の辺を持たない)の場合、Sの任意の辺eをSから取り出してTにおいて接続し、それによってできた基本閉路C(T,e)の任意の辺fをTから取り出してSに接続する(つまりeとfを交換する)
//    そうしてできたS'は、1)の条件「w(e) >= w(f)」により、w(S')<=w(S)となる. また、|S'-T|=n-1である
//    このS'についてさらに、(e,f)とは別の組合せでTと辺の交換を行うと、S''<=S'であり、|S''-T|=n-2. これをS'''...と繰り返していくと、そのコストは減少を続け、やがて|S'''...-T|=0、つまりS'''...は全域木Tとなる
// 3) 2)より、1)を満たす全域木TはグラフGにおける全域木の中の最小値であると証明されたため、全域木Tは最小全域木である. よって、クラスカル法の手順で辺を取っていけば、それは最小全域木となる

// O(|E| log |V|)
// クラスカル法は辺をソートする部分に一番時間がかかる


// -- Union-Find --

const int MAXN = 1005;

int par[MAXN];
int rnk[MAXN];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  
  if(rnk[x] < rnk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

// -- Union-Find --


struct edge{ int u, v, cost; };

// edgeの配列をcostによってソートするためのメソッド
bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

const int MAXE = 1005;
edge es[MAXE];
int V, E;                   // 頂点数, 辺数

int kruskal(){
  sort(es, es + E, comp);   // コストの小さい順に辺をソート
  init(V);                  // Union-Findの初期化
  int res = 0;
  for(int i=0; i < E; i++){ // 辺の数だけループ
    edge e = es[i];
    if(!same(e.u, e.v)){    // 辺が採用される度に両端の頂点は1つのグループに併合される. つまり、ある辺の両端が同じグループであるという事はその辺を採用することで閉路ができることを意味する
      unite(e.u, e.v);      // 辺を採用した場合、両端の頂点のグループを併合することで、既に全域木の一部であることを表現する
      res += e.cost;
    }
  }
  return res;
}