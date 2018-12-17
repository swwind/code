#include <cstdio>
using namespace std;
int x, y, fa[200], a, b, z;
int find(int x){
	return x==fa[x] ? x : fa[x] = find(fa[x]);
}
int gcd(int a, int b){
	return a%b ? gcd(b, a%b) : b;
}
int main(){
	scanf("%d%d%d", &x, &y, &z);
	for(int i = 1; i <= x; i++)fa[x] = x;
	for(int i = 0; i < y; i++)scanf("%d%d", &a, &b), fa[find(a)]=find(b);
	for(int i = 0; i < z; i++)scanf("%d%d", &a, &b), puts(find(a)==find(b) ? "Yes" : "No");
	return 0; 
}

