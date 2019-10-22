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
// #define int long long
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
 
// ABC143 D - Triangles
// https://atcoder.jp/contests/abc143/tasks/abc143_d
// 3つ以上の辺が与えられるのでその中で作ることができる3角形の種類を求める
// a < b < c であるなら、 a + b > c だけを証明できれば良いため、まず辺をソートする
// N=3*10^3なので、3重ループだとTLEになる可能性があるので上記のcとなる辺は二分探索で求める
// lower_bound 参考: https://cpprefjp.github.io/reference/algorithm/lower_bound.html

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  int n;
  cin>>n;
  vi L(n);
  rep(i,n) cin>>L[i];
  
  // 辺をソートする
  vsort(L);
  
  int ans=0;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      int sum = L[i]+L[j];
      // sum は a + b を意味する. lower_bound で sum 以上で最小の値が格納されるイテレータを返す
      // つまり j+1 から、この辺より前のインデックスまでに3角形を成立させる最後の辺が格納されていることになる
      int r = lower_bound(L.begin(), L.end(), sum) - L.begin();
      int l = j+1;
      // c = [l,r) つまり r-(l-1)-1=r-l
      ans += r-l;
    }
  }
  cout(ans);
}