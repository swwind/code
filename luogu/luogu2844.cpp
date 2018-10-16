#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[N], b[N][2];
int main(int argc, char const *argv[]) {
	int n = read(), k = read(), p = read();
  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
  }
  int ans = 0, cst = 0;
  for (int i = 1; i <= k; ++ i) {
    b[i][0] = read();
    b[i][1] = read();
    cst += b[i][a[i]];
  }
  cout << cst << endl;
	return 0;
}