#include <bits/stdc++.h>
using namespace std;
int n, b[70], tot, ans;
unsigned long long x;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		tot = 0; cin >> x;
		for(;x;x-=x&-x)++tot;
		++b[tot];
	}
	for(int i = 0; i < 70; i++)ans+=b[i]&1;
	puts(ans%9?"B":"L");
}
