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
map<ll, bool> mp;
std::vector<ll> res;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		ll x = read();
		if (mp[x]) res.push_back(x), mp[x] = 0;
		else mp[x] = 1;
	}
	sort(res.begin(), res.end());
	if (res.size() < 2) return puts("0")&0;
	else cout << res[res.size()-1] * res[res.size()-2] << endl;
	return 0;
}
