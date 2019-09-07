#include <bits/stdc++.h>
using namespace std;

// Union-Find木
// 参考: https://www.slideshare.net/iwiwi/ss-3578491
// グループ分けを行うためのデータ構造.
// グループの併合はできても分割はできない. そのため初期状態は全ての要素が別々のグループに属した状態となる
// Union-Find木は2つの工夫を行うことで、O(α(n))となる. α(n) はアッカーマン関数の逆関数であり、O(log n)よりも高速である
// (1) rankの記憶
// 各グループの木の高さ(rank)を記憶し、rankの小さいものを大きいものへ辺を張る. こうすることで、findの計算量が(大きい木の高さ) - (小さい木の高さ) 分削減できる
// (2) 経路圧縮
// 各ノードを直接根に接続する. findの際、検索したノードを一括して圧縮することが可能

const int MAXN = 1005;

int par[MAXN]; // 親
int rank[MAXN]; // 木の深さ

// n要素について初期化
void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i; // 初期は全ての頂点が根
    rank[i] = 0; // 高さ0
  }
}

// 根の探索
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return; // 既に同じグループの場合
  
  // rankの高さが低い方を高い方へ接続する
  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++; // 同じrank(木の高さ)を比較したときに、rankが上がる. rankに格納される数字は木の高さを表している訳ではない
  }
}

// 同じグループ化を判定
bool same(int x, int y){
  return find(x) == find(y);
}