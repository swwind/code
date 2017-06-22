/*
# Translate

# Sample Input
```
for i in range(1, 50) # [1, 50)
	ans = ans + i
print ans
```
*/
#include <bits/stdc++.h>
#define N 2005
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int main(){
	return 0;
}
