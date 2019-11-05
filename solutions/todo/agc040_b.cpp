#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// https://atcoder.jp/contests/agc040/tasks/agc040_b
// 解説: https://betrue12.hateblo.jp/entry/2019/11/04/051835

// TODO: 実装を完了させる
// 最小の右端を持つ区間と 最大の左端を持つ区間を同一のグループにする場合と分ける場合の最大値を比較すればよい
// 実装が複雑

// 最小の右端を持つ区間をR, 最大の左端を持つ区間をLとする

signed main()
{
  int n; cin>>n;
  vector<pair<int,int>> lr(n);
  // 最小の右端の値, 最大の左端の値
  int minr=1e9+1; int maxl=-1;
  rep(i,n){
    int l,r; cin>>l>>r;
    r++; // 半開区間として扱う
    lr.push_back(make_pair(l,r));
    chmin(minr, r);
    chmax(maxl, l);
  }
  
  if(n==2){
    cout<<lr[0].first+lr[0].second+lr[1].first+lr[1].second<<endl;
    return 0;
  }
  
  sort(lr.begin(),lr.end());
  
  
  // L,Rを同じグループとして扱う
  
  // L,Rを別のグループとして扱う
  
}