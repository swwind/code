#include <bits/stdc++.h>
using namespace std;
char a[5000], b[5000];
void dfs(int l1, int l2, int l3, int l4){
	if(l1 > l2 || l3 > l4) return;
	for(int i = l1; i <= l2; i++) if(a[i] == b[l3])
		dfs(l1, i-1, l3+1, l3+i-l1),
		dfs(i+1, l2, l3+i-l1+1, l4),
		printf("%c", a[i]);
}
int main(){
	scanf("%s%s", a, b);
	int l = strlen(a);
	dfs(0, l-1, 0, l-1);
	return 0;
}
