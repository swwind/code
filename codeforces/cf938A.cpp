#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char ch[N];
bool check(char c) {
  return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}
int main(int argc, char const *argv[]) {
  int n = read();
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++)
    (!check(ch[i]) || !check(ch[i - 1])) && putchar(ch[i]);
  puts("");
  return 0;
}