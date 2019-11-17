#include <bits/stdc++.h>
using namespace std;

// 参考: https://www.youtube.com/watch?v=zV3Ul2pA2Fw&feature=youtu.be&t=1948
// class化
// グループのサイズを取得可能

class UnionFind{
  public:
  // 親の番号を格納する．親の場合は-(その集合のサイズ)
  vector<int> Parent; 
  
  // 全て-1
  UnionFind(int N){
    Parent = vector<int>(N, -1);
  }
  
  // Aがどのグループに属しているか
  int root(int A){
    if(Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]); // return前に自分の親を更新することで高速化
  }
  
  // 自分のいるグループの頂点数を調べる
  int size(int A){
    return -Parent[root(A)]; 
  }
  
  // AとBをくっつける
  bool connect(int A, int B){
    // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
    A = root(A);
    B = root(B);
    if(A == B){
      // すでにくっついているからくっつけない
      return false;
    }
    
    // グループのサイズが大きい方(A)に小さい方(B)をくっつけたい
    // 大小が逆ならひっくり返す
    if(size(A) < size(B)) swap(A, B);
    
    // Aのサイズを更新する
    Parent[A] += Parent[B];
    // Bの親をAに変更する
    Parent[B] = A;
    
    return true;
  }
};