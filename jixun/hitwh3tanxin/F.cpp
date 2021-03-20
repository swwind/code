#include <cstdio>
#include <algorithm>
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

int main() {

  int T = read();
  while (T --) {
    int n = read();
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    while (n >= 4) {
      ans += min(a[1]+a[1]+a[n-1]+a[n], a[1]+a[2]+a[2]+a[n]);
      n -= 2;
      /*
      abcd
      bc       ad +d
      abc       d +a
      b        ac +c
      ab       cd +a

      abcd
      cd       ab +b
      acd       b +a
      a       bcd +d
      ab       cd +b
      */
    }
    // n = 1, 2, 3
    if (n == 1) ans += a[1];
    else if (n == 2) ans += max(a[1], a[2]);
    else ans += a[1] + a[2] + a[3];

    printf("%d\n", ans);
  }

  return 0;
}

/*
abc
b      ac  +max(ac)
ab     c   +a
       abc +max(ab)



*/