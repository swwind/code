#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int main(int argc, char const *argv[]){
	int n, k;
	while(cin >> n >> k){
		if(k > 2){puts("0"); continue;}
		if(k == 2){puts("1"); continue;}
		int ans = 0;
		for(int i = 1; i*i <= n; i++)
			if(n%i == 0)
				ans = ans+
	}
	return 0;
}