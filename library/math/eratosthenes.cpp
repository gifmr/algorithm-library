#include <bits/stdc++.h>
using namespace std;

// エラトステネスの篩
// 参考: https://mathtrain.jp/eratosthenes
// O(nloglogn)

const int MAXN = 1000005; // 素数を探す範囲
bool _is_prime[MAXN];     // 添え字に対応する値の素数判定を格納
vector<long long> P;      // 素数を格納する

void eratosthenes(const long long N)
{
  for (long long i = 0; i <= N; i++)
  {
    _is_prime[i] = true; // trueで初期化.
  }
  for (long long i = 2; i * i <= N; i++)
  {
    if (_is_prime[i])
    {
      for (long long j = 2 * i; j <= N; j += i)
      {
        _is_prime[j] = false; // iの倍数を篩にかける
      }
      P.emplace_back(i);
    }
  }
}