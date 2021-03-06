struct StronglyConnectedComponents {
  vector<vector<int>> G, rG;
  vector<int> order, component;
  vector<bool> used;
  void dfs(int v) {
    used[v] = 1;
    for (auto nv : G[v]) {
      if (!used[nv]) dfs(nv);
    }
    order.push_back(v);
  }
  void rdfs(int v, int k) {
    component[v] = k;
    for (auto nv : rG[v]) {
      if (component[nv] < 0) rdfs(nv, k);
    }
  }

  StronglyConnectedComponents(vector<vector<int>> &_G) {
    int n = _G.size();
    G = _G;
    rG.resize(n);
    component.assign(n, -1);
    used.resize(n);
    for (int v = 0; v < n; v++) {
      for (auto nv : G[v]) rG[nv].push_back(v);
    }
    for (int v = 0; v < n; v++) if (!used[v]) dfs(v);
    int k = 0;
    reverse(order.begin(), order.end());
    for (auto v : order) if (component[v] == -1) rdfs(v, k), k++;
  }

  bool is_same(int u, int v) { return component[u] == component[v]; }
};