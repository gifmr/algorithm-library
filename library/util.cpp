#include <bits/stdc++.h>
using namespace std;

// a<b ならば、aをbに更新. boolにより更新判定が可能
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

// a>b ならば、aをbに更新. boolにより更新判定が可能
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 整数型vectorの要素を列挙
void printv(vector<long long> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i != v.size())
      cout << " ";
  }
  cout << endl;
}

// 整数型vectorの要素の総和を返却
long long vtotal(vector<long long> &v)
{
  int total = 0;
  for (int i = 0; i < v.size(); i++)
    total += v[i];
  return total;
}