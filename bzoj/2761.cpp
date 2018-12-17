#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<int, bool> mp;
int main(){
	int T = read();
	while(T--){
		int n = read(), x = read();
		printf("%d", x); mp[x]=1;
		for(int i = 1; i < n; i++){
			x = read();
			if(!mp[x]) printf(" %d", x), mp[x]=1;
		}
		puts("");
		mp.clear();
	}
	return 0;
}