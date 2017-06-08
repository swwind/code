#include <bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
int b[N], a[N], add[N], pos[N], n, m, block;
char ch[5]; int x, y, z;
void reset(int x){
    int l=(x-1)*block+1,r=min(x*block,n);
    for(int i=l;i<=r;i++)
        b[i]=a[i];
    sort(b+l,b+r+1);
}
int find(int x, int v){
	int l = (x-1)*block+1, r = min(x*block, n);
	int R = r;
	while(l<=r){
		int mid = l + r >> 1;
		if(b[mid] < v) l = mid+1;
		else r = mid-1;
	}
	return R-l+1;
}
void adds(int l, int r, int v){
	if(pos[l] == pos[r])
		for(int i = l; i <= r; i++)
			a[i] += v;
	else{
		for(int i = l; i <= pos[l]*block; i++) a[i] += v;
		for(int i = (pos[r] -1)*block +1; i <= r; i++) a[i] += v;
	}
	reset(pos[l]), reset(pos[r]);
	for(int i = pos[l] + 1; i < pos[r]; i++)
		add[i] += v;
}
int ask(int l, int r, int v){
	int sum = 0;
	if(pos[l] == pos[r])
		for(int i = l; i <= r; i++)
			if(a[i]+add[pos[i]] >= v) sum++;else;
	else{
		for(int i = l; i <= pos[l]*block; i++)
			if(a[i]+add[pos[i]] >= v) sum++;
		for(int i = (pos[r]-1)*block+1; i<= r; i++)
			if(a[i]+add[pos[i]] >= v) sum++;
	}
	for(int i = pos[l] + 1; i < pos[r]; i++)
		sum += find(i, v - add[i]);
	return sum;
}
int main(){
	int q;
	scanf("%d%d", &n, &q);
	block = (int) sqrt(n);
	for(int i = 1; i <= n; i++){
		scanf("%d", a+i);
		pos[i] = (i-1)/block+1;
		b[i] = a[i];
	}
	if(n%block) m = n/block +1;
	else m = n/block;
	for(int i = 1; i <= m; i++) reset(i);
	for(int i = 1; i <= q; i++){
		scanf("%s%d%d%d", ch, &x, &y, &z);
		if(ch[0] == 'M') adds(x, y, z);
		else printf("%d\n", ask(x, y, z));
	}
	return 0;
}

