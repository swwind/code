#include <bits/stdc++.h>
#define ll long long
using namespace std;int n;
int get(int k){
	int sum = 0;double s = sqrt(k);int i;
	for(i = 1; i < s; i++) if(k % i == 0) sum += 2;
	if((i+1)*(i+1) == k) sum++;
	return sum;
}
int main(){
	scanf("%d", &n);
	for(int i = 2; i; i++) if(get(i) == n) return printf("%d\n", i);
}

