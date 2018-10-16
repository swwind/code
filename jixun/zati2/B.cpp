#include <bits/stdc++.h>
#define N 800020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
string str[N >> 3], ntr[N >> 3];
int ans[N >> 3], sum;
namespace AC_tree {
	int ch[N][26], cnt = 1;
	vector<int> son_str[N], son_ntr[N];
	void push_str(int id) {
		int now = 1, len = str[id].length();
		for (int i = 0; i < len; i++) {
			if (!ch[now][str[id][i] - 'a'])
				ch[now][str[id][i] - 'a'] = ++ cnt;
			now = ch[now][str[id][i] - 'a'];
		}
		son_str[now].push_back(id);
	}
	void push_ntr(int id) {
		int now = 1, len = ntr[id].length();
		for (int i = 0; i < len; i++) {
			if (!ch[now][ntr[id][i] - 'a'])
				break;
			now = ch[now][ntr[id][i] - 'a'];
		}
		son_ntr[now].push_back(id);
	}
	void dfs(int x, int dep) {
		for (int i = 0; i < 26; i++) {
			if (ch[x][i]) {
				dfs(ch[x][i], dep + 1);
				for (auto s : son_str[ch[x][i]])
					son_str[x].push_back(s);
				for (auto s : son_ntr[ch[x][i]])
					son_ntr[x].push_back(s);
				son_str[ch[x][i]].clear();
				son_ntr[ch[x][i]].clear();
			}
		}
		int s = min(son_str[x].size(), son_ntr[x].size());
		while (s --) {
			int a = son_str[x].back();
			int b = son_ntr[x].back();
			son_str[x].pop_back();
			son_ntr[x].pop_back();
			ans[a] = b;
			sum += dep;
		}
	}
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		AC_tree::push_str(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> ntr[i];
		AC_tree::push_ntr(i);
	}
	AC_tree::dfs(1, 0);
	printf("%d\n", sum);
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", i, ans[i]);
	return 0;
}
