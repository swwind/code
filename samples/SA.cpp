#include <bits/stdc++.h>
#define N 100020
static int lg[N];
class SA{
	#ifndef LOG_SIZE
	#define LOG_SIZE 15
	#endif
public:
	int sa[N], rk[N], tp[N], top[N], n, mn[N][LOG_SIZE+1], ht[N];
	char s[N];
	
	void build_sa(int m = 1020){
		int *x = rk, *y = tp;
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
	void getHeight(){
		int k = 0;
		for(int i = 1; i <= n; i++) rk[sa[i]] = i;
		for(int i = 1; i <= n; i++){
			if(k)k--;
			int j = sa[rk[i]-1];
			while(i+k <= n && j+k <= n && s[i+k]==s[j+k])k++;
			ht[rk[i]] = k;
		}
	}
	void clear(){
		std::memset(sa, 0, sizeof sa); std::memset(rk, 0, sizeof rk);
		std::memset(tp, 0, sizeof tp);// std::memset(s, 0, sizeof s);
		std::memset(mn, 0, sizeof mn); std::memset(ht, 0, sizeof ht);
		std::memset(top, 0, sizeof top);
	}
	void init(int ln = 0){
		ln ? n = ln : n = strlen(s+1);
		clear(); // ?
		build_sa(); getHeight();
		for(int i = 1; i <= n; i++) mn[i][0] = ht[i];
		for(int i = 1; i <= LOG_SIZE; i++)
			for(int j = 1; j <= n; j++)
				mn[j][i] = std::min(mn[j][i-1], mn[j+(1<<i-1)][i-1]);
	}
	int lcp(int x, int y){
		if(rk[x] > rk[y]) std::swap(x, y);
		x = rk[x]; y = rk[y];
		int t = lg[y-x];
		return std::min(mn[x+1][t], mn[y-(1<<t)+1][t]);
	}
	void calcLG(){
		for(int i = 0, j = 1, nxt = 2; j < N; i++, nxt<<=1)
			while(j <= nxt && j < N) lg[j++] = i;
	}
}sa;
int main(){
	scanf("%s", sa.s + 1);
	sa.n = strlen(sa.s + 1);
	sa.build_sa();
	for (int i = 1; i <= sa.n; i++)
		printf("%d\n", sa.sa[i]);
}