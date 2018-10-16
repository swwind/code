// AC 自动机

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
int ch[N][26], cnt, num, n;
int val[N];
char str[160][80];
void insert(char *str) {
  int n = strlen(str + 1);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    int x = str[i] - 'a';
    if (!ch[now][x])
      ch[now][x] = ++ cnt;
    now = ch[now][x];
  }
  val[now] = ++ num;
}
int q[N], l, r, fail[N];
void build_fail() {
  for (int i = 0; i < 26; i++)
    if (ch[0][i]) q[++ r] = ch[0][i];
  while (l < r) {
    int now = q[++ l];
    for (int i = 0; i < 26; i++) {
      if (!ch[now][i]) ch[now][i] = ch[fail[now]][i];
      else fail[ch[now][i]] = ch[fail[now]][i], q[++ r] = ch[now][i];
    }
  }
}
int ans[N];
void query(char *str) {
  int n = strlen(str + 1);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    int x = str[i] - 'a';
    int k = now = ch[now][x];
    while (k) {
      ans[val[k]] ++;
      k = fail[k];
    }
  }
}
int c[N];
bool cmp(int x, int y) {
  return ans[x] > ans[y];
}
int main(int argc, char const *argv[]) {
  while (n = read()) {
    memset(ch, 0, sizeof ch);
    memset(val, 0, sizeof val);
    memset(fail, 0, sizeof fail);
    memset(ans, 0, sizeof ans);
    l = r = cnt = num = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", str[i] + 1);
      insert(str[i]);
      c[i] = i;
    }
    build_fail();
    scanf("%s", str[n + 1] + 1);
    query(str[n + 1]);
    sort(c + 1, c + n + 1, cmp);
    printf("%d\n", ans[c[1]]);
    int ed = 1;
    while (ans[c[ed]] == ans[c[1]])
      ed ++;
    for (int i = 1; i < ed; i++)
      printf("%s\n", str[c[i]] + 1);
    // for (int i = 1; i <= n; i++)
    //   printf("ans[%d] = %d\n", c[i], ans[c[i]]);
  }
  return 0;
}