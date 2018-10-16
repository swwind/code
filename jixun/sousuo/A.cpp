#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
string str[8];
vector<int> a[51];
struct node {
	char ch[32][32];
	int x, y;
	void clear(){memset(ch, 0, sizeof ch);}
	node(){clear();x=y=1;}
	char* operator [] (int a) {return ch[a];}
	friend bool operator < (node a, node b) {
		for (int j = 0; j < 32; j++)
			if (a[1][j] != b[1][j])
				return a[1][j] < b[1][j];
		if (a.y != b.y) return a.y < b.y;
		for (int i = 2; i < 32; i++)
			for (int j = 0; j < 32; j++)
				if (a[i][j] != b[i][j])
					return a[i][j] < b[i][j];
		return false;
	}
	void output() {
		for (int i = 1; i <= x; i++, puts(""))
			for (int j = 1; j <= y; j++)
				putchar(ch[i][j] ? ch[i][j] : '.');
	}
}as,bs;
int vis[8];
void dfs(int type, int st, int stx, int sty, int nxt) {
	// printf("dfs(%d, %d, %d, %d, %d)\n", type, st, stx, sty, nxt);
	if (nxt == 7) {
		// as.output();
		if (bs[0][0] == char(5000) || as < bs)
			bs = as;
		return;
	}
	node r = as;
	if (type == 1) {
		for (auto k : a[st]) {
			if (vis[k]) continue;
			int flag = 0;
			for (int i = 0; i < str[k].length(); i++)
				if (as[stx][sty+i] && as[stx][sty+i] != str[k][i])
					flag = 1;
			if (flag) continue;
			as.y = max<int>(as.y, sty+str[k].length()-1);
			if (nxt > 3 && as.y != r.y) continue;
			if (nxt == 5 && sty+str[k].length()-1 != as.y) continue;
			for (int i = 0; i < str[k].length(); i++)
				as[stx][sty+i] = str[k][i];
			vis[k] = 1;
			// as.output();
			if (nxt == 3)
				dfs(2, as[1][1]-'A', 1, 1, nxt+1);
			else
				dfs(2, str[k][str[k].length()-1]-'A', stx, sty+str[k].length()-1, nxt+1);
			as = r;
			vis[k] = 0;
		}
	} else {
		for (auto k : a[st]) {
			if (vis[k]) continue;
			int flag = 0;
			for (int i = 0; i < str[k].length(); i++)
				if (as[stx+i][sty] && as[stx+i][sty] != str[k][i])
					flag = 1;
			if(flag) continue;
			as.x = max<int>(as.x, stx+str[k].length()-1);
			if (nxt > 4 && as.x != r.x) continue;
			if (nxt == 6 && stx+str[k].length()-1 != as.x) continue;
			for (int i = 0; i < str[k].length(); i++)
				as[stx+i][sty] = str[k][i];
			vis[k] = 1;
			// as.output();
			dfs(1, str[k][str[k].length()-1]-'A', stx+str[k].length()-1, sty, nxt+1);
			vis[k] = 0;
			as = r;
		}
	}
}
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= 6; i++) {
		cin >> str[i];
		a[str[i][0]-'A'].push_back(i);
	}
	bs[0][0] = char(5000);
	for (int i = 0; i < 26; i++)
		if (a[i].size() >= 2)
			dfs(1, i, 1, 1, 1);
	if (bs.x == 1 && bs.y == 1) puts("Impossible");else
	bs.output();
	return 0;
}
