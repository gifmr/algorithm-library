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

// 最長増加部分列問題

int n;        // 数列の長さ
int a[1005];  // 数列の数

// dp[i]:=最後がa[i]であるような最長増加部分列の長さ
int dp[100005];

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  cin>>n;
  rep(i, n) cin>>a[i];
  
  int ans=0;
  rep(i, n){
    dp[i]=1; // dp初期化. 増加部分列は少なくとも1以上になる
    rep(j, i){
      if(a[j]<a[i]){
        // a[j]<a[i]ならば、dp[i]は少なくともdp[j]+1の増加部分列になる
        // 言い換えるとdp[i]は、a[j]<a[i]を満たすjの中の最大のdp[j]の数+1の値となる
        // この計算を繰り返すと数列全体の最大増加部分列を求めることができる
        dp[i]=max(dp[i], dp[j]+1);
      }
    }
    ans=max(ans, dp[i]);
  }
  cout(ans);
}