#include <bits/stdc++.h>
#define N 80
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[N][N][N][2], num[N][3], pos[3][N];
char str[N];
int move(int i, int j, int k, int p) {
	return max(num[p][0] - i, 0) + max(num[p][1] - j, 0) + max(num[p][2] - k, 0) - 1;
}
int main(int argc, char const *argv[]) {
	int n = read();
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		num[i][0] = num[i - 1][0];
		num[i][1] = num[i - 1][1];
		num[i][2] = num[i - 1][2];
		if (str[i] == 'V') pos[0][num[i][0] ++] = i;
		else if (str[i] == 'K') pos[1][num[i][1] ++] = i;
		else pos[2][num[i][2] ++] = i;
	}
	// printf("%d %d %d\n", num[n][0], num[n][1], num[n][2]);
	memset(f, 63, sizeof f);
	f[0][0][0][0] = 0;
	for (int i = 0; i <= num[n][0]; i++) {
		for (int j = 0; j <= num[n][1]; j++) {
			for (int k = 0; k <= num[n][2]; k++) {
				if (i < num[n][0]) {
					int x = move(i, j, k, pos[0][i]);
					f[i + 1][j][k][1] = min(f[i + 1][j][k][1], f[i][j][k][0] + x);
					f[i + 1][j][k][1] = min(f[i + 1][j][k][1], f[i][j][k][1] + x);
				}
				if (j < num[n][1])
					f[i][j + 1][k][0] = min(f[i][j + 1][k][0], f[i][j][k][0] + move(i, j, k, pos[1][j]));
				if (k < num[n][2]) {
					int x = move(i, j, k, pos[2][k]);
					f[i][j][k + 1][0] = min(f[i][j][k + 1][0], f[i][j][k][0] + x);
					f[i][j][k + 1][0] = min(f[i][j][k + 1][0], f[i][j][k][1] + x);
				}	
			}
		}
	}
	int ans1 = f[num[n][0]][num[n][1]][num[n][2]][0];
	int ans2 = f[num[n][0]][num[n][1]][num[n][2]][1];
	printf("%d\n", min(ans1, ans2));
	return 0;
}