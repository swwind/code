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
int n = read();
double ans = 420000./n, sum;
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++)
		sum += ans, ans *= 1-.5/i;
	printf("%.2lf\n", sum);
	return 0;
}
