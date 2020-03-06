#include <bits/stdc++.h>
using namespace std;

// 素数判定 O(√n)
bool is_prime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

// 素数判定高速版 2の倍数を除外することで高速化
bool quick_is_prime(int n)
{
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;

  for (int i = 3; i * i <= n; i += 2)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

// 約数列挙 O(√n)
vector<int> divisor(int n)
{
  vector<int> res;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      res.push_back(i);
      if (i != n / i)
        res.push_back(n / i);
    }
  }
  return res;
}

// 素因数分解 O(√n)
map<int, int> prime_factor(int n)
{
  map<int, int> res;
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}

// 素因数の個数数え上げ
long long cnt_prime_factor(long long N)
{
  long long res = 0;
  for (ll i = 2; i * i <= N; i++)
  {
    if (N % i == 0)
    {
      res++;
      while (N % i == 0)
        N /= i;
    }
  }
  if (N != 1)
    res++;
}