#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define N 500020
#define ll long long

using namespace std;
using namespace __gnu_pbds;

int n, scr[N], cnt, tot;
map<string, int> mp;
string name[N];
struct node {
  int score, id;
  friend bool operator < (const node &a, const node &b) {
    return a.score == b.score ? a.id < b.id : a.score > b.score;
  }
};
inline node create_node(int x) {
  node res;
  res.score = scr[x];
  res.id = x;
  return res;
}
tree<node, null_type, less<node>, rb_tree_tag,
     tree_order_statistics_node_update>
    board;
int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  int T;
  cin >> T;
  while (T --) {
    char c;
    string str;
    cin >> c >> str;
    if (c == '+') {
      if (mp[str]) {
        board.erase(create_node(mp[str]));
        --tot;
      }
      mp[str] = ++ cnt;
      cin >> scr[cnt];
      board.insert(create_node(cnt));
      ++ tot;
      name[cnt] = str;
    } else if (c == '?' && !isdigit(str[0])) {
      int x = mp[str];
      cout << board.order_of_key(create_node(x)) + 1 << endl;
    } else {
      int x = atoi(str.c_str());
      for (int i = x; i <= min(tot, x + 9); ++i) {
        cout << name[board.find_by_order(i - 1) -> id] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
