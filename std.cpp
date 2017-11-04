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
int a[13], b[13];
int main(int argc, char const *argv[]) {
	b[2 - 1] = 1;
	b[5 - 1] = 1;
	for(int i = 9; i >= 0; i--)
		b[i] += b[i + 1];
	for(int i = 0; i < 10; i++)
		a[i] += b[i];
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}