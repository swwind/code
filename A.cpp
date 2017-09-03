#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
char ch[N];
int a[N], cnt;
int main(int argc, char const *argv[]){
	int n = read(), sum = 0;
	scanf("%s", ch+1); n = strlen(ch+1);
	if(n == 1 && ch[1] == '0') return puts("0\n0\n0");
	for(int i = 1; i <= n; i++){
		sum += ch[i]-'0';
		printf("%c%c", ch[i], i == n ? '\n' : '+');
	}
	for(;sum;sum/=10)a[++cnt]=sum%10;
	sum = 0; if(!cnt) cnt++;
	for(int i = cnt; i; i--){
		sum += a[i];
		printf("%d%c", a[i], i == 1?'\n':'+');
	} cnt = 0;
	for(;sum;sum/=10)a[++cnt]=sum%10;
	sum = 0; if(!cnt) cnt++;
	for(int i = cnt; i; i--){
		sum += a[i];
		printf("%d%c", a[i], i == 1?'\n':'+');
	} cnt = 0;
	return 0;
}
