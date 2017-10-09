#include <bits/stdc++.h>
#define N 120
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
string str[N], reg;
int len, sum, ans[N];
bool match(int x, int y) {
	return reg.substr(x, len) == str[y];
}
int find(int x) {
	for (int i = len; i; i--)
		if (match(i, x)) return i%len;
	return -1;
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++)
		cin >> str[i];
	len = str[1].length();
	for (int i = 1; i <= n; i++)
		if (str[i].length() != len)
			return puts("-1")&0;
	reg = str[1]+str[1];
	for (int i = 1; i <= n; i++)
		if (find(i) == -1)
			return puts("-1")&0;
	int ans = 1<<30;
	for (int i = 1; i <= len*2; i++) {
		reg = reg.substr(1)+reg[0];
		int tmp = 0;
		for (int j = 1; j <= n; j++)
			tmp += (len-find(j))%len;
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}