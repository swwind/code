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
char a[N], b[N];
bool check(int x, int y, int l, int r) {
  int len = r - l + 1;
  for (int i = 0; i < len; ++ i) {
    if (b[x + i] != a[l + i]) {
      return false;
    }
  }
  return true;
}
int main(int argc, char const *argv[]) {
  int n = read();
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = n; ~i; -- i) {
    if (check(1, i, n - i + 1, n)) {
      return printf("%d\n", 2 * n - i), 0;
    }
  }
  return 0;
}