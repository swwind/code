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
int a[N], ans;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		a[read()] ++;
	for (int i = 1; i <= 100000; i++)
		ans = max(ans, a[i - 1] + a[i] + a[i + 1]);
	cout << ans << endl;
	return 0;
}