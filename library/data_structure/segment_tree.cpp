/// @see [https://pione.hatenablog.com/entry/2021/01/24/023953]
template <class T> class SegTree {
private:
  T e;
  int w;
  function<T(T, T)> op;
  vector<T> tree;

public:
  SegTree(const int n, const T _e, const function<T(T, T)> _op) {
    e = _e;
    w = 1;
    while (w < n)
      w <<= 1;
    tree = vector<T>(w * 2 - 1, e);
    op = _op;
  }

  void update(int i, const T v) {
    i = w - 1 + i;
    tree[i] = v;
    if (i)
      while (true) {
        i = (i - 1) / 2;
        int l = (i + 1) * 2 - 1, r = (i + 1) * 2;
        tree[i] = op(tree[l], tree[r]);
        if (i == 0)
          break;
      }
  }

  T query(const int L, const int R, int l = -1, int r = -1, int v = 0) {
    if (l == -1)
      l = 0;
    if (r == -1)
      r = w;

    if (L <= l and r <= R)
      return tree[v];
    else if (r <= L or R <= l)
      return e;
    else {
      T x = query(L, R, l, (l + r) / 2, (v + 1) * 2 - 1);
      T y = query(L, R, (l + r) / 2, r, (v + 1) * 2);
      return op(x, y);
    }
  }
};