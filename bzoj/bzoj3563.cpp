#include <bits/stdc++.h>
#define M 100020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node{
	int x, y;
}e[M*5];
int k;
char s[M]; bool v[M*5];
int ans[M], fa[M];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++)
		e[i].x = read(), e[i].y = read();
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	int q = read();
	for(int i = 1, k1, k2; i <= q; i++){
		k1 = read(), k2 = 0;
		gets(s+2);s[1]=' ';
		for(int j = 1; s[j]; j++)
			if(s[j]>='0'&&s[j]<='9'&&(s[j+1]<'0'||s[j+1]>'9'))
				k2++;
		ans[i] = k2^k1;
	}
	for(int i = 1; i < q; i++)
		puts(ans[i+1]==ans[i]?"Disconnected":"Connected");
	int tmp = 0; s[0] = 'k';
	for(int i = 1; s[i-1]; i++){
		if(s[i]>='0'&&s[i]<='9')
			tmp = tmp*10+s[i]-'0';
		else if(s[i-1]>='0'&&s[i-1]<='9')
			v[tmp^ans[q]] = 1, tmp = 0;
	}
	int block = n;
	for(int i = 1; i <= m; i++) if(!v[i]){
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y)continue;
		fa[x] = y; block--;
	}
	puts(block==1?"Connected":"Disconnected");
}
/*
5 10
2 1
3 2
4 2
5 1
5 3
4 1
4 3
5 2
3 1
5 4
5
1 1
2 7 0 3
6 0 7 4 6
1 2 7
0 5 0 2 13
*/