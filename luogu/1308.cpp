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
void upper(string &s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'a') s[i] = s[i]-'a'+'A';
}
string ctc, str;
int ans, len, pos = -1;
int main(int argc, char const *argv[]) {
	getline(cin, ctc);
	upper(ctc);
	getline(cin, str);
	upper(str);
	len = str.length();
	for (int i = 0, j = 0; i <= len; i++)
		if (i == len || str[i] == ' ') {
			if (str[i-1] != ' ' && ctc == str.substr(j, i-j)) {
				ans ++;
				if (!~pos)
					pos = j;
			}
			j = i+1;
		}
	if (ans) printf("%d %d\n", ans, pos);
	else puts("-1");
	return 0;
}