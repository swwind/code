// 12.16 我的生日 私の誕生日です My birthday
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
struct node{
	int st, ed, id, op;
	friend bool operator < (const node &a, const node &b) {
		return a.op > b.op;
	}
}s[N];
priority_queue<node> q;
bool cmp(node a, node b) {
	return a.st < b.st;
}
int a, b, c, d, t, n;
int main(int argc, char const *argv[]) {
	while (~scanf("%d%d%d%d", &a, &b, &c, &d))
		s[++n] = (node){b, c, a, d};
	sort(s+1, s+n+1, cmp);
	int k = 1;
	for (int i = 1; i <= n; i++) {
		while (s[k].st <= t)
			q.push(s[k++]);
		if (q.empty()) {
			t = s[k].st;
			q.push(s[k++]);
			while (s[k].st == s[k-1].st)
				q.push(s[k++]);
		}
		node g = q.top(); q.pop();
		printf("%d %d\n", g.id, t += g.ed);
	}
	return 0;
}