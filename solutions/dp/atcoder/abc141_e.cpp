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
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define cout(d) cout<<d<<endl;
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

// ABC141 E - Who Says a Pun?
// https://atcoder.jp/contests/abc141/tasks/abc141_e
// 解説: https://www.youtube.com/watch?v=fHZhDUzhzN0
// dp[i][j]:= iとjを開始地点としたときの最大の連続する部分文字列数(重なる部分についても数える)
// dp[i][j]は、s[i]==s[j]ならば、dp[i+1][j+1]となる
// dpテーブルは、i=j=n-1、つまり文字列の末尾からはじめて埋めていく

int dp[5005][5005];

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  rrep(i, n){
    rrep(j, n){
      if(s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
      else dp[i][j] = 0;          // int型のグローバル配列は0初期化されるので無くてもよい
    }
  }
  
  int ans = 0;
  rep(i, n) rep(j, n){
    if(i >= j) continue;
    int now = min(dp[i][j], j-i); // j-iはjとiの距離. dpテーブルの数はiとjが重なる部分に対しても数えるが、重ならない部分の最大値はj-iとなる
    chmax(ans, now);
  }
  
  cout<<ans<<endl;
}