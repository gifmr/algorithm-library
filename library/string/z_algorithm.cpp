/// @see [https://pione.hatenablog.com/entry/2021/01/30/034016]
vector<int> Z;

int z_algorithm(const string &s) {
  int n = s.size();
  Z.clear();
  Z.resize(n);

  Z[0] = n;
  int i = 1, j = 0;
  while (i < n) {
    while (i + j < n and s[j] == s[i + j])
      j++;
    Z[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (i + k < n and k + Z[k] < j) {
      Z[i + k] = Z[k];
      k++;
    }
    i += k;
    j -= k;
  }

  return *max_element(Z.begin(), Z.end());
}