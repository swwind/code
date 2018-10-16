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
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) { x = 1, y = 0; return; }
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}
int main(int argc, char const *argv[]) {
	ll a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	cout << (x + b) % b << endl;
	return 0;
}
