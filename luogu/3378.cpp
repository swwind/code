#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
priority_queue<ll, vector<ll>, greater<ll>> q;
int main(int argc, char const *argv[]) {
	int n = read();
	while (n--) {
		int x = read();
		if (x == 1) q.push(read());
		if (x == 2) printf("%lld\n", q.top());
		if (x == 3) q.pop();
	}
	return 0;
}