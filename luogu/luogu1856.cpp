#include <bits/stdc++.h>
#define N 10020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], b[N], at, bt;
int x1[N], x2[N], y_[N], y2[N];
bool f[N][N];
map<int, int>aa,bb;
int main(int argc, char const *argv[]){
	int n = read();// a[++at] = -10200; a[++at] = 10200; b[++bt] = -10200; b[++bt] = 10200;
	for(int i = 1; i <= n; i++){
		a[++at] = x1[i] = read(); b[++bt] = y_[i] = read();
		a[++at] = x2[i] = read(); b[++bt] = y2[i] = read();
		if(x1[i] > x2[i]) swap(x1[i], x2[i]);
		if(y_[i] > y2[i]) swap(y_[i], y2[i]);
	}
	sort(a+1, a+at+1); sort(b+1, b+bt+1);
	at = unique(a+1, a+at+1)-a-1;
	bt = unique(b+1, b+bt+1)-b-1;
	for(int i = 1; i <= at; i++) aa[a[i]] = i;
	for(int i = 1; i <= bt; i++) bb[b[i]] = i;
	for(int o = 1; o <= n; o++)
		for(int i = aa[x1[o]]; i < aa[x2[o]]; i++)
			for(int j = bb[y_[o]]; j < bb[y2[o]]; j++)
				f[i][j] = 1;
	int ans = 0;
	for(int i = 1; i < at; i++)
		for(int j = 1; j < bt; j++)if(f[i][j]){
			if(!f[i][j+1]) ans += a[i+1]-a[i];
			if(!f[i][j-1]) ans += a[i+1]-a[i];
			if(!f[i+1][j]) ans += b[j+1]-b[j];
			if(!f[i-1][j]) ans += b[j+1]-b[j];
		}
	printf("%d\n", ans);
	return 0;
}
