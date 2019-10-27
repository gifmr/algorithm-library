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
// #define int long long
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;
 
const int MOD = 1e9+7;
const int INF = 1e9;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }
 
// yukicoder No.914 Omiyage
// https://yukicoder.me/problems/no/914
// 解説: https://ningenme.hatenablog.com/entry/2019/10/25/232215#A---Omiyage
// 部分和dp
// dp[i][j] := i国までで1つずつお土産を買いj円使うことができるか
// O(N*M*K)
 
signed main()
{
  int n,m,K; cin>>n>>m>>K;
  vvi A(n,vi(m));
  rep(i,n) rep(j,m) cin>>A[i][j];
  
  vi dp(K+1,0);
  dp[0]=1;
  rep(i,n){
    vi tmp(K+1,0);
    rep(j,m){
      for(int k=0; k+A[i][j]<=K; k++){
        if(dp[k]) tmp[k+A[i][j]]=1; // 自国のお土産を買ってtrueになったk円を分けるためにtmpに保存
      }
    }
    dp=tmp;
  }
  for(int i=K; i>=0; i--){
    if(dp[i]){
      cout<<K-i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}