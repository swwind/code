#include <cstdio>
#include <algorithm>
#define N 300020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

char str[N];

int main() {

  int n = read();
  scanf("%s", str + 1);

  if (n & 1) return puts(":("), 0;

  if (str[1] == ')') return puts(":("), 0;
  if (str[n] == '(') return puts(":("), 0;
  str[1] = '(';
  str[n] = ')';

  int l = 0, r = 0;
  for (int i = 2; i < n; ++ i) {
    if (str[i] == '(') ++ l;
    if (str[i] == ')') ++ r;
  }
  l = (n-2)/2 - l;
  r = (n-2)/2 - r;
  if (l < 0 || r < 0) return puts(":("), 0;
  int suck = 0;
  for (int i = 2; i < n; ++ i) {
    if (str[i] == '?') {
      if (l) {
        -- l;
        str[i] = '(';
      } else {
        -- r;
        str[i] = ')';
      }
    }

    if (str[i] == '(') ++ suck;
    else -- suck;
    if (suck < 0) return puts(":("), 0;
  }

  puts(str+1);

}