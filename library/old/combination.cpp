#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long rui(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b & 1)
      ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}

long long comb(long long a, long long b){
  long long ans = 1;
  for (long long i = a; i > a - b; i--){
    ans = ans * i % MOD;
  }
  for (long long i = 1; i <= b; i++){
    ans = (ans * rui(i, MOD - 2)) % MOD;
  }
  return ans;
}