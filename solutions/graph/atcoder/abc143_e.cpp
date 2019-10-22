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
#define int long long
#define PI (acos(-1))
 
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
 
// ABC 143 E - Travel by Car
// https://atcoder.jp/contests/abc143/tasks/abc143_e
// ワーシャルフロイドで全点対最短路を求める → dist[i][j]<=Lならコスト1の辺があるとして新しいグラフを構築する → 新しいグラフに対してワーシャルフロイドを適用
 
signed main()
{
  ll n,m,l;
  cin>>n>>m>>l;
  vector<vll> d(n, vll(n, INF));
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c;
    a--;b--;
    d[a][b]=d[b][a]=c;
  }
  
  ll q;
  cin>>q;
  vll S(q), T(q);
  rep(i,q){
    ll s,t;
    cin>>s>>t;
    S[i]=s-1;
    T[i]=t-1;
  }
  
  // ワーシャルフロイドで全点対最短路を求める
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
  
  // dist[i][j]<=Lならコスト1の辺があるとして新しいグラフを構築する
  vector<vll> d2(n, vll(n, INF));
  for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j){
        if(d[i][j] <= l) d2[i][j] = 1;
      }
  
  // 新しいグラフに対してワーシャルフロイドを適用
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
          d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
        }
  
  // d2[S[i]][T[i]]==INF ならば辺は存在しないため移動不可、辺が存在するなら始まりに通る辺は燃料の補給は必要ないので ans-1 となる
  rep(i,q){
    int ans = d2[S[i]][T[i]];
    if(ans==INF){
      cout<<-1<<endl;
    }else{
      cout<<ans-1<<endl;
    }
  }
  
}