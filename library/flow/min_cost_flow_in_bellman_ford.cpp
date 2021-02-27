/// https://pione.hatenablog.com/entry/2021/02/28/062450
template <typename capacity_t, typename cost_t>
class MinCostFlow {
private:
  const cost_t INF = 1e9;
  struct Edge {
    int to, rev;
    capacity_t cap;
    cost_t cost;
    Edge(int to, int rev, capacity_t cap, cost_t cost)
        : to(to), rev(rev), cap(cap), cost(cost) {}
  };
  vector<vector<Edge>> G;
  vector<int> prev_v, prev_e;
  Edge& get_rev(Edge &edge) { return G[edge.to][edge.rev]; }

public:
  MinCostFlow(int n) {
    G.resize(n);
    prev_v.resize(n);
    prev_e.resize(n);
  }
  void add_edge(int from, int to, capacity_t cap, cost_t cost) {
    G[from].push_back(Edge(to, (int)G[to].size(), cap, cost));
    G[to].push_back(Edge(from, (int)G[from].size() - 1, 0, -cost));
  }
  
  cost_t get_min_flow_cost(int s, int t, capacity_t flow) {
    int n = G.size();
    cost_t res = 0;
    while (flow > 0) {
      vector<cost_t> dist(n, INF);
      dist[s] = 0;
      bool update = true;
      while (update) {
        update = false;
        for (int v = 0; v < n; v++) {
          if (dist[v] == INF) continue;
          for (int i = 0; i < G[v].size(); i++) {
            auto &edge = G[v][i];
            if (edge.cap > 0 and dist[edge.to] > dist[v] + edge.cost) {
              dist[edge.to] = dist[v] + edge.cost;
              prev_v[edge.to] = v;
              prev_e[edge.to] = i;
              update = true;
            }
          }
        }
      }
      if (dist[t] == INF) return -1;
      capacity_t d = flow;
      for (int v = t; v != s; v = prev_v[v]) {
        d = min(d, G[prev_v[v]][prev_e[v]].cap);
      }
      flow -= d;
      res += d * dist[t];
      for (int v = t; v != s; v = prev_v[v]) {
        G[prev_v[v]][prev_e[v]].cap -= d;
        get_rev(G[prev_v[v]][prev_e[v]]).cap += d;
      }
    }
    return res;
  }
};