/// @see [https://pione.hatenablog.com/entry/2021/01/24/231352]
class Kruskal {
private:
  long long cost = 0;

public:
  Kruskal(const vector<vector<pair<int, long long>>> &G) {
    int n = G.size();
    vector<tuple<long long, int, int>> V;
    for (int i = 0; i < n; i++) {
      for (auto p : G[i]) {
        int v = p.first, c = p.second;
        V.emplace_back(c, v, i);
      }
    }

    sort(V.begin(), V.end());

    UnionFind uf = UnionFind(n);
    for (auto e : V) {
      long long c;
      int u, v;
      tie(c, u, v) = e;
      if (!uf.is_same(u, v)) {
        cost += c;
        uf.connect(u, v);
      }
    }
  }

  long long get() { return cost; }
};