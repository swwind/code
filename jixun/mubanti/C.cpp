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
char str[N];
int main(int argc, char const *argv[]) {
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	sort(str + 1, str + len + 1);
	do printf("%s\n", str + 1);
	while (next_permutation(str + 1, str + len + 1));
	return 0;
}
