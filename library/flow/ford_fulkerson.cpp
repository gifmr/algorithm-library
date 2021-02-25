template <class T>
struct Edge {
  int to, from, rev;
  T cap;
  Edge(int from, int to, int rev, T cap)
      : to(to), from(from), rev(rev), cap(cap) {}
};

template <class T>
struct Graph {
  vector<vector<Edge<T>>> G;
  vector<Edge<T>> &operator[](int i) { return G[i]; }
  const size_t size() const { return G.size(); }
  Graph(int n) : G(n) {}
  void add_edge(int from, int to, T cap) {
    G[from].push_back(Edge<T>(from, to, (int)G[to].size(), cap));
    G[to].push_back(Edge<T>(to, from, (int)G[from].size() - 1, 0));
  }
  Edge<T> &get_rev(Edge<T> &edge) { return G[edge.to][edge.rev]; }
};

/// https://pione.hatenablog.com/entry/2021/02/26/003115
template <class T>
class FordFulkerson {
  const T INF = 1e9;

private:
  vector<bool> used;
  T dfs(Graph<T> &G, int v, int t, T flow) {
    if (v == t)
      return flow;
    used[v] = true;
    for (auto &e : G[v]) {
      if (used[e.to] or e.cap <= 0)
        continue;
      T d = dfs(G, e.to, t, min(flow, e.cap));
      if (d > 0) {
        e.cap -= d;
        G.get_rev(e).cap += d;
        return d;
      }
    }
    return 0;
  }

public:
  FordFulkerson() {}
  T max_flow(Graph<T> &G, int s, int t) {
    int n = G.size();
    T res = 0;
    while (true) {
      used.assign(n, false);
      T flow = dfs(G, s, t, INF);
      if (flow > 0) {
        res += flow;
      } else {
        return res;
      }
    }
    return 0;
  }
};