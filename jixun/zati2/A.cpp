#include <bits/stdc++.h>
#define N 120
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int> son[N];
int main(int argc, char const *argv[]) {
	int n = read(), t = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		son[x].push_back(read());
	}
	for (int i = 1; i <= t; i++) {
		sort(son[i].begin(), son[i].end(), greater<int>());
		for (int j = 0; j < son[i].size(); j += 2)
			if (j + 1 < son[i].size())
				son[i + 1].push_back(son[i][j] + son[i][j + 1]);
			else
				son[i + 1].push_back(son[i][j]);
	}
	printf("%d\n", son[t][0]);
	return 0;
}