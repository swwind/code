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
struct node {
	int st, ed, id, op;
	friend bool operator < (const node &a, const node &b) {
		return a.op == b.op ? a.st > b.st : a.op < b.op;
	}
}k,tmp;
priority_queue<node> q;
int now;
int main(int argc, char const *argv[]) {
	while (~scanf("%d%d%d%d", &k.id, &k.st, &k.ed, &k.op))
		if (q.empty()) q.push(k), now = k.st;
		else {
			while (!q.empty()) {
				tmp = q.top(); q.pop();
				now = max(now, tmp.st);
				if (k.st - now >= tmp.ed)
					printf("%d %d\n", tmp.id, now += tmp.ed);
				else if (tmp.op >= k.op){
					q.push(tmp);
					break;
				} else {
					tmp.ed -= k.st - now;
					now = k.st;
					q.push(tmp);
					break;
				}
			}
			q.push(k);
		}
	while (!q.empty()) {
		tmp = q.top(); q.pop();
		printf("%d %d\n", tmp.id, now += tmp.ed);
	}
	return 0;
}