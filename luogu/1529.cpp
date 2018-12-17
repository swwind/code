#include <bits/stdc++.h>
#define N 100
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int id(char c){return c > 'Z' ? (c-'a'+27) : (c-'A'+1);}
char nextchar(char ch=getchar()){while(ch<'A'||ch>'Z'&&ch<'a'||ch>'z')ch=getchar();return ch;}
int mp[N][N], mn = 1;
int main(int argc, char const *argv[]){
	int n = read();
	memset(mp, 63, sizeof(int)*N*N);
	for(int i = 1; i <= n; i++){
		int x = id(nextchar()), y = id(nextchar());
		mp[x][y] = mp[y][x] = min(mp[y][x], read());
		mp[x][x] = mp[y][y] = 0;
	}
	for(int k = 1; k <= 52; k++)
		for(int i = 1; i <= 52; i++)
			for(int j = 1; j <= 52; j++)
				mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
	for(int i = 2; i < 26; i++)
		if(mp[i][26] < mp[mn][26]) mn = i;
	printf("%c %d\n", mn-1+'A', mp[mn][26]);
	return 0;
}
