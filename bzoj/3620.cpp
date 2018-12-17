#include <bits/stdc++.h>
#define N 15007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char ch[N];
int nxt[N], ans;
int main(){
	scanf("%s", ch+1);
	int len = strlen(ch+1), k = read();
	for(int st = 1; st <= len-k*2; st++){
		nxt[st] = st-1;
		for(int i = st+1, j = st-1; i <= len; i++){
			while(j > st-1 && ch[j+1] != ch[i]) j = nxt[j]; 
			if(ch[j+1] == ch[i]) j++; nxt[i] = j;
		}
		for(int i = st+k*2, j = i; i <= len; j = ++i){
			while((nxt[j]-st+1)*2 >= i-st+1) j = nxt[j];
			if(nxt[j]-st+1 >= k) ans++;
		}
	}
	printf("%d\n", ans);
}