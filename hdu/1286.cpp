#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int phi[N], pri[N], cnt;
bool mark[N];
int main(int argc, char const *argv[]){
	phi[1] = 1;
	for(int i = 2; i < N; i++){
		if(!mark[i]) pri[++cnt] = i, phi[i] = i-1;
		for(int j = 1; j <= cnt && i*pri[j] < N; j++){
			mark[i*pri[j]] = 1;
			if(i%pri[j]) phi[i*pri[j]] = phi[i]*(pri[j]-1);
			else{phi[i*pri[j]] = phi[i]*pri[j]; break;}
		}
	}
	int T = read();
	while(T--){
		int n = read();
		printf("%d\n", phi[n]);
	}
	return 0;
}