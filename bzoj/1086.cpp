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

int to[N<<1], nxt[N<<1], head[N], cnt;
inline void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int n, b;
int col[N], color, cap[N];
stack<int> st;
void dfs(int x, int f) {
  int sz = st.size();
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs(to[i], x);
    if (st.size() - sz >= b) {
      cap[++ color] = x;
      while (st.size() > sz) {
        col[st.top()] = color;
        st.pop();
      }
    }
  }
  st.push(x);
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);
  n = read(); b = read();
  for (int i = 1; i < n; ++ i) {
    int x = read(), y = read();
    insert(x, y);
  }
  dfs(1, 0);
  cap[color] = 1;
  while (st.size()) {
    col[st.top()] = color;
    st.pop();
  }
  printf("%d\n", color);
  for (int i = 1; i <= n; ++ i) {
    printf("%d%c", col[i], i == n ? '\n' : ' ');
  }
  for (int i = 1; i <= color; ++ i) {
    printf("%d%c", cap[i], i == color ? '\n' : ' ');
  }
  return 0;
}