#include <bits/stdc++.h>
#define N 100020
#define OUTPUT_LENGTH_LIMIT 60
#define ll long long
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct Ray {
  int a[8];
  bool operator == (const Ray &b) {
    for (int i = 0; i < 8; ++ i)
      if (a[i] != b.a[i]) return false;
    return true;
  }
  friend bool operator < (const Ray &a, const Ray &b) {
    for (int i = 0; i < 8; ++ i)
      if (a.a[i] != b.a[i]) return a.a[i] < b.a[i];
    return false;
  }
  Ray* resolve(int type) {
    Ray *ray = new Ray();
    memcpy(ray -> a, this -> a, sizeof (int) * 8);
    switch (type) {
      case 1: ray -> _work1(); break;
      case 2: ray -> _work2(); break;
      case 3: ray -> _work3(); break;
    }
    return ray;
  }
  void _work1() {
    std::reverse(a, a + 8);
  }
  void _work2() {
    int _3 = a[3], _4 = a[4];
    a[3] = a[2]; a[2] = a[1];
    a[1] = a[0]; a[0] = _3;
    a[4] = a[5]; a[5] = a[6];
    a[6] = a[7]; a[7] = _4;
  }
  void _work3() {
    int _ = a[1];
    a[1] = a[6]; a[6] = a[5];
    a[5] = a[2]; a[2] = _;
  }
} *pre, *res;
struct Zack {
  Ray *ray;
  std::vector<int> way;
  Zack(Ray *ray, std::vector<int> way):ray(ray),way(way) {
  }
};
std::queue<Zack*> queue;
void resolve(std::vector<int> vec) {
  printf("%u", vec.size());
  for (unsigned int i = 0; i < vec.size(); ++ i) {
    if (i % OUTPUT_LENGTH_LIMIT == 0) putchar('\n');
    putchar('A' - 1 + vec[i]);
  }
  putchar('\n');
  exit(0);
}
std::map<Ray, bool> map;
int main(int argc, char const *argv[]) {
  pre = new Ray();
  res = new Ray();
  for (int i = 0; i < 8; ++ i) {
    pre -> a[i] = i + 1;
    res -> a[i] = read();
  }
  if (*pre == *res) {
    puts("0");
    return 0;
  }
  queue.push(new Zack(pre, {}));
  while (!queue.empty()) {
    Zack *zack = queue.front();
    queue.pop();
    for (int i = 1; i <= 3; ++ i) {
      Ray *ray = zack -> ray -> resolve(i);
      if (map[*ray]) continue;
      map[*ray] = true;
      std::vector<int> vec = zack -> way;
      vec.push_back(i);
      if (*ray == *res) {
        resolve(vec);
      }
      queue.push(new Zack(ray, vec));
    }
  }
  return 0;
}