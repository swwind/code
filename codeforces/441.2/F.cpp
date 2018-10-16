#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
using namespace std;
int l[500000],r[500000],a[500000],f[100],ans,d,z[500000],n;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++){
		while(a[i]>=a[z[d]]&&d>0)d--;l[i]=z[d]+1;z[++d]=i;
		for(int j=0;j<=31;j++)
			if(a[i]&(1<<j))f[j]=i;
				else l[i]=max(l[i],f[j]+1);
	}
	for(int i=0;i<=31;i++)f[i]=n+1;d=0;z[0]=n+1;
	for(int i=n;i>=1;i--){
		while(a[i]>a[z[d]]&&d>0)d--;r[i]=z[d]-1;z[++d]=i;
		for(int j=0;j<=31;j++)
			if(a[i]&(1<<j))f[j]=i;
				else r[i]=min(r[i],f[j]-1);
	}
	for(int i=1;i<=n;i++)ans+=(i-l[i]+1)*(r[i]-i+1);
	printf("%I64d",(n*(n+1)/2-ans));
}
