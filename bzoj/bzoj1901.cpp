#include <bits/stdc++.h>
using namespace std;
int a[10020], b[10020],n,m;
char op[2];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	while(m--){
		int l, r,k;
		scanf("%s%d%d", op, &l, &r);
		if(op[0]=='C') a[l] = r;
		else{
			scanf("%d",&k);
			for(int i = l; i <= r; i++)
				b[i-l] = a[i];
			sort(b, b+r-l+1);
			printf("%d\n", b[k-1]);
		}
	}
}