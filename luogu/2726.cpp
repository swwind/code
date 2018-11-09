#include <bits/stdc++.h>
#define N 10005

using namespace std;

int n, a[N];

int main(){
	scanf("%d", &n);
	a[0] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < N; j++)
			a[j] *= i;
		for(int j = 0; j < N; j++)
			if(a[j] > 9)
				a[j+1] = a[j+1] + a[j] / 10,
				a[j] %= 10;
	}
	for(int i = 0; i < N; i++) if(a[i]){
		printf("%d", a[i]);
		return 0;
	}
}

