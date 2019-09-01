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


// AtCoder Beginner Contest 139 E - League
// https://atcoder.jp/contests/abc139/tasks/abc139_e
// 1試合を頂点としてグラフと見ることで、DAGの最長経路が求める日数となる
// 閉路がある場合は試合の順序の制約を満たさないことを意味するので、この場合は-1を出力する


const int MAXN=1005; // 選手数
const int MAXV=MAXN*(MAXN-1)/2; // 頂点の最大数(試合数)

vi to[MAXV]; // DAGの辺を格納する. これはvector<int>型の配列

// 引数i, jは選手で、試合IDを取得する
int id[MAXN][MAXN];
int toId(int i, int j){
  if(i > j) swap(i,j); // i>jはi<jと同一の試合と判定する
  return id[i][j];
}

bool visited[MAXV]; // 頂点が探索済みかを判定する. dpのメモ化用
bool calculated[MAXV]; // 頂点が計算を終えたものかを判定する. 閉路検出用
int dp[MAXV]; // vからスタートした時の最長経路
int dfs(int v){
  if(visited[v]) {
    if(!calculated[v]) return -1; // 閉路判定
    return dp[v];
  }
  visited[v] = true;
  dp[v] = 1; // 頂点の個数
  for(int u: to[v]){ // 接続する頂点がない場合、ループを抜ける
    int res = dfs(u);
    if(res == -1) return -1;
    dp[v] = max(dp[v], res+1);
  }
  calculated[v] = true; // dfsの末端で計算終了判定を行う
  return dp[v];
}

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  int n;
  cin>>n;
  
  vvi a(n, vi(n-1));
  rep(i, n){
    rep(j, n-1){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  
  int V=0; // 頂点数
  rep(i, n) rep(j, n) { // 各頂点(試合)に対してIDを割り振る
    if(i < j){
      id[i][j] = V++;
    }
  }
  
  rep(i, n) {
    rep(j, n-1) {
      a[i][j] = toId(i,a[i][j]); // a[i][j]つまり対戦相手を頂点IDに書き換える
    }
    rep(j, n-2) {
      to[a[i][j+1]].push_back(a[i][j]); // グラフの作成
    }
  }
  int ans = 0;
  rep(i, V){
    int res = dfs(i);
    if(res == -1){
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}