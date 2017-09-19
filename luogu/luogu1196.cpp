#include <bits/stdc++.h>
#define N 30000
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
char ch[5];
int fa[N+5], ln[N+5], fr[N+5];
int find(int x) {
	if (fa[x] == x)
		return fa[x];
	int fx = find(fa[x]);
	fr[x] += fr[fa[x]];
	return fa[x] = fx;
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fr[fx] += ln[fy];
	ln[fy] += ln[fx];
	ln[fx] = 0;
	fa[fx] = fy;
}
int main(int argc, char const *argv[]){
	int n = read();
	for (int i = 1; i <= N; i++)
		fa[i] = i, ln[i] = 1;
	while (n--) {
		scanf("%s", ch+1);
		int x = read(), y = read();
		if (ch[1] == 'C')
			printf("%d\n", find(x) == find(y) ? abs(fr[x]-fr[y])-1 : -1);
		else
			merge(x, y);
	}
	return 0;
}
