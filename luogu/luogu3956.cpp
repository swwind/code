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
int mp[120][120], mn[120][120][2];
struct node {
	int x, y, c, v;
}q[N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	while (m --) {
		int x = read(), y = read();
		mp[x][y] = read() + 1;
	}
	memset(mn, 63, sizeof mn);
	int l = 0, r = 0;
	if (mp[1][1] != 1) q[++r] = (node){1, 1, 2, 0}, mn[1][1][1] = 0; // 0 or 2
	if (mp[1][1] != 2) q[++r] = (node){1, 1, 1, 0}, mn[1][1][0] = 0; // 0 or 1
	while (l < r) {
		node p = q[++l];
		int x = p.x, y = p.y, c = p.c, v = p.v;
		// printf("%d %d %d %d\n", x, y, c, v);
		if (v > mn[x][y][c-1]) continue;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx > n || yy > n || xx < 1 || yy < 1) continue;
			if (!mp[x][y] && !mp[xx][yy]) continue;
			int szb;
			if (!mp[xx][yy]) { // this is null
				// change to 1
				szb = v + (c == 2) + 2;
				if (szb < mn[xx][yy][0]) {
					q[++r] = (node){xx, yy, 1, szb};
					mn[xx][yy][0] = szb;
				}
				// change to 2
				szb = v + (c == 1) + 2;
				if (szb < mn[xx][yy][1]) {
					q[++r] = (node){xx, yy, 2, szb};
					mn[xx][yy][1] = szb;
				}
			} else {
				szb = v + (c != mp[xx][yy]);
				if (szb < mn[xx][yy][mp[xx][yy]-1]) {
					q[++r] = (node){xx, yy, mp[xx][yy], szb};
					mn[xx][yy][mp[xx][yy]-1] = szb;
				}
			}
		}
	}
	int res = min(mn[n][n][1], mn[n][n][0]);
	printf("%d\n", res == mn[0][0][0] ? -1 : res);
	return 0;
}