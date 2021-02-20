/// 素数判定 O(√n)
bool is_prime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

/// 素数判定高速版 2の倍数を除外することで高速化
bool quick_is_prime(int n) {
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;

  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

/// 素因数分解 O(√n)
map<int, int> prime_factor(long long n) {
  map<int, int> res;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}