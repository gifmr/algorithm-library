#include <bits/stdc++.h>
using namespace std;

struct BIT
{
  long long n;
  vector<long long> dat;

  void initialize(long long n_input) {
    n = n_input + 1;
    dat.resize(n + 1);
    for (int i = 0; i <= n; i++) dat[i] = 0;
  }

  long long sum(long long i) {
    long long s = 0;
    while (i >= 0) {
      s += dat[i];
      i = (i & (i + 1)) - 1;
    }
    return s;
  }

  long long sum_between(long long i, long long j) {
    return i <= j ? sum(j) - sum(i - 1) : 0;
  }

  void add(long long i, long long x) {
    while (i <= n) {
      dat[i] += x;
      i |= i + 1;
    }
  }
};