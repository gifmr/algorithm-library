#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define REPS(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define RREP(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define RREPS(i, n) for (int i = ((int)(n)); i > 0; i--)
#define IREP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define IREPS(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define FOR(e, c) for (auto &e : c)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RVISORT(v) sort(v.begin(), v.end(), greater<int>());
#define ALL(v) v.begin(), v.end()
 
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using ll = long long;
 
typedef long long ll;
 
template<class T, class C> void chmax(T& a, C b){ a>b?:a=b; }
template<class T, class C> void chmin(T& a, C b){ a<b?:a=b; }

int main()
{
    VI v(5);
    int k;
    cin >>v[0]>>v[1]>>v[2]>>v[3]>>v[4]>>k;
    
    string ans="Yay!";
    REP(i,v.size()-1){
        for(int j=i+1;j<v.size();j++){
            if(v[j]-v[i]>k) ans=":(";
        }
    }

    cout << ans << endl;
    return 0;
}