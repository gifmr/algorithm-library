/// @see [https://pione.hatenablog.com/entry/2021/01/24/232508]
class UnionFind {
private:
  vector<int> parent;

public:
  UnionFind(int n) { parent = vector<int>(n, -1); }

  int root(int a) {
    if (parent[a] < 0)
      return a;
    return parent[a] = root(parent[a]);
  }

  int size(int a) { return -parent[root(a)]; }

  bool connect(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) {
      return false;
    }
    if (size(a) < size(b))
      swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
    return true;
  }

  bool is_same(int a, int b) { return root(a) == root(b); }
};