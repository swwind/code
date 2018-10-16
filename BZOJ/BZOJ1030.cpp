#include <bits/stdc++.h>
#define N 60020
#define zyy 10007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int ch[N][26], cnt = 1, fl[N], q[N], fail[N], f[102][N];
char str[120];
int main(){
	int n = read(), m = read();
	for(int i = 0; i < 26; i++) ch[0][i] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%s", str+1);
		int len = strlen(str+1), now = 1;
		for(int j = 1; j <= len; j++){
			if(!ch[now][str[j]-'A'])
				ch[now][str[j]-'A'] = ++cnt;
			now = ch[now][str[j]-'A'];
		}
		fl[now] = 1;
	}
	int l = 0, r = 1; fail[1] = 0; q[1] = 1;
	while(l < r){
		int now = q[++l];
		for(int i = 0; i < 26; i++){
			if(!ch[now][i]) continue;
			int k = fail[now];
			while(!ch[k][i]) k = fail[k];
			fail[ch[now][i]] = ch[k][i];
			if(fl[ch[k][i]]) fl[ch[now][i]] = 1;
			q[++r] = ch[now][i];
		}
	}
	f[0][1] = 1;
	for(int x = 1; x <= m; x++)
		for(int i = 1; i <= cnt; i++){
			if(fl[i] || !f[x-1][i]) continue;
			for(int j = 0; j < 26; j++){
				int k = i;
				while(!ch[k][j]) k = fail[k];
				f[x][ch[k][j]] = (f[x][ch[k][j]]+f[x-1][i])%zyy;
			}
		}
	int ans1 = 0, ans2 = 1;
	for(int i = 1; i <= m; i++) ans2 = (ans2*26)%zyy;
	for(int i = 1; i <= cnt; i++) if(!fl[i]) ans1 = (ans1+f[m][i])%zyy;
	int ans = (ans2-ans1+zyy)%zyy;
	printf("%d\n", ans);
	return 0;
}