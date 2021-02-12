/// @see [https://pione.hatenablog.com/entry/2021/01/24/232508]
class UnionFind {
private:
  vector<int> Parent;

public:
  UnionFind(int N) { Parent = vector<int>(N, -1); }

  int root(int A) {
    if (Parent[A] < 0)
      return A;
    return Parent[A] = root(Parent[A]);
  }

  int size(int A) { return -Parent[root(A)]; }

  bool connect(int A, int B) {
    A = root(A);
    B = root(B);
    if (A == B) {
      return false;
    }
    if (size(A) < size(B))
      swap(A, B);
    Parent[A] += Parent[B];
    Parent[B] = A;
    return true;
  }

  bool isSame(int A, int B) { return root(A) == root(B); }
};