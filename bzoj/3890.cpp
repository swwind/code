#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int to, next, w1, w2;
}e[5000];
bool f1[105][10005], f2[105][10005];
int n, m, x, y, f, l, tot, head[105];
void ins(int a, int b, int c, int d){
	e[++tot] = (node){b, head[a], c, d};
	head[a] = tot;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d%d", &x, &y, &f, &l);
		ins(x, y, f, l);
	}
	f1[1][0] = f2[1][0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = head[i]; j; j = e[j].next){
			for(int k = e[j].w1; k < 10000; k++) f1[e[j].to][k] |= f1[i][k-e[j].w1];
			for(int k = e[j].w2; k < 10000; k++) f2[e[j].to][k] |= f2[i][k-e[j].w2];
		}
	}
	for(int i = 1; i < 10000; i++)
		if(f1[n][i] && f2[n][i]) return printf("%d", i)*0;
	return puts("IMPOSSIBLE")*0;
}

