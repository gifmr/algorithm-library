/**
 * Trie-Tree
 * 
 * @see [https://pione.hatenablog.com/entry/2021/02/09/223409]
 * 
 * @param char_size Trie木で扱う文字種数
 * @param base Trieで扱う文字種のうちの先頭
 */
template <int char_size = 26, int base = 'a'>
class Trie {
private:
  struct Node {
    int common;
    vector<int> next;
    vector<int> accept;
    Node() : common(0), next(vector<int>(char_size, -1)){};
  };
  vector<Node> nodes;

public:
  Trie() : nodes(vector<Node>(1)){};

  void insert(const string &s, int string_id = 0) {
    nodes[0].common++;
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      int char_id = (int)(s[i] - base);
      if (nodes[last].next[char_id] == -1) {
        nodes.push_back(Node());
        nodes[last].next[char_id] = nodes.size() - 1;
        last = nodes.size() - 1;
      } else {
        last = nodes[last].next[char_id];
      }
      nodes[last].common++;
    }
    nodes[last].accept.push_back(string_id);
  }

  bool search(const string &s) {
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      int char_id = (int)(s[i] - base);
      if (nodes[last].next[char_id] == -1)
        return false;
      else
        last = nodes[last].next[char_id];
    }
    return nodes[last].accept.size() > 0 ? true : false;
  }

  bool search_prefix(const string &s) {
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      int char_id = (int)(s[i] - base);
      if (nodes[last].next[char_id] == -1)
        return false;
      else
        last = nodes[last].next[char_id];
    }
    return true;
  }

  int count_words() { return nodes[0].common; }

  int size() { return nodes.size(); }
};