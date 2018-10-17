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
char s[N<<1];
int sa[N], rk[N], tmp[N], top[N], n, len;
void build_sa(){
	int m = 128; // maxnum
	int *x = rk, *y = tmp;
	for(int i = 1; i <= m; i++) top[i] = 0;
	for(int i = 1; i <= n; i++) top[x[i]=s[i]]++;
	for(int i = 1; i <= m; i++) top[i] += top[i-1];
	for(int i = n; i; i--) sa[top[x[i]]--] = i;
	for(int k = 1; k < n; k <<= 1){
		int p = 0;
		for(int i = n; i > n-k; i--) y[++p] = i;
		for(int i = 1; i <= n; i++) if(sa[i] > k) y[++p] = sa[i]-k;
		for(int i = 1; i <= m; i++) top[i] = 0;
		for(int i = 1; i <= n; i++) top[x[y[i]]]++;
		for(int i = 1; i <= m; i++) top[i] += top[i-1];
		for(int i = n; i; i--) sa[top[x[y[i]]]--] = y[i];
		swap(x, y);
		p = 1; x[sa[1]] = 1;
		for(int i = 2; i <= n; i++)
			if(y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) x[sa[i]] = p;
			else x[sa[i]] = ++p;
		if(p >= n) break; m = p;
	}
}

int main(){
	scanf("%s", s+1);
	len = strlen(s+1);
	for(int i = 1; i <= len; i++) s[i+len] = s[i];
	n = len<<1; build_sa();
	for(int i = 1; i <= n; i++)
		if(sa[i] <= len) putchar(s[sa[i]+len-1]);puts("");
	return 0;
}
