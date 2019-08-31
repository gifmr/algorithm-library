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
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define rv(s) reverse(s.begin(),s.end());
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vs = vector<string>;
using vd = vector<double>;
using ul = unsigned long;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// 蟻本:pp.60 ナップサック問題その2
// Wの範囲が大きい場合、O(nW)では解けない
// 普通のナップサック問題では「重さに対する最大の価値」をDPで計算したが、ここでは「価値に対する最小の重さ」をDPで計算する

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  int n,W;
  cin>>n>>W;
  
  int v[100],w[100];
  rep(i,n){
    cin>>v[i]>>w[i];
  }
  
  int MAX_V=100;
  int MAX_N=100;
  
  // dp[i+1][j]:=i番目の品物から価値の総和がjとなるように選んだ時の重さの総和の最小値
  int dp[MAX_N+1][MAX_V*MAX_N+1];
  
  // dp[0][0]～dp[0][MAX_V*MAX_N+1]をINFで初期化
  fill(dp[0], dp[0]+MAX_V*MAX_N+1, INF);
  // 品物0以前からは何も選べないので、dp[0][0]=0とする(起点)
  dp[0][0]=0;
  
  rep(i,n){ // 品物i
    for(int j=0; j<=MAX_V*MAX_N; ++j){ // 品物の価値j
      if(j<v[i]){ // 入らない
        dp[i+1][j]=dp[i][j];
      }else{ // 入る
        // ”i-1番目までの品物から価値がjとなるように選んだ重さの総和”
        // VS
        // ”i番目の品物と、i-1番目までの品物から価値がj-v[i]となるように選んだ重さの総和、の和”
        dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
      }
    }
  }
  
  // 重さ総和がW以下の中で、最大の価値iを格納する
  int ans=0;
  for(int i=0; i<=MAX_V*MAX_N; ++i) if(dp[n][i]<=W) ans=i;
  
  cout(ans);
}