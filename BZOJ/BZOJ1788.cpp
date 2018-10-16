#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[100050], b[100050], x[100050];
char c;
int main(){
	scanf("%d", &n);
	for(int i = n - 1; i >= 0; i--) scanf("%d", x+i);
	for(int i = n - 1; i >= 0; i--) scanf("%d", a+i);
	scanf("%c", &c);scanf("%c", &c);
	for(int i = n - 1; i >= 0; i--) scanf("%d", b+i);
	if(c == '+'){
		for(int i = 0; i < n; i++)
			a[i] += b[i], a[i+1] += a[i] / x[i], a[i] %= x[i];
		for(int i = n - 1; i >= 0; i--) printf("%d ", a[i]);
	}
	else{
		int flag;
		for(int i = n - 1; i >= 0; i--)
			if(a[i] < b[i]){
				flag = 1;
				break;
			}
		if(flag)
			for(int i = n - 1; i >= 0; i--) swap(a[i], b[i]);
		for(int i = 0; i < n; i++){
			a[i] -= b[i];
			if(a[i] < 0) a[i] += x[i], a[i+1]--;
		}
		if(flag) printf("-");
		for(int i = n - 1; i >= 0; i--) printf("%d ", a[i]);
	}
	return 0;
}
/*
3
3 2 5
1 1 2
+
0 0 3
*/
