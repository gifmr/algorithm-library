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

// 最長増加部分列問題 方針2
// 解説: https://qiita.com/python_walker/items/d1e2be789f6e7a0851e5
// O(n log n)


int n; // 数列の長さ
int a[1005]; // 数列の数. 最大長を1000と仮定する

// dp[i]:=長さがi+1であるような増加部分列における最終要素の最終値
// dpテーブルには、aの要素の値が入れられていき、その前後関係は単調増加となる
// なぜなら、dpテーブルに数列の値を入れていく様子は以下の様になるため
// (1) j<iのとき、dp[j]<a[i]であるなら、dp[j+1]=a[i]となる
// (2) j<iのとき、a[i]<=dp[j]であるなら、a[i]<=dp[m]となる最小のdp[m]にa[i]を代入する
// これは言い換えると、a[i]<=dp[j]ならば、a[j]までの数とa[i]を使い、長さがmであり最終要素がdp[m]以下の増加部分列を作ることができるということ
int dp[1005];

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  cin>>n;
  rep(i,n) cin>>a[i];
  
  fill(dp, dp+n, INF);
  
  rep(i,n){
    // lower_bound(a, a+n, k)は、ソートされた配列からa[i]>=kとなる、最小のa[i]のポインタを返す
    // これは言い換えると、kより大きい直近のa[i]のポインタを返すという事
    *lower_bound(dp, dp+n, a[i]) = a[i];
  }
  // dp配列の中でINFではない最大の添え字をansに格納している
  // lower_boundで返されるのはポインタのため、添え字に変換するためにdpを減算している
  // dp[0] - dp = 1となるため、添え字の値をLISに変換する際に+1をする必要はない
  int ans = lower_bound(dp, dp+n, INF) - dp;
  cout(ans);
}