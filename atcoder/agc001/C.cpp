#include <bits/stdc++.h>
#define N 2020
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
int main(int argc, char const *argv[]) {
  int n = read(), k = read();
  
  return 0;
}