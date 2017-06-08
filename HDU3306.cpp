#include <cstdio>
#include <cstring>
#define mod 10007
using namespace std;
struct node{
	int num[4][4];
	node(){memset(num, 0, sizeof num);}
	node(int x, int y){
		memset(num, 0, sizeof num);
		num[0][0] = num[0][1] = num[2][1] = 1;
		num[1][1] = x*x%mod; num[1][2] = y*y%mod;
		num[1][3] = 2*x*y%mod;
		num[3][1] = x; num[3][3] = y;
	}
	node(bool flag){
		memset(num, 0, sizeof num);
		for(int i = 0; i < 4; i++)
			num[i][i] = 1;
	}
};
node operator * (const node &a, const node &b){
	node c;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				c.num[i][j] = (c.num[i][j] + a.num[i][k]*b.num[k][j])%mod;
	return c;
}
int a, b, c;
int main(){
	while(scanf("%d%d%d", &a, &b, &c) != EOF){
		node tmp(b%mod, c%mod), ans(true);
		while(a){
			if(a&1)ans=tmp*ans;
			tmp=tmp*tmp;
			a >>= 1;
		}
		int sum = 0;
		for(int i = 0; i < 4; i++)
			sum = (sum + ans.num[0][i])%mod;
		printf("%d\n", sum);
	}
}
