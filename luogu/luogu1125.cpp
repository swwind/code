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
char ch[120];
int cnt[50];
int isPrime(int x){
	if (x == 0 || x == 1) return 0;
	for (int i = 2; i <= x-1; i++)
		if (x%i == 0) return 0;
	return 1;
}
int main(int argc, char const *argv[]) {
	scanf("%s", ch+1);
	int len = strlen(ch+1);
	for (int i = 1; i <= len; i++)
		cnt[ch[i]-'a']++;
	int mx = 0, mn = 1<<30;
	for (int i = 0; i < 26; i++) {
		mx = max(mx, cnt[i]);
		if (cnt[i]) mn = min(mn, cnt[i]);
	}
	if (isPrime(mx-mn)) printf("Lucky Word\n%d\n", mx-mn);
	else puts("No Answer\n0");
	return 0;
}
