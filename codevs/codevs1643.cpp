#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	int x, y;
	bool operator < (const node &b) const {
		return y < b.y;
	}
}a[N];
int main(int argc, char const *argv[]){
	int n = read(), ans = 0;
	for(int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
	sort(a+1, a+n+1);
	for(int i = 1, j = 0; i <= n; i++)
		if(a[i].x >= j) ans++, j = a[i].y;
	printf("%d\n", ans);
	return 0;
}