#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#define MOD 100003
#define N 200005
using namespace std;
int n, m, dis[N];
queue<int> q;
vector<int> mp[N];
int bo[N], count[N], x, y;
int main(){
	memset(dis, 1, sizeof dis);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &x, &y),
		mp[x].push_back(y),
		mp[y].push_back(x);
	bo[1] = count[1] = 1;
	dis[1] = 0;
	q.push(1);
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(int i = 0; i < mp[now].size(); i++){
			int nn = mp[now][i];
			if(dis[now] + 1 < dis[nn]){
				dis[nn] = dis[now] + 1;
				count[nn] = count[now] % MOD;
				if(!bo[nn])
					bo[nn] = 1,
					q.push(nn);
			}
			else
				if(dis[now] + 1 == dis[nn])
					count[nn] = (count[nn] + count[now]) % MOD;
		}
		bo[now] = 0;
	}
	for(int i = 1; i <= n; i++)
		if(count[i] != count[0])
			printf("%d\n", count[i]);
		else printf("0\n");
	return 0;
}
