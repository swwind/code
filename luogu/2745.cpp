#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int x1[N], y1_[N], x2[N], y2[N], n, dp[N], mx, mn, dl[N];
char op, I;
map<char, int> mp;
int a[N], b[N], aa[N], bb[N];
bool f[300][300];
double calc(int x){
	int at = 0, bt = 0;
	for(int i = 1; i <= n; i++)
		if(!dl[i] && dp[i] >= dp[x]){
			a[++at] = x1[i]; a[++at] = x2[i];
			b[++bt] = y1_[i]; b[++bt] = y2[i];
		}
	sort(a+1, a+at+1); sort(b+1, b+bt+1);
	at = unique(a+1, a+at+1)-a-1;
	bt = unique(b+1, b+bt+1)-b-1;
	for(int i = 1; i <= at; i++) aa[a[i]] = i;
	for(int i = 1; i <= bt; i++) bb[b[i]] = i;
	memset(f, 0, sizeof f);
	for(int i = aa[x1[x]]; i < aa[x2[x]]; i++)
		for(int j = bb[y1_[x]]; j < bb[y2[x]]; j++)
			f[i][j] = 1;
	for(int o = 1; o <= n; o++)
		if(!dl[o] && dp[o] > dp[x])
			for(int i = aa[x1[o]]; i < aa[x2[o]]; i++)
				for(int j = bb[y1_[o]]; j < bb[y2[o]]; j++)
					f[i][j] = 0;
	double sum = 0;
	for(int i = 1; i < at; i++)
		for(int j = 1; j < bt; j++)
			if(f[i][j]) sum += (a[i+1]-a[i])*(b[j+1]-b[j]);
	return 100*sum/(1.*(x2[x]-x1[x])*(y2[x]-y1_[x]));
}
int main(int argc, char const *argv[]){
	while((op=getchar()) != EOF){
		if(op == 'w'){ ++n;
			scanf("(%c,%d,%d,%d,%d)", &I, x1+n, y1_+n, x2+n, y2+n);
			if(x1[n] > x2[n]) swap(x1[n], x2[n]);
			if(y1_[n] > y2[n]) swap(y1_[n], y2[n]);
			mp[I] = n; dp[n] = ++mx;
		}
		if(op == 't'){
			scanf("(%c)", &I);
			dp[mp[I]] = ++mx;
		}
		if(op == 'b'){
			scanf("(%c)", &I);
			dp[mp[I]] = --mn;
		}
		if(op == 'd'){
			scanf("(%c)", &I);
			dl[mp[I]] = 1;
		}
		if(op == 's'){
			scanf("(%c)", &I);
			printf("%.3lf\n", calc(mp[I]));
		}
	}
	return 0;
}
