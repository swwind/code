#include <bits/stdc++.h>
#define N 150020
using namespace std;
struct Node{
	int L, T;
	bool operator < (const Node &p) const {
		return L < p.L;
	}
}a[N];
priority_queue<int> sw;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].T, &a[i].L);
	sort(a+1, a+n+1);
	int total = 0, ans = 0;
	for(int i = 1; i <= n; i++)
		if(a[i].T + total <= a[i].L){
			sw.push(a[i].T);
			total += a[i].T;
			++ans;
		}
		else if(a[i].T < sw.top()) {
			total -= sw.top(); sw.pop();
			sw.push(a[i].T); total += a[i].T;
		}
	printf("%d\n", ans);
	return 0;
}
