// 一个简单包装，支持自定义下标范围的数组。

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
template <typename T, int L, int R>
struct Array {
  T a[R - L + 1];
  T& operator [] (int x) {
    return a[x - L];
  }
  T* operator + (int x) {
    return a + (x - L);
  }
};
Array<int, -50, 50> arr;
int main(int argc, char const *argv[]) {
  arr[-3] = 3;
  printf("%d\n", arr[-3]);
  return 0;
}