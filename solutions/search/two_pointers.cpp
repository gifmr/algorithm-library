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

// 尺取り法
// 2つのカーソルがあり、後ろのカーソルubがNの範囲で移動する
// O(N)

int main(){
  int n, s;
  cin>>n>>s;
  vi v(n);
  rep(i,n) cin>>v[i];
  int lb = 0, ub = 0, sum = 0;
  
  int ans=INF;
  // 後ろのカーソル(ub)がnになるまでループする
  for(;;){
    // ubがn(配列の外にでる)か、sumがs以上になるとループを脱出する
    // sumがs以上になる条件でループを脱出した時、ubは条件を満たす範囲より1つ先にある
    while(ub < n && sum < s){
      sum += v[ub++];
    }
    
    if(sum < s) break;
    
    // ubはsum>=sを満たす範囲の1つ先にあるため、ub-lbで連続部分列の長さとなる
    chmin(ans, ub - lb);
    sum -= v[lb++];
  }
  // 解が存在しない場合
  if(ans == INF) ans = 0;
  
  cout<<ans<<endl;
}