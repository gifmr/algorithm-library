/// @see [https://pione.hatenablog.com/entry/2021/02/12/201223]
struct EulerianTrail {
  vector<int> order;

  EulerianTrail(vector<vector<int>> &G, int root = 0) {
    int n = G.size();
    order.resize(n);
    int cur = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
      order[v] = cur;
      cur++;
      for (auto nv : G[v]) {
        dfs(nv, v);
      }
    };
    dfs(root, -1);
  }
}