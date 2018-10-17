#include <cstdio>
#define N 50020
using namespace std;
int n, l, h, t=1, c[N], q[N];
long long s[N], f[N];
inline long long sqr(long long x){return x*x;}
inline double slope(int i, int j){
	return (f[i]+sqr(s[i]+i)-f[j]-sqr(s[j]+j))/(s[i]+i-s[j]-j);
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i = 1; i <= n; i++)
		scanf("%d", c+i);
	for(int i = 1; i <= n; i++)
		s[i] = s[i-1]+c[i];
	for(int i = 1; i <= n; i++){
		while(h+1<t && slope(q[h],q[h+1])<2*(s[i]+i-l-1)) h++;
		f[i] = f[q[h]]+sqr(s[i]-s[q[h]]+i-q[h]-1-l);
		while(h+1<t && slope(q[t-2],q[t-1])>slope(q[t-1],i)) t--;
		q[t++] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}