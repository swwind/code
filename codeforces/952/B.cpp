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
int main(int argc, char const *argv[]) {
  for (int i = 0; i < 10; i++) {
    cout << rand() % 10 << endl << flush;
    string x;
    getline(cin, x);
    std::transform(x.begin(), x.end(), x.begin(), ::tolower);
    if (x == "don't even" ||
        x == "are you serious?" ||
        x == "go die in a hole" ||
        x == "worse" ||
        x == "terrible" ||
        x == "no way")
      return puts("grumpy"), 0;
    if (x == "great!" ||
        x == "don't think so" ||
        x == "don't touch me" ||
        x == "not bad" ||
        x == "cool")
      return puts("normal"), 0;
  }
  puts("grumpy");
  return 0;
}