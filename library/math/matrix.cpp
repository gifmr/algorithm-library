// 行列演算
const ll MOD = 1e9+7;
#define mat vector<vector<int>>

/// 行列積
mat mat_mul(mat &a, mat &b) {
  mat res(a.size(), vector<int>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        (res[i][j] += a[i][k] * b[k][j]) %= MOD;
      }
    }
  }
  return res;
}

/// 行列累乗
mat mat_pow(mat a, long long n) {
  mat res(a.size(), vector<int>(a.size()));
  // 単位行列で初期化
  for (int i = 0; i < a.size(); i++)
    res[i][i] = 1;
  // 繰り返し二乗法
  while (n > 0) {
    if (n & 1) res = mat_mul(a, res);
    a = mat_mul(a, a);
    n >>= 1;
  }
  return res;
}