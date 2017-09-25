#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
string str;
int len, miku[N], m, ansl, ansr, ans;
char pas[N];
bool isLetter(char c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
void search(int l, int r) {
	while (l > 0 && r <= m)
		if (pas[l--] != pas[r++])
			break;
	if (l > 0 || r <= m) l++, r--;
	if (r-l+1 > ans) {
		ans = r-l+1;
		ansl = miku[l];
		ansr = miku[r];
	}
}
int main(int argc, char const *argv[]) {
	while (getline(cin, str)) {
		len = str.length(); m = 0; ans = 0;
		for (int i = 0; i < len; i++)
			if (isLetter(str[i])) {
				pas[++m] = toupper(str[i]);
				miku[m] = i;
			}
		for (int i = 1; i <= m; i++) {
			search(i, i);
			search(i, i+1);
		}
		printf("%d\n", ans);
		for (int i = ansl; i <= ansr; i++)
			putchar(str[i]);
		puts("");
	}
	return 0;
}
