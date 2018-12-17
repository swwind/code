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
static int lg[N];
class SA{
	#ifndef N
	#define N 100020
	#endif
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
	void init(int ln){
		n = ln; clear();
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
}S1, S2;
int a[N], b[N];
int main(){
	int T = read();
	for(int i = 0, j = 1, nxt = 2; nxt < N; i++, nxt<<=1)
		while(j <= nxt) lg[j++] = i;
	while(T--){
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		scanf("%s", S1.s+1);
		int n = strlen(S1.s+1), n2 = n/2;
		for(int i = 1; i <= n; i++)
			S2.s[n-i+1] = S1.s[i];
		S1.init(n); S2.init(n);
		for(int i = 1; i <= n2; i++)
			for(int j = 1; j+i <= n; j+=i){
				int x = S1.lcp(j, j+i), y = S2.lcp(n-j+1, n-j-i+1);
				int l = max(j, j-y+i), r = min(j+i, j+x)-1;
				if(l <= r){
					a[l+i]++; a[r+i+1]--;
					b[l-i]++; b[r-i+1]--;
				}
			}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
			ans += (a[i]+=a[i-1])*(b[i]+=b[i-1]);
		printf("%lld\n", ans);
	}
}