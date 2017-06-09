#include <bits/stdc++.h>
#define N 1000020
using namespace std;
struct node{
	int x, y, type;
}ask[N];
int a[N<<1], b[N<<1], fa[N<<1];
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x, int y){
	int xx = find(x), yy = find(y);
	if(xx == yy) return;
	fa[xx] = yy;
}
int main(){
	int T = read();
	while(T--){
		int n = read(); b[0] = 0;
		for(int i = 1, x, y, z; i <= n; i++){
			x = read(); y = read(); z = read();
			a[i*2-1] = x; a[i*2] = y; ask[i] = (node){x, y, z};
		}
		int n2 = n << 1;
		sort(a+1, a+n2+1);
		for(int i = 1; i <= n2; i++)
			if(a[i] != a[i-1]) b[++b[0]] = a[i];
		for(int i = 1; i <= n; i++){
			ask[i].x = lower_bound(b+1, b+b[0]+1, ask[i].x)-b;
			ask[i].y = lower_bound(b+1, b+b[0]+1, ask[i].y)-b;
		}
		for(int i = 1; i <= b[0]; i++) fa[i] = i;
		for(int i = 1; i <= n; i++)
			if(ask[i].type) merge(ask[i].x, ask[i].y);
		bool flag = 0;
		for(int i = 1; i <= n; i++)
			if(!ask[i].type) if(find(ask[i].x) == find(ask[i].y)){
				flag = 1;
				break;
			}
		puts(flag?"NO":"YES");
	}
	return 0;
}