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
int get(char c) {
  if (c == 'i' || c == 'I' || c == 'L' || c == 'l')
    return 4;
  if (c == 'o' || c == 'O' || c == '0')
    return 3;
  if (isalpha(c))
    return 2;
  return 1;
}
char str[100020];
int main(int argc, char const *argv[]) {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  long long res = 1;
  for (int i = 1; i <= len; i++)
    res = res * get(str[i]) % 1000000007;
  cout << res << endl;
  return 0;
}