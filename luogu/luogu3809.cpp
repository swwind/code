#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char ch[N];
int n, rk[N], tp[N], top[N], sa[N];
void build_sa(int m = 200) {
  int *x = rk, *y = tp;
  
  for (int i = 1; i <= m; i++) top[i] = 0;
  for (int i = 1; i <= n; i++) top[rk[i] = ch[i]]++; // 统计每个字符出现的次数 top[i]，并将 rk[i] := ch[i]
  for (int i = 1; i <= m; i++) top[i] += top[i - 1]; // 统计小于等于字符 i 的出现的次数 top[i]
  for (int i = n; i; i--) sa[top[x[i]] --] = i; // 按照第一个字母来排序

  for (int k = 1; k < n; k <<= 1) {
    int p = 0;
    for (int i = n; i > n - k; i--) y[++p] = i; // 最后的 k 个元素直接放进 y 里，因为他们最后是 0，rk应该靠前
    for (int i = 1; i <= n; i++) if (sa[i] > k) y[++p] = sa[i] - k; // 如果排名为 i 的串下标大于 k，那么他的。。。
    for (int i = 1; i <= m; i++) top[i] = 0;
    for (int i = 1; i <= n; i++) top[x[y[i]]]++;
    for (int i = 1; i <= m; i++) top[i] += top[i - 1];
    for (int i = n; i; i--) sa[top[x[y[i]]] --] = y[i];
    swap(x, y);

    x[sa[1]] = p = 1; // 排名为 x 

    for (int i = 2; i <= n; i++)
      if (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]) x[sa[i]] = p;
      else x[sa[i]] = ++ p;

    if (p >= n) break;
    m = p;
  }
}
int main(int argc, char const *argv[]) {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  build_sa();
  for (int i = 1; i <= n; i++)
    printf("%d ", sa[i]);
  return 0;
}