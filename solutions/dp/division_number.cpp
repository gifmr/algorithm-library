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

// 分割数
// 参考: http://drken1215.hatenablog.com/entry/2018/01/16/222843
// O(nk)

// n個の互いに区別できない品物を、k個以下に分割する方法の総数を求める
// これは言い換えると、自然数nをk個の0以上の整数の和で表す場合の数となる
// 分割数の場合の数を数え上げるには、0を含む分割の仕方と、0を含まない分割の仕方に場合分けして考えることが有効である
// 自然数nのk個の0以上の整数の和で表す場合の数をP(n, k)とすると、分割分割数の性質には以下の様なものがある
// (1) k個の1以上の整数への分割数(0を含まない分割数)はP(n-k, k)
// さらに上記とは独立した場合として、0を含む分割の仕方は以下の様になる
// (2) k分割のうち1個を0を格納する箱として固定すると考えると、0を含む分割数は、P(n, k-1)
// (1), (2)がdpの漸化式となる

int n; // 分割の対象となる整数
int k; // 分割数
int m; // mod

// dp[i][j]:=自然数jのi分割の総数
// dp[i][j-i]:=(1)より0を含まない分割数
// dp[i-1][j]:=(2)より0を含む分割数
int dp[1005][1005];

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  cin>>n>>k>>m;
  
  dp[0][0]=1; // 0分割を1通りとして定義
  
  reps(i, k){ // 分割数
    for(int j=0; j<=n; j++){ // 分割する整数
    
      if(j-i>=0){ // 分割数iが整数j以下の場合は、0を含まない分割の場合が有り得る
        dp[i][j]=(dp[i][j-i]+dp[i-1][j]) % m;
      
      }else{ // 分割数i > 整数j の場合、0を含まない分割の仕方は有り得ない
        dp[i][j]=dp[i-1][j]; // mod処理済みの値を再代入するため、%mは不要
      }
      
    }
  }
  
  int ans=dp[k][n];
  cout(ans);
}