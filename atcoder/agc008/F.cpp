#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int to[N<<1], nxt[N<<1], head[N], cnt;
void insert(int x, int y) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

char str[N];
int chs[N], tot, R[N], L[N], d1[N], d2[N];
ll ans;

int fir_dfs(int x,int f) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] != f) {
      chs[x] += fir_dfs(to[i], x);
      int w = d1[to[i]] + 1;
      if (w > d1[x]) d2[x] = d1[x], d1[x] = w;
      else if (w > d2[x]) d2[x] = w;
    }
  }
  return chs[x];
}
void sec_dfs(int x, int f, int v) {
  R[x] = v > d1[x] ? d1[x] : max(v, d2[x]);
  L[x] = str[x] == '1' ? 0 : (tot != chs[x] ? v : (1 << 30));
  if (f) {
    if (d1[x] == v - 1) ++ ans;
    else if (d1[x] < v - 1) ans += chs[x] > 0;
    else ans += chs[x] < tot;
  }
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] != f) {
      if (chs[to[i]]) L[x] = min(L[x], d1[to[i]] + 1);
      if (d1[to[i]] + 1 == d1[x]) sec_dfs(to[i], x, max(v, d2[x]) + 1);
      else sec_dfs(to[i], x, max(v, d1[x]) + 1);
    }
  }
}
int main(int argc, char const *argv[]) {
  // freopen("../../temp/.in", "r", stdin);

  int n = read();
  for (int i = 1; i < n; ++ i) {
    insert(read(), read());
  }
  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++ i) {
    tot += chs[i] = str[i] == '1';
  }

  fir_dfs(1, 0);
  sec_dfs(1, 0, 0);

  for (int i = 1; i <= n; ++ i) {
    if (L[i] <= R[i]) {
      ans += R[i] - L[i] + 1;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
/*

我们考虑枚举你染黑的连通块的中心（也就是所有直径的中点）。 
有两种情况：
1）中心是一个点； 
2）中心是一条边的中点；

对于1），考虑将其置为根rt，则连通块的“半径”是一个区间（半径就是说这个联通块的直径的一半）。

首先考虑其上界R：答案就是来自不同子树的最长链的第二长链，这里是不严格次长，也就是可以相等。这是由于，考虑最长链是A来自x，次长是B来自y，且A>B，那么当你半径>B的时候，y会全被涂黑，然后从从B的链底走到rt再走到x中被涂黑色的最深的点，显然长度>=2B，此时这条链的中心显然不是rt，就gg了。

其次考虑其下界L：下界就是，考虑rt的所有满足子树中存在s[y]=1的 rt的儿子x，然后把所有x的最长链取个min即可（可能还要加个1之类的）。这是由于，所有这样的x中，最大深度最小的那颗子树一定会被全部涂黑，否则同理分析可以知道rt不会是中心。

接着看中心是一条边的情况；假设这条边是(u, v)，断开后得到两颗分别以u和v为根的树A和B，并且记maxdpt(A)表示A的最大深度；则maxdpt小的那一颗树一定会被涂黑，也就是这种情况的答案不会超过1种，这个时候只需要判断maxdpt较小的那个树里面是否存在s[y]=1的y即可。特殊的当maxdpt(A)=maxdpt(B)的时候ans直接++即可，因为题目保证了至少存在一个1。

Just copy & parse...

*/