#include <cstdio>
#include <algorithm>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int main() {
  int a = read(); // ((
  int b = read(); // ()
  int c = read(); // )(
  int d = read(); // ))

  printf("%d\n", (!a && !d && !c) || (a == d && a > 0));
}

/**
--------
-----------
--------------
  ---
  -------
  ----------
     -----------

*/