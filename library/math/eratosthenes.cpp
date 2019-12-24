#include <bits/stdc++.h>
using namespace std;

// エラトステネスの篩
// 参考: https://mathtrain.jp/eratosthenes
// O(nloglogn)

const int MAXN = 100005;        // 素数を探す範囲
bool _is_prime[MAXN];           // 添え字に対応する値の素数判定を格納
vector<int> P;                  // 素数を格納する

void eratosthenes(const int N)
{
  for (int i = 0; i <= N; i++) {
    _is_prime[i] = true;        // trueで初期化.
  }
  _is_prime[0]=_is_prime[1]=false;
  for (int i = 2; i <= N; i++) {
    if (_is_prime[i]) {
      for (int j = 2 * i; j <= N; j += i) {
        _is_prime[j] = false;   // iの倍数を篩にかける
      }
      P.emplace_back(i);
    }
  }
}