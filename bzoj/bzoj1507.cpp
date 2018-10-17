#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
crope rp;
char ch[3000020], op[50];
int main(){
	int t, pos=0;
	scanf("%d\n", &t);
	while(t--){
		scanf("%s", op);
		int x;
		switch(op[0]){
			case 'M':scanf("%d", &pos);break;
			case 'P':pos--;break;
			case 'N':pos++;break;
			case 'I':
				scanf("%d", &x);
				for(int i = 0; i < x; i++){
					ch[i] = getchar();
					while(ch[i] == '\n')
						ch[i]=getchar();
				}
				ch[x] = '\0';
				rp.insert(pos, ch);
			break;
			case 'D':scanf("%d", &x);rp.erase(pos, x);break;
			case 'G':scanf("%d", &x);rp.copy(pos, x, ch);ch[x]='\0';puts(ch);
		}
	}
}