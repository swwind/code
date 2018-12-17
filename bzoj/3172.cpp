#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int tr[N][26], f[N], fail[N], cnt = 1, ans[N], q[N];
char ch[N];
void ins(int x){
	scanf("%s", ch);
	int len = strlen(ch), now = 1, z;
	for(int i = 0; i < len; i++){
		z = ch[i]-'a';
		if(!tr[now][z]) tr[now][z] = ++cnt;
		now = tr[now][z];
		ans[now]++;
	}
	f[x] = now;
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) ins(i);
	for(int i = 0; i < 26; i++) tr[0][i] = 1;
	int l = 0, r = 1, now; q[1] = 1;
	while(l < r){
		now = q[++l];
		for(int i = 0; i < 26; i++){
			if(!tr[now][i]) continue;
			int p = fail[now];
			while(!tr[p][i]) p = fail[p];
			fail[tr[now][i]] = tr[p][i];
			q[++r] = tr[now][i];
		}
	}
	for(int i = r; i; i--)
		ans[fail[q[i]]] += ans[q[i]];
	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[f[i]]);
	return 0;
}