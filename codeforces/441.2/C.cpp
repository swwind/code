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
int get(int x){
	if (x == 0) return 1;
	int ans = 0;
	while(x)ans++,x/=10;
	return ans;
}
int getss(int x){
	int ans = x;
	while(x)ans+=x%10,x/=10;
	return ans;
}
int res[N], cnt;
int main(int argc, char const *argv[]) {
	int n = read();
	int k = get(n) * 9;
	for (int i = 0; i <= k && n - i >= 0; i++)
		if (getss(n - i) == n) res[++cnt] = n - i;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", res[cnt - i + 1]);
	return 0;
}