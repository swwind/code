#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[1020];
int main(int argc, char const *argv[]) {
  scanf("%s", str);
  int len = strlen(str);
  bool W = false, E = false, N = false, S = false;
  for (int i = 0; i < len; ++ i) {
    if (str[i] == 'W') W = true;
    if (str[i] == 'E') E = true;
    if (str[i] == 'N') N = true;
    if (str[i] == 'S') S = true;
  }
  if ((W ^ E) || (N ^ S)) puts("No");
  else puts("Yes");
  return 0;
}