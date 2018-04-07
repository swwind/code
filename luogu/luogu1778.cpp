#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
string str;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int mp[300];
inline int encode(int a, int b, int c) {
  return a << 16 | b << 8 | c;
}
inline void decode(int code, int &a, int &b, int &c) {
  a = code >> 16 & 255;
  b = code >> 8  & 255;
  c = code       & 255;
}
inline bool check(int a, int b, int a1, int b1) {
  return a1 == b1 || a1 == b && a == b1;
}
vector <int> to[300];
int st[5], ed[5], id[20][20], vis[200][200][200];
int main(int argc, char const *argv[]) {
  int m, n, w; cin >> m >> n >> w;
  while (n) {
    // prepare
    getline(cin, str);
    int cnt = 0;
    memset(id, 0, sizeof id);
    for (int i = 1; i <= n; i++) {
      getline(cin, str);
      for (int j = 1; j <= m; j++) {
        char ch = str[j - 1];
        if (ch == '#') {
          // mp[i][j] = 1;
        } else {
          id[i][j] = ++ cnt;
          if (ch >= 'A' && ch <= 'Z') ed[ch - 'A' + 1] = cnt;
          if (ch >= 'a' && ch <= 'z') st[ch - 'a' + 1] = cnt;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!id[i][j]) continue;
        int pos = id[i][j];
        to[pos].clear();
        if (id[i - 1][j]) to[pos].push_back(id[i - 1][j]);
        if (id[i][j - 1]) to[pos].push_back(id[i][j - 1]);
        if (id[i + 1][j]) to[pos].push_back(id[i + 1][j]);
        if (id[i][j + 1]) to[pos].push_back(id[i][j + 1]);
        to[pos].push_back(pos);
      }
    }
    if (w <= 2) {
      int pos = ++ cnt;
      st[3] = ed[3] = pos;
      to[pos].clear();
      to[pos].push_back(pos);
    }
    if (w <= 1) {
      int pos = ++ cnt;
      st[2] = ed[2] = pos;
      to[pos].clear();
      to[pos].push_back(pos);
    }
    // bfs
    queue<int> q;
    memset(vis, 0, sizeof vis);
    int __st = encode(st[1], st[2], st[3]);
    q.push(__st);
    vis[st[1]][st[2]][st[3]] = 1;
    while (!q.empty()) {
      int code = q.front(); q.pop();
      int a, b, c; decode(code, a, b, c);
      if (a == ed[1] && b == ed[2] && c == ed[3])
        break;
      for (int a1 : to[a]) {
        for (int b1 : to[b]) {
          if (check(a, b, a1, b1))
            continue;
          for (int c1 : to[c]) {
            if (check(a, c, a1, c1) || check(b, c, b1, c1))
              continue;
            int pos = encode(a1, b1, c1);
            if (vis[a1][b1][c1]) continue;
            vis[a1][b1][c1] = vis[a][b][c] + 1;
            q.push(pos);
          }
        }
      }
    }
    cout << vis[ed[1]][ed[2]][ed[3]] - 1 << endl;

    cin >> m >> n >> w;
  }
  return 0;
}