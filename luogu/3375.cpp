#include <bits/stdc++.h>
using namespace std;
char A[1000020], B[1000020];
int nxt[1000020];
int main(){
	scanf("%s%s", A+1, B+1);
	int n = strlen(A+1), m = strlen(B+1);
	for(int i = 2, j = 0; i <= m; i++){
		while(j && B[i] != B[j+1]) j = nxt[j];
		if(B[i] == B[j+1]) j++; nxt[i] = j;
	}
	for(int i = 1, j = 0; i <= n; i++){
		while(j && A[i] != B[j+1]) j = nxt[j];
		if(A[i] == B[j+1]) j++;
		if(j == m) printf("%d\n", i-m+1), j = nxt[j];
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", nxt[i]);
	return 0;
}
