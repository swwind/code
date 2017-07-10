#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[5050], len, n;
int mul(int val){
	for(int i = 1; i <= len; i++)
		a[i]*=val;
	for(int i = 1; i <= len; i++){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[len+1])len++;
}
int main(){
	scanf("%d", &n);
	a[len=1]=1;
	while(n > 4) mul(3), n-=3; mul(n);
	printf("%d\n", len);
	if(len > 100) for(int i = 0; i < 100; i++) putchar(a[len-i]+'0');
	else for(int i = len; i; i--) putchar(a[i]+'0');
	return 0;
}

