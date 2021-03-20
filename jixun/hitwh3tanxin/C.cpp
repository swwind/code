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

struct fuck {
  int st, ed;
  friend bool operator < (const fuck &a, const fuck &b) {
    return a.ed == b.ed ? a.st < b.st : a.ed < b.ed;
  }
};

fuck segs[N];

int main() {
  int n;
  while (~scanf("%d", &n) && n) {
    for (int i = 1; i <= n; ++ i) {
      segs[i].st = read();
      segs[i].ed = read();
    }
    sort(segs + 1, segs + n + 1);
    int lastend = -2e9;
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
      if (segs[i].st >= lastend) {
        lastend = segs[i].ed;
        ++ ans;
      }
    }
    printf("%d\n", ans);
  }
}

/**
--------
-----------
--------------
  ---
  -------
  ----------
     -----------

*/