#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

const int maxn = 1010;
long long S[maxn][maxn];

// 第2種スターリング数
// 写像12相のうち、玉:区別あり、箱:区別なし、箱に入れる玉の個数:1個以上 の場合の数はスターリング数となる
// S(N, K) = S(N-1, K-1) + K * S(N-1, K)
// 上記の漸化式の意味
// 玉1 ～ N のうち、玉1に着目する
// S(N-1, K-1) : 玉1が1個だけが1つの箱に入る場合、この場合玉1以外のN-1個でK-1個の箱への入れ方を考える
// K * S(N-1, K) : 玉1が1個だけが1つの箱に入らない場合、N-1個の玉でK個の箱の入れ方を考え、そのうちの1個の箱に玉1を入れる
void stirling_number(long long N, long long K){
  for(int i=1; i<=N; i++){
    S[i][1] = 1;
    S[i][i] = 1;
  }
  for(int i=2; i<=N; i++){
    for(int j=2; j<=K; j++){
      S[i][j] = (S[i-1][j-1] + (K * S[i-1][j]) % MOD) % MOD;
    }
  }
}