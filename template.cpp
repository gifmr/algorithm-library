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
using ul = unsigned long;

typedef long long ll;

template<class T, class C> void chmax(T& a, C b){ a>b?:a=b; }
template<class T, class C> void chmin(T& a, C b){ a<b?:a=b; }

const int mod=1e9+7;

struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};

mint c[4005][4005];
void init() {
  c[0][0] = 1;
  for (int i = 0; i <= 4000; i++) {
    for (int j = 0; j <= i; j++) {
      c[i+1][j] += c[i][j];
      c[i+1][j+1] += c[i][j];
    }
  }
}
mint comb(int n, int k) {
  return c[n][k];
}

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

map<ll, ll> primeFact(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n]++;
  return res;
}

int main()
{
  cin.tie( 0 );
  ios::sync_with_stdio( false );
	
  //init();

  return 0;
}