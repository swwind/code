#include <bits/stdc++.h>
#define N 40020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int p[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
struct node {
	string w;
	int val;
	friend bool operator < (const node &a, const node &b) {
		return a.val == b.val ? a.w < b.w : a.val > b.val;
	}
}ans[N];
map<string,int>mp;
int cnt[N][30], n;
int calc(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
		sum += p[str[i]-'a'];
	return mp[str] = sum;
}
int calc(string str, int x) {
	memset(cnt[x], 0, sizeof(cnt[x]));
	for (int i = 0; i < str.size(); i++)
		cnt[x][str[i]-'a']++;
	for (int i = 0; i < 26; i++)
		if (cnt[x][i] > cnt[0][i]) return 0;
	return 1;
}
int calc(int i, int j) {
	for(int k = 0; k < 26; k++)
		if(cnt[i][k] + cnt[j][k] > cnt[0][k])
			return 0;
	return 1;
}
int main(int argc, char const *argv[]) {
	string str; cin >> str; calc(str, 0);
	while(cin >> str) {
		if (str == ".") break;
		if (calc(str, ++n)) {
			ans[n].w = str;
			ans[n].val = calc(str);
		} else --n;
	}
	int tot = n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (calc(i, j)) {
				string qwq = ans[i].w < ans[j].w
					? (ans[i].w + " " + ans[j].w)
					: (ans[j].w + " " + ans[i].w);
				if (mp[qwq]) continue;
				mp[qwq] = 1;
				ans[++tot].w = qwq;
				ans[tot].val = ans[i].val + ans[j].val;
			}
	sort(ans+1, ans+tot+1);
	printf("%d\n", ans[1].val);
	int pos = 1;
	while (pos <= n && ans[pos].val == ans[1].val)
		cout << ans[pos++].w << endl;
	return 0;
}