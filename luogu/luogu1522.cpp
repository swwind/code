#include <bits/stdc++.h>
#define N 160
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
const double inf = 1e100;
int x[N], y[N];
char ch[N];
double mp[N][N], f[N], ans = inf, sum;
double dis(int i, int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			mp[i][j] = i == j ? 0 : inf;
	for(int i = 1; i <= n; i++){
		scanf("%s", ch+1);
		for(int j = 1; j <= n; j++)
			if(ch[j]-'0') mp[i][j] = dis(i, j);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) if(mp[i][j] < inf)
			f[i] = max(f[i], mp[i][j]);
	for(int i = 1; i < n; i++)
		for(int j = i+1; j <= n; j++) if(mp[i][j] == inf)
			ans = min(ans, f[i]+dis(i, j)+f[j]);
	for(int i = 1; i <= n; i++) sum = max(sum, f[i]);
	printf("%.6lf\n", max(ans, sum));
	return 0;
}
