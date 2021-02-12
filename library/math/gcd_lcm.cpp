long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long ngcd(vector<long long> &a) {
  long long res = a[0];
  for (long long i = 1; i < a.size() && res != 1; i++)
    res = gcd(a[i], res);
  return res;
}

long long nlcm(vector<long long> &a) {
  long long res = a[0];
  for (long long i = 1; i < a.size(); i++)
    res = lcm(a[i], res);
  return res;
}