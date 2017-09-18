#include <map>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define M 200200  
#define id(a, b) (a*n+b)
using namespace std;  
struct abcd{  
	int to,next;  
}table[M<<1];  
int head[M],tot;  
int n,ans;  
int max_dpt[M];  
map<int,int>e;  
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
void ins(int x,int y)  
{  
	table[++tot].to=y;  
	table[tot].next=head[x];  
	head[x]=tot;  
}  
void dfs(int x,int f)  
{  
	// printf("%d -> %d\n", x, f);
	int i;  
	max_dpt[x]=1;  
	for(i=head[x];i;i=table[i].next)  
	{  
		if(table[i].to==f)  
			continue;  
		dfs(table[i].to,x);  
		ans=max(ans,max_dpt[x]+max_dpt[table[i].to]);  
		max_dpt[x]=max(max_dpt[x],max_dpt[table[i].to]+1);  
	}  
}  
void Sort(int &x,int &y,int &z)  
{  
	int _x=min(min(x,y),z);  
	int _z=max(max(x,y),z);  
	int _y=x+y+z-_x-_z;  
	x=_x;y=_y;z=_z;  
}  
int main()  
{  
	int i,x,y,z;  
	map<int,int>::iterator it;  
	n=read()-2;
	for(i=1;i<=n;i++)  
	{  x=read();y=read();z=read();
		Sort(x,y,z);          
		if(it=e.find(id(x,y)),it!=e.end())  
			ins(it->second,i),ins(i,it->second),e.erase(it);  
		else  
			e[id(x,y)]=i;  
		if(it=e.find(id(x,z)),it!=e.end())  
			ins(it->second,i),ins(i,it->second),e.erase(it);  
		else  
			e[id(x,z)]=i;  
		if(it=e.find(id(y,z)),it!=e.end())  
			ins(it->second,i),ins(i,it->second),e.erase(it);  
		else  
			e[id(y,z)]=i;  
	}  
	dfs(1,0);  
	cout<<ans<<endl;  
	return 0;  
}  