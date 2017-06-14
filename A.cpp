#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
unsigned long long a1[1002],b1[1002],ans=0;
int k=1,l=1;
long long mod=10000000000;
bool pd(){
	int i;
	for(i=1;i<=max(l,k);i++)
		if(a1[i]!=b1[i]) break;
	if(i>max(l,k))return 1;
	else return 0;
}
void jian(){
	for(int i=1;i<=max(l,k);i++){
		if(a1[i]<b1[i]){
			a1[i]+=mod;
			a1[i+1]--;
		}
		a1[i]-=b1[i];
	}
}
void diva(){
	for(int i=k;i>1;i--){
		a1[i-1]+=(a1[i]%2)*mod;
		a1[i]/=2;
	}
	a1[1]/=2;
		   
}
void divb(){
	for(int i=l;i>1;i--){
		b1[i-1]+=(b1[i]%2)*mod;
		b1[i]/=2;
	}
	b1[1]/=2;
}
void gcd(){
	if(pd()==1)return;
	while(a1[1]%2==0&&b1[1]%2==0){
		diva();
		divb();
		ans++;
	}
	while(a1[1]%2==0)diva();
	while(b1[1]%2==0)divb();
	if(pd()==1)return ;
	while(a1[k]==0)k--;
	while(b1[l]==0)l--;
	int i=max(k,l);
	while(a1[i]==b1[i])i--;
	if(a1[i]>b1[i])jian();
	else{
		for(;i>=1;i--)
			swap(a1[i],b1[i]);
		swap(k,l);
		jian();
	}
	gcd();
}
int main(){
	char a[10001],b[10001];
	scanf("%s%s",a,b);
	int lena=strlen(a);
	int lenb=strlen(b);
	//memset(a1,0,sizeof(a1));
	//memset(b1,0,sizeof(b1));
	for(int i=lena-1,t=1;i>=0;i--,t*=10){
		int x=a[i]-'0';
		a1[k]+=x*t;
		if((lena-i)%10==0){
			k++;t=1;
		}
	}
	for(int i=lenb-1,t=1;i>=0;i--,t*=10){
		int x=b[i]-'0';
		b1[l]+=x*t;
		if((lenb-i)%10==0){
			l++;t=1;
		}
	}
	gcd();
	for(int i=1;i<=ans;i++){
		for(int j=k;j>=1;j--){
			a1[i]*=2;
			a1[i+1]+=a1[i]/mod;
			a1[i]%=mod;
		}
		if(a[k+1]>0)k++;
	}
	while(a1[k]==0)k--;
	cout<<a1[k];
	k--;
	for(;k>=1;k--)printf("%09d",a1[k]);
	return 0;
}