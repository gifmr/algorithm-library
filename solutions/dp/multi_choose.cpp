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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 重複組み合わせ
// n種類の品物があり、i番目の品物はa[i]個ある.同じ品物同士を区別しないとき、m個を選ぶ組合せの総数を求め、そのmodの結果出力する
// O(nm)

int n; // 品物の種類
int m; // 選ぶ個数
int mod;

int a[1005];

// dp[i+1][j]:=i番目までの品物からj個選ぶ組合せの総数
// 以下の様に式変形が可能
// dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]
// これは、i番目までの品物からj個の組合せを数えるときに、a[i]を選ばない場合と、a[i]を選ぶ場合に分けて考えている
// (1) a[i]を選ばない場合
// a[i]を選ばないということは、a[i-1]まででj個を選ぶ組合せの総数となるため、その数はdp[i][j]
// (2) a[i]を選ぶ場合
// a[i]を選ぶということは、a[i]まででj-1個を選択し、残りの1個をa[i]を選ぶ場合と考えることができる
// ただし、a[i]<=j-1の時で、a[i-1]まででj-1-a[i]を選ぶ場合にはa[i]の個数がa[i]+1個となり、個数の制約に矛盾が生じる
// よって、a[i]を選ぶ場合の組合せの数は、a[i]まででj-1個を選択する組合せの数から、a[i-1]まででj-1-a[i]個を選択する組合せの数を引いた結果となる
// すなわち、dp[i+1][j-1]-dp[i][j-1-a[i]]
int dp[1005][1005];

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  cin>>n>>m;
  rep(i,n) cin>>a[i];
  cin>>mod;
  
  for(int i=0; i<=n; i++){
    dp[i][0]=1; // a[i]までのaから1つも選ばない方法を1通りとしている
  }
  rep(i,n){
    for(int j=1; j<=m; j++){
      if(j-1-a[i]>=0){
        dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]) % mod;
      }else{
        // j-1-a[i]<0 となる場合は、言い換えるとj-1個を全てa[i]としても、
        // 選択しないa[i]は1個以上存在するため、a[i]の個数がa[i]+1個となる矛盾は生じない
        dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]) % mod;
      }
    }
  }
  int ans=dp[n][m];
  cout(ans);
}