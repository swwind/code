#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll ans;
int n;
char ch[300005];
struct pam{
	int cnt, last;
	int a[300005][26], fa[300005], l[300005], size[300005];
	pam(){
		cnt = fa[0] = fa[1] = 1;
		l[1] = -1;
	}
	void extend(int c, int n){
		int p = last;
		while(ch[n-l[p]-1] != ch[n]) p = fa[p];
		if(!a[p][c]){
			int now = ++cnt, k = fa[p];
			l[now] = l[p]+2;
			while(ch[n-l[k]-1] != ch[n]) k = fa[k];
			fa[now] = a[k][c]; a[p][c] = now;
		}
		last = a[p][c];
		size[last]++;
	}
	void solve(){
		for(int i = cnt; i; i--){
			size[fa[i]] += size[i];
			ans = max(ans, (ll)size[i]*l[i]);
		}
	}
}pam;
int main(){
	scanf("%s",ch+1);
	n = strlen(ch+1);
	for(int i = 1; i <= n; i++)
		pam.extend(ch[i]-'a', i);
	pam.solve();
	printf("%lld\n",ans);
	return 0;
}