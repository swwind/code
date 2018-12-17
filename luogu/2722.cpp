#include <iostream>
using namespace std;
int t,m,w[100001],v[100001],f[100001];
int main(){
	cin >> t >> m;
	for(int i = 1; i <= m; i++)
		cin >> v[i] >> w[i];
	for(int i = 1; i <= m; i++)
		for(int j = w[i]; j <= t; j++)
			if(f[j] <= f[j-w[i]] + v[i])
				f[j] = f[j-w[i]] + v[i];//转换方程式
	cout << f[t] << endl;
	return 0;
}

