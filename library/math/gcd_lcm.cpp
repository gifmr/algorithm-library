long long _gcd(long long a, long long b) { return b ? _gcd(b, (a%b+b)%b) : a; }

long long _lcm(long long a, long long b) { return a / _gcd(a, b) * b; }

long long ngcd(vector<long long> &a) {
  long long res = a[0];
  for (long long i = 1; i < a.size() && res != 1; i++)
    res = _gcd(a[i], res);
  return res;
}

long long nlcm(vector<long long> &a) {
  long long res = a[0];
  for (long long i = 1; i < a.size(); i++)
    res = _lcm(a[i], res);
  return res;
}