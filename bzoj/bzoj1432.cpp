#include <cstdio>
using namespace std;
int n, k;
int min(int a, int b){
	return a > b ? b : a;
}
int main(){
	scanf("%d%d", &n, &k);
	printf("%d", n == 1 ? 1 : (min(k, n - k + 1) << 1));
}
