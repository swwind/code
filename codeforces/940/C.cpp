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
char s[N];
int n, k, youthisfuckingnigger, youmotherfucker[N];
char to[30];
bool p[30];
std::map<char, int> iamnotagoodman;

int main(){
  int n = read(), k = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    p[s[i]+1-'a'] = !0;
  for (int i = 1; i <= 26; i++)
    if(p[i]){
      iamnotagoodman['a'-1+i] = youthisfuckingnigger;
      to[youthisfuckingnigger] = 'a'-1+i;
      ++youthisfuckingnigger;
    }
  if (k > n) {
    printf("%s", s + 1);
    for (int i = 1; i <= k - n; i++)
      putchar(to[0]);
    return puts(""), 0;
  } else {
    for (int i = 1; i <= k; i++)
      youmotherfucker[i] = iamnotagoodman[s[i]];
    youmotherfucker[k]++;
    for (int i = k; i; i--)
      if (youmotherfucker[i] == youthisfuckingnigger) {
        youmotherfucker[i-1]++;
        youmotherfucker[i] = 0;
      }
    for (int i = 1; i <= k; i++)
      s[i] = to[youmotherfucker[i]];
    s[k+1] = 0;
    printf("%s\n", s+1);
  }
  return 0;
}
