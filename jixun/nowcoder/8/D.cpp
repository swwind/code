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

int a[N], b[N], c[N];
int n;

int check_valid() {
  for (int i = 1; i <= n; ++ i) {
    if (a[i] < 0) return false;
  }
  for (int i = 2; i <= n; ++ i) {
    if (b[i] != a[i] && b[i] != a[i-1]) return false;
  }
  return true;
}

int main() {

  scanf("%d", &n);
  for (int i = 2; i <= n; ++ i) {
    scanf("%d", &b[i]);
  }
  for (int i = 2; i <= n; ++ i) {
    scanf("%d", &c[i]);
  }

  int ans = 0;
  a[1] = b[2];
  for (int i = 2; i <= n; ++ i) {
    a[i] = c[i] - a[i-1];
    printf("%d\n", a[i]);
  }
  ans += check_valid();
  a[1] = c[2] - b[2];
  if (a[1] != b[2]) {
    for (int i = 2; i <= n; ++ i) {
      a[i] = c[i] - a[i-1];
    }
    ans += check_valid();
  }
  printf("%d\n", ans);
}
/*
4
  7 5 5
  7 9 5

7 0 9 -4
0 7 2 3
-2 9 0 5


a[2] = c[2] - a[1];
a[3] = c[3] - (c[2] - a[1]) = c[3] - c[2] + a[1];
a[4] = c[4] - (c[3] - (c[2] - a[1])) = c[4] - c[3] + c[2] - a[1];
a[5] = c[5] - (c[4] - (c[3] - (c[2] - a[1]))) = c[5] - c[4] + c[3] - c[2] + a[1];

--> a[2] = d[2] - a[1]
--> a[3] = d[3] + a[1]
--> a[4] = d[4] - a[1]
--> a[5] = d[5] + a[1]
--> a[6] = d[6] - a[1]

(d[2] - a[1]) | a[1] = b[2]
(d[3] + a[1]) | (d[2] - a[1]) = b[3]
(d[4] - a[1]) | (d[3] + a[1]) = b[4]
(d[5] + a[1]) | (d[4] - a[1]) = b[5]


1  ?  1
*  1  1 -> 1 0 1
* 10 10 -> 10 10 10
*/
