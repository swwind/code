#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fa[120], sum[120];
int find(int x){
	if(fa[x] == x)return x;
	int t = find(fa[x]);
	sum[x] += sum[fa[x]];
	return fa[x]=t;
}
int main(){
	int T = read();
	while(T--){
		bool flag = 1;
		int n = read(), m = read();
		for(int i = 1; i <= n+1; i++) fa[i] = i;
		memset(sum, 0, sizeof sum);
		for(int i = 1; i <= m && flag; i++){
			int l = read(), r = read()+1, val = read();
			int x = find(l), y = find(r);
			if(x == y) if(sum[r]-sum[l] != val){
				flag = 0;
				break;
			}else;
			else{
				if(x < y) swap(x, y), swap(l, r);
				fa[x] = y;
				if(l < r) sum[x] = sum[r]-sum[l]-val;
				else sum[x] = sum[r]-sum[l]+val;
			}
		}
		puts(flag?"true":"false");
	}
	return 0;
}