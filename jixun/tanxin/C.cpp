#include <bits/stdc++.h>
#define N 1000020
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
ll tmp, ans;
int main(int argc, char const *argv[]) {
	scanf("%s", ch + 1);
	int len = strlen(ch + 1);
	for (int i = 1; i <= len; i++)
		if (i == 1 || ch[i] ^ ch[i - 1]) a[++cnt] = 1;
		else                             a[cnt] = 0;
	if (ch[1] == ch[len])
		a[1] = 0, --cnt;
	for (int i = 1; i <= cnt; i++) {
		if (a[i]) ++ tmp;
		else ans += (tmp >> 1) + 1, tmp = 0;
	}
	cout << ans + (tmp >> 1) << endl;
	return 0;
}