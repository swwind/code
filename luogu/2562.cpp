#include <bits/stdc++.h>
using namespace std;
char A[1000020];
int n, a[1000020];
int work(int l, int r){
	if(a[r]-a[l-1] == r-l+1) putchar('B');
	else if(a[r] == a[l-1]) putchar('A');
	else{
		putchar('C');
		int mid = l + r-1 >> 1;
		work(l, mid);
		work(mid+1, r);
	}
}
int main(){
	scanf("%s", A+1);
	int n = strlen(A+1);
	for(int i = 1; i <= n; i++) a[i] = a[i-1]+A[i]-'0';
	work(1, n);
	puts("");
	return 0;
}