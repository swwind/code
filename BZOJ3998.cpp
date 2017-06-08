// RE...

#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int ch[N*10][26], tot, cnt[2], val[N], st[2][N];
char str[N];
int dfs(int x){
	for(int i = 0; i < 26; i++)
		if(ch[x][i]) val[x] += dfs(ch[x][i]);
	return val[x];
}
void find(int x, int k){
	if(k <= 0) return;
	for(int i = 0; i < 26; i++)if(ch[x][i]){
		if(k <= val[ch[x][i]]){
			putchar(i+'a');
			return find(ch[x][i], k-1);
		}
		k -= val[ch[x][i]];
	}
}
int main(){
	scanf("%s", str+1);
	int len = strlen(str+1), t = read(), k = read();
	cnt[1] = 1;
	for(int i = 1; i <= len; i++){
		cnt[~i&1] = 1;
		for(int j = 1; j <= cnt[i&1]; j++){
			int &rp = ch[st[i&1][j]][str[i]-'a'];
			if(!rp) rp = ++tot;
			if(t) val[rp]++;
			else val[rp]=1;
			st[~i&1][++cnt[~i&1]] = rp;
		}
	}
	dfs(0);//printf("%d\n", val[0]);
	if(k > val[0]) return puts("-1")&0;
	find(0, k);puts("");
}