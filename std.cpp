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
int main(int argc, char const *argv[]) {
	int h = read()*5%60;
	int m = read();
	int s = read();
	int t1 = read();
	int t2 = read();
	if (t1 == t2) return puts("YES")&0;
	if (t1 > t2) 
	return 0;
}
