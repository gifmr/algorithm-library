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

// 個数制限付き部分和問題
// 解説: https://hfuji.hatenablog.jp/entry/2015/11/25/172524

// dp[i+1][j]:=i番目までの数のグループからjを作る際、余る最大のa[i]の個数. 作れない場合は-1とする
// 言い換えると、dp[i+1][j]>=0とならば、i番目までの数のグループからjを作ることができることを意味する
// 計算量: O(n*K)

// dpへの代入の場合分け
// (1) jがi-1番目までの数のグループで作ることができるなら、dp[i+1][j]=m[i]
// (2) (1)ではなく、j-a[i]を作ることができて、a[i]が余っている場合、dp[i+1][j]=dp[i+1][j-a[i]]-1
// (3) (1)でも(2)でもない. つまり、i番目までの数のグループでは作ることができない場合、dp[i+1][j]=-1

// 上記の定義は正しいが、配列のサイズが大きい場合は使えない
// そのため、dp[j]として配列を再利用する. 
// dp[i][j]の値を、dp[i+1][j]に上書きしても問題は生じない
// なぜなら、dp[i][j]がdp[i+1][j]に上書きされるタイミングは、(1)の場合のみで、(2)の場合は必ず(1)の場合が見つかった後にしか行われない
// そのため、dp[j]で値が更新される過程は以下のようになる
// [1] a[i-1]までの数によって作られる数をm[i]に初期化する
// [2] dp[j-a[i]]>=0となる場合、dp[j]=dp[j-a[i]]-1


int n;        // 使用の数の種類
int K;        // 作りたい数
int a[1005];  // 使用する数
int m[1005];  // 各数の使える個数

int dp[100005];

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  cin>>n>>K;
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>m[i];
  
  memset(dp, -1, sizeof(dp)); // 全てを-1に初期化
  dp[0]=0; // dp初期化. 0個の整数の和は0とみなせる
  
  rep(i,n){
    for(int j=0; j<=K; j++){
      if(dp[j]>=0){
        dp[j]=m[i];
      }else if(dp[j-a[i]]>0 && j-a[i]>=0){ // j-a[i]>=0としているのは、a[i]が作りたい数jより大きい値でないかを判定している
        dp[j]=dp[j-a[i]]-1;
      }else{
        dp[j]=-1;
      }
    }
  }
  
  string ans = "No";
  if(dp[K]>=0) ans = "Yes";
  cout << ans << endl;
}