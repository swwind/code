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
char se[10001], ss[10001], ans[10001], c;
int len, p, i;
int cnt = 1;
int main(int argc, char const *argv[]) {
  cin >> len >> se >> p;
  if (len == 1) {
    cout << se << endl;
    return 0;
  }
  strcpy(ss, se);
  sort(ss, ss + len);
  c = se[p - 1];
  for (i = 0; i < len; i++)
    if (ss[i] == c) break;
  ans[0] = se[i];
  c = se[i];
  ss[i] = '#';
  for (i = len - 1; i >= 0; i--){
    if (ss[i] == c){
      c = se[i];
      ans[cnt++] = c;
      ss[i] = '#';
      i = len;
    }
  }
  for (i = len - 1; i >= 0; i--)
    cout << ans[i];
  cout << endl;
  return 0;
}