#include <bits/stdc++.h>
#define ll long long
#define rep(a) for(int a = 0; a < 16; a++)
#define N 200050
using namespace std;
bool f[21][17][17][17][17][17];
int n;
int pr(int i,int j,int k,int l,int a,int b,int c){
	string str = "0123456789abcdefghijklmnopqrstuvwxyz";
	printf("%c%c%c%c%c%c%c\n", str[i], str[j], str[k], str[l], str[a], str[b], str[c]);
	return 0;
}
int main(){
	scanf("%d", &n);
	rep(i)rep(j)rep(k)rep(l)rep(a)rep(b)rep(c)
		if(!f[0][i][j][k][l][a]&&!f[1][i][j][k][l][b]&&!f[2][i][j][k][a][b]&&!f[3][i][j][l][a][b]&&!f[4][i][k][l][a][b]&&!f[5][j][k][l][a][b]
				&&!f[6][i][j][k][l][c]&&!f[7][i][j][k][a][c]&&!f[8][i][j][l][a][c]&&!f[9][i][k][l][a][c]&&!f[10][j][k][l][a][c]&&!f[11][i][j][k][b][c]
				&&!f[12][i][j][l][b][c]&&!f[13][i][k][l][b][c]&&!f[14][j][k][l][b][c]&&!f[15][i][j][a][b][c]&&!f[16][i][k][a][b][c]
				&&!f[17][j][k][a][b][c]&&!f[18][i][l][a][b][c]&&!f[19][j][l][a][b][c]&&!f[20][k][l][a][b][c]){
			n--;
			if(!n) return pr(i, j, k, l, a, b, c);
			f[0][i][j][k][l][a] = f[1][i][j][k][l][b] = f[2][i][j][k][a][b] = f[3][i][j][l][a][b] = f[4][i][k][l][a][b] = f[5][j][k][l][a][b] =
			f[6][i][j][k][l][c] = f[7][i][j][k][a][c] = f[8][i][j][l][a][c] = f[9][i][k][l][a][c] = f[10][j][k][l][a][c] = f[11][i][j][k][b][c] =
			f[12][i][j][l][b][c] = f[13][i][k][l][b][c] = f[14][j][k][l][b][c] = f[15][i][j][a][b][c] = f[16][i][k][a][b][c] = f[17][j][k][a][b][c] =
			f[18][i][l][a][b][c] = f[19][j][l][a][b][c] = f[20][k][l][a][b][c] = 1;
		}
		
}
