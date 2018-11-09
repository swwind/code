#include <bits/stdc++.h>
#define N 400020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
struct SA{
	#ifndef N
	#define N 100020
	#endif
	int sa[N], rk[N], tmp[N], top[N], s[N];
	void build_sa(){
		int m = 1200; // maxnum
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
			std::swap(x, y);
			p = 1; x[sa[1]] = 1;
			for(int i = 2; i <= n; i++)
				if(y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) x[sa[i]] = p;
				else x[sa[i]] = ++p;
			if(p >= n) break; m = p;
		}
	}
}sa;
int main(){
	int len1 = read();
	for(int i = 1; i <= len1; i++)
		sa.s[i] = read();
	int len2 = read();
	for(int i = 1; i <= len2; i++)
		sa.s[i+len1+1] = read();
	n = len1+len2+2;
	sa.s[n] = sa.s[len1+1] = 1020;
	int l = 1, r = len1+2;
	sa.build_sa();
	for(int i = 1; i <= len1+len2; i++){
		printf("%d ",sa.rk[l] < sa.rk[r] ? sa.s[l++] : sa.s[r++]);
		if(l == len1+1){
			for(int j = r; j < n; j++)
				printf("%d ", sa.s[j]);
			break;
		}
		if(r == n){
			for(int j = l; j <= len1; j++)
				printf("%d ", sa.s[j]);
			break;
		}
	}
	return 0;
}