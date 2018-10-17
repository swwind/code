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
int a[N];
vector<int> son[N];
 
int resolve(int x) {
  vector<int> dps;
  for (size_t i = 0; i < son[x].size(); ++ i) {
    dps.push_back(resolve(son[x][i]));
  }
  sort(dps.begin(), dps.end());
  int mxdep = 1;
  for (size_t i = 0; i < dps.size(); ++ i) {
    mxdep = max(mxdep, (int) (dps[i] + dps.size() - i));
  }
  return mxdep;
}
 
int main(int argc, char const *argv[]) {

  int n = read();
  for (int i = 2; i <= n; ++ i) {
    a[i] = read();
    son[a[i]].push_back(i);
  }
 
  printf("%d\n", resolve(1) - 1);
 
  return 0;
}