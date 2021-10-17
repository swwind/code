#include <bits/stdc++.h>
using namespace std;

#define N 5020

const int EPSILON = 0;

struct Edge {
  int to, type;
};

// WARNING: parse `()[]|+` and numbers only
struct NFA : public vector<vector<Edge>> {
  // regex buffer
  char buf[N];
  int n, now = 0;

  inline int create_node() {
    int id = size();
    push_back({});
    return id;
  }

  inline void insert_edge(int x, int y, int t) {
    at(x).push_back(Edge { y, t });
  }

  inline bool is(char c) {
    return now < n && buf[now] == c;
  }
  inline bool is_number() {
    return now < n && buf[now] >= '0' && buf[now] <= '9';
  }
  inline void expect(char c) {
    assert(now < n && buf[now ++] == c);
  }

  pair<int, int> parse_atom() {
    vector<char> vec;

    if (is_number()) {
      vec.push_back(buf[now ++]);
    } else {
      expect('[');
      while (is_number()) {
        vec.push_back(buf[now ++]);
      }
      expect(']');
    }

    int st = create_node();
    int ed = create_node();
    for (char c : vec) {
      insert_edge(st, ed, c);
    }
    return { st, ed };
  }

  pair<int, int> parse_regex() {
    pair<int, int> orr, cmb, reg;
    bool has_orr = false, has_cmb = false;

    while (true) {
      if (is_number() || is('[')) reg = parse_atom();
      else if (is('(') && ++ now) reg = parse_regex();
      else assert(false);

      if (is('+') && ++ now) insert_edge(reg.second, reg.first, EPSILON);
      while (is('+')) ++ now;

      if (!has_cmb) cmb = reg, has_cmb = true;
      else insert_edge(cmb.second, reg.first, EPSILON), cmb.second = reg.second;

      if (is('|') && ++ now) {
        if (!has_orr) {
          orr.first = create_node();
          orr.second = create_node();
          has_orr = true;
        }
        insert_edge(orr.first, cmb.first, EPSILON);
        insert_edge(cmb.second, orr.second, EPSILON);
        has_cmb = false;
      }

      if (now >= n || (is(')') && ++ now)) {
        assert(has_cmb);
        if (has_orr) {
          insert_edge(orr.first, cmb.first, EPSILON);
          insert_edge(cmb.second, orr.second, EPSILON);
          return orr;
        } else {
          return cmb;
        }
      }
    }
  }

  inline pair<int, int> initialize() {
    scanf("%s", buf);
    n = strlen(buf);
    return parse_regex();
  }

  void debug_print() {
    for (size_t i = 0; i < size(); ++ i) {
      for (Edge e : at(i)) {
        printf("%d ---(%d)--> %d\n", i, e.type, e.to);
      }
    }
  }
};

char s[N<<1];
int n;

int main() {
  NFA nfa = NFA();
  pair<int, int> pr = nfa.initialize();
  printf("st: %d, ed: %d\n", pr.first, pr.second);
  nfa.debug_print();

  return 0;
}