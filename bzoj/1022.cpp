#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	scanf("%d", &T);
	while(T--){
		int n, x, sum = 0, flag = 1;
		scanf("%d", &n);
		while(n--){
			scanf("%d", &x);
			if(x^1) flag = 0;
			sum ^= x;
		}
		if(flag) sum = !sum;
		puts(sum ? "John" : "Brother");
	}
	return 0;
}
