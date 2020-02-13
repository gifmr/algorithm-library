#include <bits/stdc++.h>
using namespace std;

// めぐる式 二分探索フレームワーク

// 実行前にリスト(elems)に要素を格納する
// また問題に応じて以下の部分を更新する
// (1) 判定条件
// (2) 先頭が条件を満たし途中から満たさなくなるパターンの場合、ok/ng の値を入れ替える

vector<int> elems;

bool isOK(int index, int key){
  if(elems[index] >= key) return true; // <- (1) ここの条件を変更する
  else return false;
}

int binary_search(int key){
  int ng = -1;                  // <- (2) ここを変更する
  int ok = (int) elems.size();  // <- このサンプルは先頭が条件を満たさず途中から満たす場合を想定している
  
  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;
    if(isOK(mid, key)) ok = mid;
    else ng = mid;
  }
  return ok;
}

signed main()
{
  // 実行サンプル
  elems = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
  
  cout << binary_search(51) << endl;  // 3
  cout << binary_search(1) << endl;   // 0
  cout << binary_search(910) << endl; // 9
  
  cout << binary_search(52) << endl;  // 6
  cout << binary_search(0) <<endl;    // 0
  cout << binary_search(911) <<endl;  // 10
}