#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string str = "";
ll f(){
	ll ans = 1, k = 1, tmp = 0;
	while(k < n*2-1){
		int flag = 0;tmp = 0;
		if(str[k]==' '){ans=ans*10+str[k+1]-'0';k+=2;continue;}
		if(str[k]=='+') flag = 1;
		tmp = str[k+1]-'0';
		while(str[k+2]==' '&&k<n*2-1) tmp=tmp*10+str[k+3]-'0', k+=2;
		k+=2;
		if(flag) ans+=tmp;
		else ans-=tmp;
	}
	return ans;
}
void dfs(int x){
	if(x==(n-1)*2+1)
		if(!f()) cout<<str<<endl;else;
	else{
		str[x] = ' ', dfs(x+2);
		str[x] = '+', dfs(x+2);
		str[x] = '-', dfs(x+2);
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++) str += '0' + i, str += ' ';
	str += '0' + n;
	dfs(1);
	return 0;
}
