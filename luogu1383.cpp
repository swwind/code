// 太复杂，哎。
#include <bits/stdc++.h>
using namespace std;
char ch[100020];
int cnt, n;
int main(){
	scanf("%d", &n);
	while(n--){
		char op = getchar();
		while(op<'A'||op>'Z') op=getchar();
		char x; int k;
		switch(op){
			case 'T':
				x = getchar();
				while(x==' ') x=getchar();
				ch[++cnt] = x;
				break;
			case 'U':
				scanf("%d", &k);
				cnt = max(0, cnt-k);
				break;
			case 'Q':
				scanf("%d", &k);
				putchar(ch[k]);
				puts("");
				break;
		}
	}
	return 0;
}