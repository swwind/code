#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int add(int x){
	int ans = 1;
	for(;x%10==0;x/=10)ans*=10;
	return ans;
}
int calc(int x){
	int ans = 0;
	while(x%10==0)x/=10;
	x%10 == 5 && --ans;
	for(;x;x/=10)ans+=2;
	return ans;
}
int main(int argc, char const *argv[]){
	int T = read();
	while(T--){
		int l = read(), r = read();
		int mn = calc(l), ans = l;
		l += add(l);
		while(l <= r){
			int fuck = calc(l);
			if(fuck < mn) mn = fuck, ans = l;
			l += add(l);
		}
		printf("%d\n", ans);
	}
	return 0;
}