#include <bits/stdc++.h>
#define zyy 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char ch[12];
int f[1025][1003], cnt[12], v[12], a[12];
int main(){
	int T = read();
	while(T--){
		scanf("%s", ch+1);
		int d = read(), len = strlen(ch+1);
		memset(f, 0, sizeof f);
		for(int i = 0; i < 10; i++) cnt[i]=0,v[i]=1;
		for(int i = 1; i <= len; i++){
			a[i] = ch[i]-'0';
			v[a[i]] *= ++cnt[a[i]];
		}
		f[0][0] = 1;
		for(int i = 0; i < (1<<len); i++)
			for(int k = 0; k < d; k++) if(f[i][k])
				for(int x = 1; x <= len; x++) if(!(i&(1<<x-1)))
					f[i|(1<<x-1)][(a[x]+k*10)%d] += f[i][k];
		for(int i = 0; i < 10; i++) f[(1<<len)-1][0] /= v[i];
		printf("%d\n", f[(1<<len)-1][0]);
	}
}