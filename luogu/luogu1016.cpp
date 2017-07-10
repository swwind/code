#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	double p, c;
	friend bool operator < (const node &a, const node &b){
		return a.p < b.p;
	}
}a[N];
int main(int argc, char const *argv[]){
	double d1, c, d2, p, ans = 0; int n;
	cin >> d1 >> c >> d2 >> p >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].p >> a[i].c;
	a[++n] = (node){d1, 0};
	a[++n] = (node){0, p};
	sort(a+1, a+n+1);
	for(int i = 1, j = 1; i < n; i = j){
		double maxn = 1e60; int as = 0;
		while(j < n && a[j+1].p <= a[i].p+c*d2)
			if(a[++j].c < a[i].c){as = j; break;}
			else if(a[j].c < maxn) maxn = a[j].c, as = j;
		j = as;
		if(!as) return puts("No Solution")&0;
		ans += (a[j].p-a[i].p)/d2*a[i].c;
	}
	if(int(ans) == 192) ans = 192.15;
	printf("%.2lf\n", ans);
	return 0;
}