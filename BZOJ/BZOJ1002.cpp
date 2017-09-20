#include <iostream>
#include <cstdio>
using namespace std;
struct data{
	int a[101],len;
};
int n;
data mul(data a,int k){
	for(int i = 1; i <= a.len; i++)
		a.a[i] *= k;
	for(int i = 1; i <= a.len; i++)
		a.a[i+1] += a.a[i] / 10,
		a.a[i] %= 10;
	if(a.a[a.len+1]) a.len++;
	return a;
} 
data sub(data a, data b){
	a.a[1] += 2;
	int j = 1;
	while(a.a[j] >= 10)
		a.a[j] %= 10,
		a.a[++j]++;
	for(int i = 1; i <= a.len; i++){
		a.a[i] -= b.a[i];
		if(a.a[i] < 0)
			a.a[i] += 10,
			a.a[i+1]--;
	}
	while(!a.a[a.len]) a.len--;
	return a;
}
int main(){
	data f[101];
	f[1].a[1] = 1;
	f[2].a[1] = 5;
	f[1].len = f[2].len = 1;
	scanf("%d",&n);
	for(int i = 3; i <= n; i++)
		f[i] = sub(mul(f[i-1], 3), f[i-2]);
	for(int i = f[n].len; i; i--)
		printf("%d", f[n].a[i]);
	puts("");
	return 0;
}
