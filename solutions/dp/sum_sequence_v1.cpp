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

// 個数制限付き部分和問題. 改善余地あり
// 解説1: https://hfuji.hatenablog.jp/entry/2015/11/25/172524
// 解説2: https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-3%E9%83%A8%E5%88%86%E5%92%8C%E5%95%8F%E9%A1%8C
// 計算量: O(K Σ[i] m[i])

// dp[i+1][j]:=i番目までの数のグループからjを作れるか
// 0<=k<=m[i] かつ k*a[i]<=j となるkを定義した時、
// dp[i+1][j]:=dp[i][j-k*a[i]]が存在することを意味する
// これは言い換えると、jからa[i]を引くことで、i-1までの数のグループで作れる数にできるか、を判定している


int n;        // 使用の数の種類
int K;        // 作りたい数
int a[1005];  // 使用する数
int m[1005];  // 各数の使える個数

bool dp[1005][1005];

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  cin>>n>>K;
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>m[i];
  
  memset(dp, 0, sizeof(dp)); // 全てをfalseに初期化
  dp[0][0]=true; // dp初期化. 0個の整数の和は0とみなせる
  
  rep(i,n){
    for(int j=0; j<=K; j++){
      for(int k=0; k<=m[i] && k*a[i]<=j; k++){
        dp[i+1][j] |= dp[i][j-k*a[i]];
      }
    }
  }
  
  string ans = "No";
  if(dp[n][K]) ans = "Yes";
  cout << ans << endl;
}