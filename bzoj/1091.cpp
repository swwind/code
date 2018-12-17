#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int x[10], y[10];
double ans;
double sqr(double a){return a*a;}
int n, m;
double calc(int a, int b){
	int x1 = x[a], x2 = x[b];
	int y1 = y[a], y2 = y[b];
	if(x2 > x1)
		if(y2 > y1)
			if(1.*(y2-y1)/(x2-x1)*x1 <= y1)
				return sqrt(sqr(1.*(y2-y1)/(x2-x1)*x1)+sqr(x1));
			else
				return sqrt(sqr(1.*(x2-x1)/(y2-y1)*y1)+sqr(y1));
		else if(y2 < y1)
			if(1.*(y1-y2)/(x2-x1)*x1 <= m-y1)
				return sqrt(sqr(1.*(y1-y2)/(x2-x1)*x1)+sqr(x1));
			else
				return sqrt(sqr(1.*(x2-x1)/(y1-y2)*(m-y1))+sqr(m-y1));
		else return x1;
	else if(x2 < x1)
		if(y2 > y1)
			if(1.*(x1-x2)/(y2-y1)*y1 <= n-x1)
				return sqrt(sqr(1.*(x1-x2)/(y2-y1)*y1)+sqr(y1));
			else 
				return sqrt(sqr(1.*(y2-y1)/(x1-x2)*(n-x1))+sqr(n-x1));
		else if(y2 < y1)
			if(1.*(y1-y2)/(x1-x2)*(n-x1) <= m-y1)
				return sqrt(sqr(1.*(y1-y2)/(x1-x2)*(n-x1))+sqr(n-x1));
			else
				return sqrt(sqr(1.*(x1-x2)/(y1-y2)*(m-y1))+sqr(m-y1));
		else return n-x1;
	else
		if(y1 > y2) return m-y1;
		else return y1;
}
int main(){
	n = read(), m = read();int p = read();
	for(int i = 1; i <= p; i++) x[i] = read(), y[i] = read();
	for(int i = 1; i <= p; i++){
		int j = i==p?1:(i+1), k = i==1?p:(i-1);
		ans += sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))+min(calc(i, j), calc(i, k));
	}
	printf("%.3lf\n", ans);
	return 0;
}