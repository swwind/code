#include <bits/stdc++.h>
#define N 5000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
char ch[N];
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 0; i < n; i += 72)
		scanf("%s", ch+i);
	int i = 0, j = 1;
	while(i < n && j < n){
		int k = 0;
		while(ch[(i+k)%n] == ch[(j+k)%n] && k < n) k++;
		if(k == n) break;
		ch[(i+k)%n] > ch[(j+k)%n] ? (i = i+k+1) : (j = j+k+1);
		i == j && ++j;
	}
	printf("%d\n", min(i, j));
	return 0;
}
