#include <queue>

class DoubleLinear {
public:
  static int dblLinear(int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(1);
    while (n --) {
      int x = q.top(); q.pop();
      q.push(x * 2 + 1);
      q.push(x * 3 + 1);
      while (q.top() == x)
        q.pop();
    }
    return q.top();
  }
};

#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << DoubleLinear::dblLinear(10) << std::endl;
  std::cout << DoubleLinear::dblLinear(20) << std::endl;
  std::cout << DoubleLinear::dblLinear(30) << std::endl;
  std::cout << DoubleLinear::dblLinear(50) << std::endl;
  return 0;
}