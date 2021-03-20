#include <cstdio>
#include <algorithm>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int main() {
  int n = read(), S = read();
  int before = 2e9;
  long long ans = 0;

  for (int i = 1; i <= n; ++ i) {
    int pay = read();
    int wanted = read();

    int single = min(before, pay);
    ans += (long long) single * wanted;
    before = min(before, pay) + S;
  }
  printf("%lld\n", ans);

  return 0;
}