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
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int>> p;
int a[N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1, k = 1; i <= m; i++) {
		int b = read();
		while (k <= b) {
			q.push(a[k++]);
			if (q.size() == i){
				p.push(q.top());
				q.pop();
			}
		}
		printf("%d\n", p.top());
		q.push(p.top());
		p.pop();
	}
	return 0;
}