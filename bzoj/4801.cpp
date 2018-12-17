#include <bits/stdc++.h>
#define N 500020
#define ll long long
#define check(x) (x == 14 ? 1 : x)
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[2], b[2];
char ch[5];
int get(char c){
	if(c == 'A') return 14;
	if(c == 'K') return 13;
	if(c == 'Q') return 12;
	if(c == 'J') return 11;
	if(c == 'T') return 10;
	return c - '0';
}
int main(){
	int T = read();
	while(T--){
		scanf("%s", ch); a[0] = get(ch[0]);
		scanf("%s", ch); a[1] = get(ch[0]);
		scanf("%s", ch); b[0] = get(ch[0]);
		scanf("%s", ch); b[1] = get(ch[0]);
		int ans = -1<<30;
		for(int i = 0; i <= 1; i++){
			int sum = 1<<30, flag = 0;
			for(int j = 0; j <= 1; j++){
				int now = 0;
				a[i] < b[j] ? now -= check(b[j]), flag = 1 : now += check(a[i]);
				a[i^1] != b[j^1]
					? (now += a[i^1] > b[j^1] ? check(a[i^1]) : -check(b[j^1]))
					: (now += flag ? -check(b[j^1]) : check(a[i^1]));
				sum = min(sum, now);
			}
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}