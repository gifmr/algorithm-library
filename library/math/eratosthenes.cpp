/// @see [https://pione.hatenablog.com/entry/2021/02/11/013813]
struct Eratosthenes {
  vector<bool> is_prime;
  vector<int> primes;
  vector<int> min_prime_can_divide_x;

  Eratosthenes(const int n) {
    min_prime_can_divide_x.resize(n + 1);
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    min_prime_can_divide_x[0] = min_prime_can_divide_x[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (is_prime[i]) {
        for (int j = 2 * i; j <= n; j += i) {
          is_prime[j] = false;
          if (min_prime_can_divide_x[j] == 0)
            min_prime_can_divide_x[j] = i;
        }
        primes.push_back(i);
        min_prime_can_divide_x[i] = i;
      }
    }
  }

  set<int> get_prime_factors(int x) {
    set<int> s;
    while (x > 1) {
      s.insert(min_prime_can_divide_x[x]);
      x /= min_prime_can_divide_x[x];
    }
    return s;
  }

  map<int, int> get_prime_factor_and_cnt(int x) {
    map<int, int> mp;
    while (x > 1) {
      mp[min_prime_can_divide_x[x]]++;
      x /= min_prime_can_divide_x[x];
    }
    return mp;
  }
};