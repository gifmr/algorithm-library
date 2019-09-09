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

// 二部グラフ判定
// グラフの隣り合う頂点を別々の色で塗ることができるかを判定する. グラフの色彩問題と呼ばれる
// 参考: https://mathtrain.jp/graph
// 二部グラフとは頂点が2つのグループに分かれており、異なるグループの頂点間にのみ辺が引かれているグラフのこと

// input: 1行目に頂点数、2行目以降は各頂点について、隣接する頂点を入力する
// V
// k0 v00 v01 v02 ...
// k1 v10 v11 v12 ...
// .
// .

// sample

// 4 2 1 3 2 0 2 2 1 3 2 2 0
// result: Yes
// 3 2 1 2 2 0 2 2 0 1
// result: No

const int MAXV = 1005;
vi G[MAXV];       // グラフ
int V;            // 頂点数

int color[MAXV];  // 頂点iの色(1 or -1)

// 頂点に色を塗る. v: vertex, c: color
bool dfs(int v, int c){
  color[v] = c; // 頂点vをcで塗る
  rep(i, G[v].size()){
    // 隣接する頂点が既に塗られている場合. 自身と同じ色ならfalse
    if(color[G[v][i]] == c) return false;
    // 隣接する頂点の色が塗られていない場合. 自身と違う色で塗れなければfalse
    if(color[G[v][i]] == 0 && !dfs(G[v][i], c * -1)) return false;
  }
  // ここは全ての頂点の塗れた場合にのみ通る
  return true;
}

int main(){
  
  // input
  
  cin >> V;
  rep(i, V){
    int k; cin >> k;
    rep(j, k){
      int e; cin >> e;
      G[i].push_back(e);
    }
  }
  
  // solution
  
  rep(i, V){ // グラフが連結である場合このループは不要で、一度dfsを呼び出すだけで良い
    if(color[i] == 0){
      if(!dfs(i, 1)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}