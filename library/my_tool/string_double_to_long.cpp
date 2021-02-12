/// @see [https://pione.hatenablog.com/entry/2021/02/07/124449]
long long string_double_to_long(const string &s, const int p) {
  if (s.find('.') == string::npos) {
    long long p = 1;
    while (p--)
      p *= 10;
    return stoll(s) * p;
  } else {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '.') {
        int tail_len = n - i - 1;
        int loop_cnt = p - tail_len;
        auto t = s.substr(0, i) + s.substr(i + 1, n);
        while (loop_cnt--)
          t.push_back('0');
        return stoll(t);
      }
    }
  }
}