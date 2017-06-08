#include <bits/stdc++.h>
#define N 1000010
#define mod 3000007

using namespace std;
typedef long long llg;

int head[mod], nxt[N], to[N], c[N];
int l, r, w[4][4], tot, d[N], z, n, ans;

int insert(int x){
	int u = x % mod;
	for(int i = head[u]; i; i = nxt[i])
		if(to[i] == x) return c[i];
	to[++tot] = x;
	c[tot] = z+1;
	d[r++] = x;
	nxt[tot] = head[u];
	head[u] = tot;
	return 0;
}

void work(int x1, int y1, int x2, int y2){
	swap(w[x1][y1], w[x2][y2]);
	int now = 0;
	for(int i = 1; i <= 3;i++)
		for(int j = 1; j <= 3;j++)
			now = now * 10 + w[i][j];
	insert(now);
	swap(w[x1][y1], w[x2][y2]);
}

int main(){
	insert(816357492); insert(438951276); insert(294753618); insert(672159834);
	insert(618753294); insert(276951438); insert(492357816); insert(834159672);
	while(l != r){
		int u = d[l++];
		z = insert(u);
		for(int i = 3; i; i--)
			for(int j = 3; j; j--)
				w[i][j] = u%10,
				u /= 10;
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++){
				if(i != 3) work(i, j, i+1, j);
				if(j != 3) work(i, j, i, j+1);
			}
	}
	while(~scanf("%d", &n) && n){
		ans = n;
		for(int i = 1; i < 9; i++){
			scanf("%d", &n);
			ans = ans * 10 + n;
		}
		printf("%d\n", insert(ans)-1);
	}
}
