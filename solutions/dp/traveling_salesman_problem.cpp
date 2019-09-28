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

// 巡回セールスマン問題(TSP: Traveling Salesman Problem)
// NP困難問題に属する (多項式時間の効率的なアルゴリズムが知られていない問題)
// 参考: https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#bit-dp
// O(n^2 * 2^n) ... (全探索の場合、O(n!))

// 既に訪れた頂点集合をSとして、
// dp[S][v] := 現在vにいる状態から残りの全てのの頂点をめぐって元の頂点に戻るパスの重みの総和の最小値

// 頂点vからは、まだ訪れていない頂点u∉Sへ移動できるため、以下の漸化式が成り立つ
// これは言い換えると、最後がvであるという制約の下で順序を最適化した時のSの中での最小コストという意味になる
// dp[V][0] = 0 (Vは全体集合)
// dp[S][v] = min(dp[S ∪ {u}][u] + dist[u][v]) | u ∉ S)
// 上記は、 dp[S][v] = min(dp[S - {v}][u] + dist[u][v] | u ∉ S) などとも書ける

// 上記の漸化式の初期値及び最終的な値は以下の様になる
// dp[1<<v][v] = 0
// min v dp[(1<<n) - 1][v]


/* 入力 */
int N;
int dist[21][21];

/* メモ再帰 */
int dp[(1<<20) + 1][21]; // dpテーブルは余裕をもったサイズにする
int rec(int bit, int v)
{
    // すでに探索済みだったらリターン
    if (dp[bit][v] != -1) return dp[bit][v];

    // 初期値
    if (bit == (1<<v)) {
        return dp[bit][v] = 0;
    }

    // 答えを格納する変数
    int res = INF;

    // bit の v を除いたもの. ~ はビットパターンを反転させる(つまり補数を求める)
    int prev_bit = bit & ~(1<<v);

    // v の手前のノードとして u を全探索
    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらダメ

        // 再帰的に探索
        if (res > rec(prev_bit, u) + dist[u][v]) {
            res = rec(prev_bit, u) + dist[u][v];
        }
    }

    return dp[bit][v] = res; // メモしながらリターン
}

int main()
{
    // 入力
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    // テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
    for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

    // 探索
    int res = INF;
    for (int v = 0; v < N; ++v) {
        if (res > rec((1<<N)-1, v)) {
            res = rec((1<<N)-1, v);
        }
    }
    cout << res << endl;
}