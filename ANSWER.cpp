#include <bits/stdc++.h>
#define N 3010
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int n, m, f[N][N];
struct misaka {
	int x, y;
	friend bool operator < (const misaka &p, const misaka &q) {
		return p.x > q.x;
	}
} a[N];

void get(int k) {
	sort(a + k, a + n + 1);
	int w = a[k].x;
	for (int i = n; i > k; i--) {
		if (w > 1) w -= 2, f[a[k].y][a[i].y] = 1;
		else if(!w) a[i].x -= 2, f[a[i].y][a[k].y] = 1;
		else w--, a[i].x--, f[a[k].y][a[i].y] = f[a[i].y][a[k].y] = 2;
	}
	a[k].x = 0;
}
int main(int argc, char const *argv[]) {
	cin >> n >> m;
	int x = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x;
		a[i].y = i;
		x += n - i << 1;
		sum += a[i].x;
		if (sum > x)
			return puts("no") & 0;
	}
	for (int i = m + 1; i <= n; i++) {
		a[i].y = i;
		x += n - i << 1;
		a[i].x = min(a[i - 1].x, x - sum);
		sum += a[i].x;
	}
	if (sum != x)
		return puts("no") & 0;
	for (int i = 1; i < n; i++)
		get(i);
	puts("yes");
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n; j++) {
			if (i == j) putchar('X');
			else if(!f[i][j]) putchar('L');
			else if(f[i][j] == 1) putchar('W');
			else putchar('D');
		}
		puts("");
	}
}