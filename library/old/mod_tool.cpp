#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long mod_pow(long long x, long long n){
	if(n == 0) return 1;
	long long res = mod_pow(x*x % MOD, n / 2);
	if(n & 1) res = res*x % MOD;
	return res;
}

long long mod_inv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}