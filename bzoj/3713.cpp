#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x;
}
ll f[1020], cnt = 1;
int main(){
	f[1] = 1;
	while(f[cnt] <= 1e9) f[cnt+1] = f[cnt] + f[cnt-1], cnt++;
	ll T = read();
	while(T--){
		ll x = read(), flag = 0;
		for(int i = 0; i < cnt && !flag; i++) if(f[i] <= x)
			for(int j = i; j < cnt && !flag; j++)
				if(f[i]*f[j] == x) flag = 1;
		puts(flag?"TAK":"NIE");
	}
}