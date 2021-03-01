/// @see[https://pione.hatenablog.com/entry/2021/02/27/061552]
template <class T>
class Dinic {
private:
  const int INF = 1e9;
  vector<int> level, itr;

  struct Edge {
    int to, rev; T cap;
    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap){};
  };

  vector<vector<Edge>> G;

  Edge &get_rev(Edge &edge) { return G[edge.to][edge.rev]; }

  void bfs(int s) {
    level.assign(G.size(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto &e : G[v]) {
        if (level[e.to] < 0 and e.cap > 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  T dfs(int v, int t, T flow) {
    if (v == t) return flow;
    for (int &i = itr[v]; i < G[v].size(); i++) {
      auto &edge = G[v][i];
      if (level[v] < level[edge.to] and edge.cap > 0) {
        auto f = dfs(edge.to, t, min(flow, edge.cap));
        if (f > 0) {
          edge.cap -= f;
          get_rev(edge).cap += f;
          return f;
        }
      }
    }
    return 0;
  }

public:
  Dinic(int n) { G.resize(n); }

  void add_edge(int from, int to, T cap) {
    G[from].push_back(Edge(to, (int)G[to].size(), cap));
    G[to].push_back(Edge(from, (int)G[from].size() - 1, 0));
  }

  T get_max_flow(int s, int t) {
    int n = G.size();
    T res = 0;
    while (true) {
      itr.assign(n, 0);
      bfs(s);
      if (level[t] < 0) break;
      while (true) {
        T flow = dfs(s, t, INF);
        if (flow > 0) res += flow;
        else break;
      }
    }
    return res;
  }
};