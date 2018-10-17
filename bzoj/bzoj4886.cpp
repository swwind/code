#include <bits/stdc++.h>
#define N 60020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char s[N];
int cnt[1<<26], Ans[N], tot, sum, block, ans, n, m;
struct node{
	int l, r, id;
	bool operator < (const node &b) const {
		int x = l/block, y = r/block;
		return x == y ? r < b.r : x < y;
	}
}ask[N];
void add_back(int x){
	int val = 1 << x; cnt[tot]++;
	sum ^= val; tot ^= val;
	for(int i = 0; i < 26; i++)
		ans += cnt[tot^(1<<i)];
	ans += cnt[tot];
}
void add_front(int x){
	sum ^= (1 << x);
	cnt[tot]++;
	tot ^= sum;
	for(int i = 0; i < 26; i++)
		ans += cnt[tot^(1<<i)];
	ans += cnt[tot];
	cnt[tot]++;cnt[tot^=sum]--;
}
void del_back(int x){
	for(int i = 0; i < 26; i++)
		ans -= cnt[tot^(1<<i)];
	ans -= cnt[tot];
	cnt[tot^=(1<<x)]--;
	sum ^= (1 << x);
}
void del_front(int x){
	cnt[tot]++; cnt[tot^=sum]--;
	for(int i = 0; i < 26; i++)
		ans -= cnt[tot^(1<<i)];
	ans -= cnt[tot];
	cnt[tot^=sum]--;
	sum ^= (1 << x);
}
int main(){
	n = read(); m = read();
	scanf("%s", s+1);
	block = sqrt(n);
	for(int i = 1; i <= n; i++) s[i] -= 'a';
	for(int i = 1; i <= m; i++){
		ask[i].l = read();
		ask[i].r = read();
		ask[i].id = i;
	}
	sort(ask+1, ask+m+1);
	int l = 1, r = 0;
	for(int i = 1; i <= m; i++){
		while(l < ask[i].l) del_front(s[l++]);
		while(l > ask[i].l) add_front(s[--l]);
		while(r < ask[i].r) add_back(s[++r]);
		while(r > ask[i].r) del_back(s[r--]);
		Ans[ask[i].id] = ans;
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", Ans[i]);
}