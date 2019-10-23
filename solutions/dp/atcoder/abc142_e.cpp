#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define FOR(e, c) for (auto &e : c)
#define SORT(v, n) sort(v, v + n);
#define vsort(v) sort(v.begin(), v.end());
#define rvisort(v) sort(v.begin(), v.end(), greater<int>());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout << d << endl;
#define coutd(d) cout << std::setprecision(10) << d << endl;
#define cinline(n) getline(cin, n);
#define replace_all(s, b, a) replace(s.begin(), s.end(), b, a);
#define PI (acos(-1))
// #define int long long

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// ABC 142 E - Get Everything
// https://atcoder.jp/contests/abc142/tasks/abc142_e
// O(2^N * M)

// bit DP
// dp[集合S] := Sを全て開けられる鍵の買い方の最小コスト


int n, m;
vi A(1005);
vi B(1005);
int C[1005][20];  // C[m][n]

void input(){
  cin >> n >> m;
  reps(i, m){
    cin >> A[i] >> B[i];
    reps(j, B[i]) cin >> C[i][j];
  }
}

void solve(){
  vi dp(5000, INF); // 2^n つまり 2^12 == 4096 通りのコストを格納するため 5000
  dp[0] = 0;
  for(int item = 1; item <= m; item++){
    int now = 0; // 開けることができる宝箱
    for(int j = 1; j <= B[item]; j++){
      // 1bit目を1番目の宝箱と対応させるために、c[item][j]に格納される開けることができる宝箱の番号から1を引いている
      now |= (1 << (C[item][j] - 1));
    }
    for(int bits = 0; bits < (1 << n); bits++){
      chmin(dp[bits | now], dp[bits] + A[item]);
    }
  }
  if(dp[(1 << n) - 1] == INF) dp[(1 << n) - 1] = -1; // (1 << n) - 1 で2進表記でn桁全て1となる
  cout << dp[(1 << n) - 1] << endl;
}

signed main() {
  
  input();
  solve();
  
}