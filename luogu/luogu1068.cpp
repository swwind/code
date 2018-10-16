#include <bits/stdc++.h>
using namespace std;
struct node{
	int id, score;
	bool operator < (const node &b) const {
		return score == b.score ? id < b.id : score > b.score;
	}
}a[5020];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].id, &a[i].score);
	sort(a+1, a+n+1);
	m += m>>1;
	int tmp = a[m].score;
	while(a[m+1].score == tmp) m++;
	printf("%d %d\n", tmp, m);
	for(int i = 1; i <= m; i++)
		printf("%d %d\n", a[i].id, a[i].score);
	return 0;
}