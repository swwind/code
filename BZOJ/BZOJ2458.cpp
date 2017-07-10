#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct point{
	int x, y;
	point(int x = 0, int y = 0):x(x),y(y){}
	friend double operator * (const point &a, const point &b){
		
	}
}p[N];
bool cmp1(point a, point b){return a.x < b.x;}
bool cmp2(point a, point b){return a.y < b.y;}
double solve(int l, int r){
	if(r-l <= 4){

	}
}
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++)
		p[i].x = read(), p[i].y = read();
	sort(p+1, p+n+1);
	printf("%.6lf\n", solve(1, n));
	return 0;
}