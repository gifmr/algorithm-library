#include <bits/stdc++.h>
using namespace std;

// ヒープ
// push, pop いずれの計算量も木の深さに対応するため、O(log n)

const int MAXN = 1005;
int heap[MAXN], sz = 0;

void push(int x){
  // 自分のノード番号を取得する. szには現在の要素数を格納するため、ノード番号取得後にインクリメントを行う
  int i = sz++;
  while(i > 0){
    // 親ノードの番号を取得
    int p = (i - 1) / 2;
    // xが親ノード以上であれば抜ける
    if(heap[p] <= x) break;
    // xが親ノードより小さいならば、ノードを逆転させる
    heap[i] = heap[p];
    i=p;
  }
  heap[i] = x;
}

int pop(){
  // 最小値
  int ret = heap[0];
  
  // 末尾の値を根から下りながら比較していく. szは要素数となるので、前置デクリメントで要素数を減らすと同時に、最後の要素番号に対応させている
  int x = heap[--sz];
  
  int i = 0;
  // 現在のノードに対して、子ノードが少なくとも1つある場合、ループする
  while(i * 2 + 1 < sz){
    // 2つの子ノードの番号を取得. この時、bには要素が入っていない可能性がある
    int a = i * 2 + 1;
    int b = i * 2 + 2;
    // 常にheap[a]と比較するようにし、heap[a]<heap[b] ならば a=b とすることで、常に小さい方の子ノードと比較している
    if(b < sz && heap[b] < heap[a]) a = b;
    // xが子ノードよりも小さければ逆転終了
    if(heap[a] >= x) break;
    // 親ノード>子ノードならば、ノードを逆転させる
    heap[i] = heap[a];
    i = a;
  }
  // 末尾の値を適正な位置へ格納
  heap[i] = x;
  
  return ret;
}