#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
int a[20], n, T, ans1, ans2, minn;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", a+i);
		sort(a, a+n);
		ans1 = ans2 = 0;
		if(n&1)
			ans1 = a[0], a[0] = inf, n--;
		else{
			minn = 1;
			for(int i = 1; i < n; i++)
				if(a[i] - a[i-1] <= a[minn] - a[minn-1])
					minn = i;
			ans1 = a[minn];
			ans2 = a[minn-1];
			a[minn] = a[minn-1] = inf;
			n -= 2;}
		while(n){
			sort(a, a+n+2);
			ans1 = ans1*10+a[0];
			ans2 = ans2*10+a[n-1];
			n-=2;
		}
		printf("%d\n", ans1-ans2);
	}
	return 0;
}

