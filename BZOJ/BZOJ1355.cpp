#include <bits/stdc++.h>
#define ll long long
using namespace std;
char B[1000050];
int n, nxt[1000050];
int main(){
	scanf("%d%s", &n, B+1);
	for(int i = 2, j = 0; i <= n; i++){
		while(j && B[j+1] != B[i]) j = nxt[j];
		if(B[j+1] == B[i]) j++; nxt[i] = j;
	}
	printf("%d", n-nxt[n]);
	return 0;
}

