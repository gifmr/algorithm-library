/// @see [https://pione.hatenablog.com/entry/2021/01/24/042113]
class LCA {
private:
  int root;
  int k;
  vector<vector<int>> dp;
  vector<int> depth;

public:
  LCA(const vector<vector<int>> &_G, const int _root = 0) {
    int n = _G.size();
    root = _root;
    k = 1;
    int nibeki = 2;
    while (nibeki < n) {
      nibeki <<= 1;
      k++;
    }
    dp = vector<vector<int>>(k + 1, vector<int>(n, -1));
    depth.resize(n);
    function<void(int, int)> _dfs = [&](int v, int p) {
      dp[0][v] = p;
      for (auto nv : _G[v]) {
        if (nv == p)
          continue;
        depth[nv] = depth[v] + 1;
        _dfs(nv, v);
      }
    };
    _dfs(root, -1);
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == -1)
          continue;
        dp[i + 1][j] = dp[i][dp[i][j]];
      }
    }
  }

  int get(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);
    if (depth[u] != depth[v]) {
      long long d = depth[u] - depth[v];
      for (int i = 0; i < k; i++)
        if ((d >> i) & 1)
          u = dp[i][u];
    }
    if (u == v)
      return u;

    for (int i = k; i >= 0; i--) {
      if (dp[i][u] != dp[i][v]) {
        u = dp[i][u], v = dp[i][v];
      }
    }
    return dp[0][u];
  }

  int get_distance(const int u, const int v) {
    int lca = get(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
  }
};