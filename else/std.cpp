#include <cstdio>
#include <cmath>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(int argc, char const *argv[]) {
	ll a = read(), b = read();
	if (abs(a - b) == 1) return puts("Yes!") & 0;
	if (a < 10000 && b < 10000) {
		ll x = sqrt(a * a + a * a * b * b + b * b) + .5;
		if (x * x == a * a + a * a * b * b + b * b)
			puts("Yes!");
		else
			puts("No!");
	} else {
		puts("No!");
	}
	return 0;
}