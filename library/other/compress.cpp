/// @see[https://pione.hatenablog.com/entry/2021/03/03/060451]
template <typename T>
vector<T> compress(vector<T> &v1, vector<T> &v2) {
  vector<T> vals;
  int n = v1.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 1; j++) {
      vals.push_back(v1[i] + j);
      vals.push_back(v2[i] + j);
    }
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int i = 0; i < n; i++) {
    v1[i] = lower_bound(vals.begin(), vals.end(), v1[i]) - vals.begin();
    v2[i] = lower_bound(vals.begin(), vals.end(), v2[i]) - vals.begin();
  }
  return vals;
}