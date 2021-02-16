/// @see [https://pione.hatenablog.com/entry/2021/02/11/013813]
struct Eratosthenes {
  vector<bool> is_prime;
  vector<int> primes;
  vector<int> min_prime_factor;

  Eratosthenes(const int n) {
    min_prime_factor.resize(n + 1);
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    min_prime_factor[0] = min_prime_factor[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (is_prime[i]) {
        for (int j = 2 * i; j <= n; j += i) {
          is_prime[j] = false;
          if (min_prime_factor[j] == 0)
            min_prime_factor[j] = i;
        }
        primes.push_back(i);
        min_prime_factor[i] = i;
      }
    }
  }

  set<int> get_prime_factors(int x) {
    set<int> s;
    while (x > 1) {
      s.insert(min_prime_factor[x]);
      x /= min_prime_factor[x];
    }
    return s;
  }

  map<int, int> get_prime_factor_and_cnt(int x) {
    map<int, int> mp;
    while (x > 1) {
      mp[min_prime_factor[x]]++;
      x /= min_prime_factor[x];
    }
    return mp;
  }
};