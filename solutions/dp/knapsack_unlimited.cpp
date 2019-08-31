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

// AOJ
// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_C

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
  
  int n,W;
  int v[100],w[100];
  
  // input
  cin>>n>>W;
  rep(i,n){
    cin>>v[i]>>w[i];
  }
  
  // solution
  
  // dp[i+1][j]:=i番目の品物の中から重さの総和がj以下となるように選んだ時の価値の総和の最大値
  // ただし、同じ品物を選択可能である
  int dp[101][10001]={0};
  
  rep(i,n){ // 品物i
    for(int j=0;j<=W;++j){ // ナップサックの容量j
      if(j<w[i]){ // 入らない
        dp[i+1][j]=dp[i][j];
      }else{ // 入る
        // ”i-1番目までの品物から重さj以下となるように選んだ価値の総和”
        // VS
        // ”i番目の品物と、重複を許しi番目までの品物から重さがj-w[i]以下となるように選んだ価値の総和、の和”
        
        // 普通のナップサックと異なり、遷移前で品物iを含んでいる可能性があるため(同一の品物で2周目以降)、「品物iまでから重さj-w[i]以下で」となる
        dp[i+1][j]=max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
      }
    }
  }
  
  cout(dp[n][W]);
}