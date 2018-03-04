#include <bits/stdc++.h>
#define N 40
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int in[N], out[N];
struct node {
  int rb, ct, kn;
};
std::vector<node> vec;
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), v = read(), k = read();
  for (int i = 1; i <= n; i++) {
    in[i] = read();
    out[i] = read();
    if (in[i] < out[i])
      vec.push_back({out[i] - in[i], in[i], 0});
  }
  for (int i = 1; i <= m; i++) {
    int s = read();
    int t = read();
    int e = 0;
    for (int j = 1; j <= t; j++)
      e += in[read()];
    if (s > e)
      vec.push_back({s - e, e, 1});
  }
  return 0;
}