#include <bits/stdc++.h>
using namespace std;

// 拡張ユークリッドの互除法
// 一次不定方程式の解を求めるアルゴリズム
// 参考
// 1: https://qiita.com/drken/items/b97ff231e43bce50199a
// 2: https://misteer.hatenablog.com/entry/extgcd
// mod pにおける a の逆元を求めることにも使える
// pがaより大きい素数であるとき、
// mod p における a の乗法逆元は ax + py = 1 の解x であって 0 <= x < p を満たすものになる

long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = extGCD(b, a%b, y, x);
  y -= (a/b) * x;
  return g;
}

long long _extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = extGCD(b, a%b, x, y);
  long long prex = x;
  x = y;
  y = prex - (a/b) * x;
  return g;
}