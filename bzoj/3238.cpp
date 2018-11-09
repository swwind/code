#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
class SAM{
public:
	int ch[N][30], fa[N], l[N], p, np, last, cnt, rt, q, nq;
	char s[N], c;
	void extend(int x){
		p = last;
		c = s[l[last=np=++cnt]=x];
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c] = np;
		if(!p) fa[np] = rt;
		else{
			q = ch[p][c];
			if(l[q] == l[p]+1) fa[np] = q;
			else{
				l[nq=++cnt] = l[p]+1;
				memcpy(ch[nq], ch[q], sizeof ch[p]);
				fa[nq] = fa[q];
				fa[q] = fa[np] = nq;
				for(;ch[p][c]==q;p=fa[p]) ch[p][c] = nq;
			}
		}
	}
	SAM(){last = rt = ++cnt;}
}sam;
int r[N], rk[N], c[N];
char str[N];
ll sum[N];
int main(){
	scanf("%s", str+1); int len = strlen(str+1);
	for(int i = 1; i <= len; i++) sam.s[len-i+1] = str[i]-'a';
	for(int i = 1; i <= len; i++) sam.extend(i);
	for(int i = 1; i <= sam.cnt; i++) c[sam.l[i]]++;
	for(int i = 1; i <= len; i++) c[i] += c[i-1];
	for(int i = 1; i <= sam.cnt; i++) rk[c[sam.l[i]]--] = i;
	int p = 1;
	for(int i = 1; i <= len; i++){
		p = sam.ch[p][sam.s[i]];
		r[p]++; sum[p]++;
	}
	for(int i = sam.cnt; i; i--)
		r[sam.fa[rk[i]]] += r[rk[i]];
	ll ans = 0;
	for(int i = sam.cnt; i; i--){
		int t = rk[i];
		ans += 1ll*sam.l[sam.fa[t]]*r[t]*sum[sam.fa[t]];
		sum[sam.fa[t]] += r[t];
	}
	printf("%lld\n", 1ll*(len+1)*len/2*(len-1)-2*ans);
	return 0;
}