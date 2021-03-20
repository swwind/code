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

ll find(int n, int mid) {
  ll ans = 0;
  int p = 1;
  for (int i = 1; i <= n; ++ i) {
    while (p < n && a[p+1] <= a[i] + mid) ++ p;
    ans += p - i;
  }
  // printf("%d %d %lld\n", n, mid, ans);
  return ans;
}

int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
    }
    sort(a + 1, a + n + 1);

    long long m = ((((ll) n * (n - 1)) >> 1) + 1) >> 1;

    int l = 0, r = 1e9;
    int ans = 0;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (find(n, mid) >= m) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", r);
  }
}
