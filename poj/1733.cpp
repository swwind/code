
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;
const int N=10010;
int father[N],relation[N],k=1;
void init(){
	for(int i=0;i<N;++i){
		father[i]=i;
		relation[i]=0;
	}
}
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
int find(int x){
	int fx=father[x];
	if(x!=father[x]){
		father[x]=find(father[x]);
		relation[x]=(relation[fx]+relation[x])%2;
	}
	return father[x];
}
bool Union_Set(int x,int y,int d){
	int rootx=find(x);
	int rooty=find(y);
	if(rootx!=rooty){
		father[rooty]=rootx;
		relation[rooty]=(relation[x]+d-relation[y]+2)%2;
		return true;
	}
	else{
		if((relation[x]+relation[y])%2==d)
			return true;
		return false;
	}
}
int main(){
	int len,n;
	scanf("%d%d",&len,&n);
	init();
	map<int,int> mp;
	int x,y,a,b;
	string ss;
	bool flag=true;
	int value=n;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a,&b);
		cin>>ss;
		x=min(a,b);
		y=max(a,b);
		if(!flag){
		continue;
		}
		x--;
		if(mp.find(x)==mp.end()){
			{mp[x]=k++;}
		}
		int mx=mp[x];
		if(mp.find(y)==mp.end()){
			{mp[y]=k++;}
		}
		int my=mp[y];
		int d;
		if(ss=="even")d=0;
		else d=1;
		flag=Union_Set(mx,my,d);
		if(flag==false){
		 value=i-1;
		}
	}
	printf("%d\n",value);
	return 0;
}
