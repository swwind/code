#include<bits/stdc++.h>
using namespace std;
int A, B;
int ans[7][8]={{0,0,0,0,0,0,0,0},{0,0,1,2,3,4,5,6},{0,0,6,15,28,45,66,91},{0,0,0,52,143,350,799,1744},{0,0,0,0,614,2431,9184,33603},{0,0,0,0,0,16000,102147,637330},{0,0,0,0,0,0,1114394,11948355}};
int main(){
	scanf("%d%d", &A, &B);
	if(A > B) swap(A, B);
	printf("%d\n", ans[A][B]);
	return 0;
}

