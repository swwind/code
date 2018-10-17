#include <bits/stdc++.h>
#include <ext/rope>
#define N 2000050
using namespace std;
using namespace __gnu_cxx;
int n, now, x, len;
rope<char> a, b, tmp;
char s[N], rs[N];
int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		switch(s[0]){
			case 'M':scanf("%d", &now);break;
			case 'P':now--;break;
			case 'N':now++;break;
			case 'G':printf("%c\n", a[now]);break;
			case 'I':
				scanf("%d", &x);
				len = a.length();
				for(int i = 0; i < x; i++){
					s[i] = getchar();
					while(s[i] == '\n')
						s[i] = getchar();
					rs[x-i-1] = s[i];
				}
				rs[x] = s[x] = 0;
				a.insert(now, s);
				b.insert(len-now, rs);
				break;
			case 'D':
				scanf("%d", &x);
				len = a.length();
				a.erase(now, x);
				b.erase(len-now-x, x);
				break;
			case 'R':
				scanf("%d", &x);
				len = a.length();
				tmp=a.substr(now, x);
				a = a.substr(0, now) + b.substr(len-now-x,x) + a.substr(now+x, len-now-x);
				b = b.substr(0, len-now-x) + tmp + b.substr(len-now, now);
				break;
		}
	}
	return 0;
}
