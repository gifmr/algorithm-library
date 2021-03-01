/// @see[https://pione.hatenablog.com/entry/2021/02/26/003115]
template <class T>
class FordFulkerson {
private:
  const T INF = 1e9;
  
  struct Edge {
    int to, from, rev; T cap;
    Edge(int from, int to, int rev, T cap) : to(to), from(from), rev(rev), cap(cap) {}
  };
  
  vector<vector<Edge>> G;
  
  Edge &get_rev(Edge &edge) { return G[edge.to][edge.rev]; }
  
  vector<bool> used;
  
  T dfs(int v, int t, T flow) {
    if (v == t) return flow;
    used[v] = true;
    for (auto &e : G[v]) {
      if (used[e.to] or e.cap <= 0) continue;
      T d = dfs(e.to, t, min(flow, e.cap));
      if (d > 0) {
        e.cap -= d;
        get_rev(e).cap += d;
        return d;
      }
    }
    return 0;
  }

public:
  FordFulkerson(int n) { G.resize(n); }
  
  void add_edge(int from, int to, T cap) {
    G[from].push_back(Edge(from, to, (int)G[to].size(), cap));
    G[to].push_back(Edge(to, from, (int)G[from].size() - 1, 0));
  }
  
  T get_max_flow(int s, int t) {
    int n = G.size();
    T res = 0;
    while (true) {
      used.assign(n, false);
      T flow = dfs(s, t, INF);
      if (flow > 0) {
        res += flow;
      } else {
        return res;
      }
    }
    return 0;
  }
};