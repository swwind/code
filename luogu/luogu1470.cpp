#include <bits/stdc++.h>
using namespace std;
int n, f[200005];
string str;
char ch[203][12], ss[200005];
int check(int a, int b){
	if(a+(int)strlen(ch[b]) > str.length()) return 0;
	for(int i = 0; i < (int)strlen(ch[b]); i++)
		if(str[a+i]!=ch[b][i]) return 0;
	return 1;
}
int dfs(int x){
	if(f[x]) return f[x];
	int len = 0;
	for(int i = 0; i < n; i++)
		if(check(x, i))
			len = max(len, dfs(x+(int)strlen(ch[i])) + (int)strlen(ch[i]));
	return f[x] = len;
}
int main(){
	while(scanf("%s", ch[n]) && ch[n][0] != '.') n++;
	while(scanf("%s", ss)!=EOF) str += ss;
	printf("%d", dfs(0));
	return 0;
}

