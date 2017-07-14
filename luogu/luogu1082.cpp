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
void exgcd(int a, int b, int &x, int &y){
	if(!b){x=1,y=0;return;}
	exgcd(b, a%b, x, y);
	int t = x; x = y;
	y = t-a/b*y;
}
int main(int argc, char const *argv[]){
	int a = read(), b = read(), x, y;
	exgcd(a, b, x, y);
	printf("%d\n", (x%b+b)%b);
	return 0;
}