class SuffixArray {
private:
  string s;
  int n, k;
  vector<int> suffix_array;
  vector<int> rank;
  void create_suffix_array() {
    for (int i = 0; i <= n; i++) {
      suffix_array[i] = i;
      rank[i] = i < n ? (int)s[i] : -1;
    }
    auto compare = [&](int a, int b) {
      if (rank[a] != rank[b]) return rank[a] < rank[b];
      else {
        auto rank_ak = a + k <= n ? rank[a + k] : -1;
        auto rank_bk = b + k <= n ? rank[b + k] : -1;
        return rank_ak < rank_bk;
      }
    };
    vector<int> tmp(n + 1);
    for (k = 1; k <= n; k *= 2) {
      sort(suffix_array.begin(), suffix_array.end(), compare);
      tmp[suffix_array[0]] = 0;
      for (int i = 1; i <= n; i++) {
        tmp[suffix_array[i]] = tmp[suffix_array[i - 1]] + (compare(suffix_array[i - 1], suffix_array[i]) ? 1 : 0);
      }
      for (int i = 0; i <= n; i++) {
        rank[i] = tmp[i];
      }
    }
  }

public:
  SuffixArray(const string &_s) {
    s = _s;
    n = _s.size();
    suffix_array.resize(n + 1);
    rank.resize(n + 1);
    create_suffix_array();
  }

  bool contains(const string &t) {
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      int index = suffix_array[mid];
      if (s.compare(index, t.size(), t) < 0) l = mid;
      else r = mid;
    }
    return s.compare(suffix_array[r], t.size(), t) == 0;
  }
};