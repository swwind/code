#include <bits/stdc++.h>
#define ll long long
using namespace std;
char A[120], B[120];
int nxt[120];
int main(){
	scanf("%s%s", A+1, B+1);
	int n = strlen(A+1), m = strlen(B+1);
	for(int i = 2, j = 0; i <= n; i++){
		if(A[i] == B[j+1]) j++;
		if(j == m) return printf("%d\n", i-m+1)&0;
	}
}

