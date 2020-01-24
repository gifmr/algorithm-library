#include <bits/stdc++.h>
using namespace std;

// フェルマーの小定理
// p を素数、a を p の倍数ではない任意の整数(p未満の値と捉えると分かりやすい)としたとき
// 定理: a^p-1 ≡ 1 (mod p)
// 参考
// 1: https://qiita.com/drken/items/6b4031ccbb2cab7436f3
// フェルマーの小定理の証明の過程で逆元の存在の証明が行われるが、
// 逆にフェルマーの小定理を利用することで、mod p における a の乗法逆元を求めることができる
// a * a^p-2 ≡ 1 (mod p)
// つまり、a の p-2 乗 (の mod p) が、逆元となる

long long fermat(long long a, long long mod) {
  long long cnt = mod - 2;
  long long res = 1;
  for (int i = 0; i < cnt; i++) {
    (res *= a) %= mod;
  }
  return res;
}