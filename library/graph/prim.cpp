/// @see [https://pione.hatenablog.com/entry/2021/01/24/231352]
class Prim {
private:
  long long cost = 0;
  vector<bool> used;

public:
  Prim(const vector<vector<pair<int, long long>>> &G, const int root = 0) {
    int n = G.size();
    used.resize(n);
    used[root] = 1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        q;
    for (auto p : G[root]) {
      int v = p.first;
      long long c = p.second;
      if (!used[v]) {
        q.emplace(c, v);
      }
    }
    while (!q.empty()) {
      int v;
      long long c;
      tie(c, v) = q.top();
      q.pop();
      if (!used[v]) {
        used[v] = 1;
        cost += c;
        for (auto p : G[v]) {
          int nv = p.first;
          long long nc = p.second;
          if (!used[nv]) {
            q.emplace(nc, nv);
          }
        }
      }
    }
  }

  long long get() { return cost; }
};