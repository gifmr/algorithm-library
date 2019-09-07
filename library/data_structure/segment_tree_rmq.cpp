#include <bits/stdc++.h>
using namespace std;

// セグメント木 - RMQ(Range Minimum Qurery)

const int MAXN = 1 << 17; // 100000を超える最小の2のべき乗数. 単に大きな値

// セグメント木となる配列
int n, dat[2 * MAXN - 1];

// 引数n_の値の要素数で、セグメント木を初期化する. セグメント木は完全二分木のため、要素数は 2 * n - 1 となる
void init(int n_){
  n = 1;
  while(n< n_) n *= 2;
  for(int i = 0; i < 2 * n - 1; i++) dat[i] = INT_MAX;
}

// k番目の値をaに変更
void update(int k, int a){
  k += n - 1; // 各要素は葉ノードに格納されており、葉ではないノード総数はn-1個である
  dat[k] = a;
  while(k > 0){
    k = (k - 1) / 2; // 親->子への計算式は、2*k+1, 2*k+2となる. kを求めるには、(子の添字-1)/2で小数切捨てで求められる
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // 元の値より大きい値で更新される場合もあるため、2つの子を比較する
  }
}

// 半開区間 [a, b)の最小値を求める
// [l, r)はこれから検証する半開区間. kは現在いるノードを表し、根から下っていく. 呼び出しでは query(a, b, 0, 0, n) となる
int query(int a, int b, int k, int l, int r){
  // [a, b)と[l, r)が交差しない場合、最大値を返す
  if(r <= a || b <= l) return INT_MAX;
  
  // [l, r)が完全に含まれていれば、ノードの値を返す
  if(a <= 1 && r <= b) return dat[k];
  else{ // そうでなければ、2つの子の最小値を返す
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2); // 2点間の中点は、(l+r)/2である
    int v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, v2);
  }
}