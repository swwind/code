#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, mx, a[100005], cnt[1000005], s[1000005];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", a+i);
		cnt[a[i]]++;
		mx = max(a[i], mx);
	}
	for(int i = 1; i <= mx; i++)
	    if(cnt[i])for(int j = i; j <= mx; j += i)
		    s[j] += cnt[i];
	for(int i = 1; i <= n; i++)
	    printf("%d\n", s[a[i]]-1); 
	return 0;
}
