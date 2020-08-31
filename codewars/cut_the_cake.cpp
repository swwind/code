/*

NOTE : You are provided with these functions

std::string join(const std::string &sep, const std::vector<std::string> &to_join)

std::vector<std::string> split(const std::string &to_split, char separator = '\n')
*/

#include <bits/stdc++.h>

std::vector<std::string> _split(std::string s) {
  size_t pos = 0;
  std::vector<std::string> vec;
  while ((pos = s.find("\n")) != std::string::npos) {
    vec.push_back(s.substr(0, pos));
    s.erase(0, pos + 1);
  }
  vec.push_back(s);
  return vec;
}

struct MyArray {
  int col, row;
  int* a;
  MyArray(){}
  MyArray(int col, int row):col(col), row(row) {
    a = new int[col * row];
    for (int i = 0; i < col * row; ++ i) {
      a[i] = 0;
    }
  }
  int at(int c, int r) {
    return a[c * row + r];
  }
  void set(int c, int r, int v) {
    a[c * row + r] = v;
  }
} arr;

int piece_size;

int ask(int cl, int cr, int rl, int rr) {
  return arr.at(cr, rr) - arr.at(cl-1, rr) - arr.at(cr, rl-1) + arr.at(cl-1, rl-1);
}

int size(int cl, int cr, int rl, int rr) {
  return (cr - cl + 1) * (rr - rl + 1);
}

int top;
int rcl[1000], rcr[1000], rrl[1000], rrr[1000];

bool dfs(int cl, int cr, int rl, int rr, int rm) {
  printf("%d %d %d %d %d\n", cl, cr, rl, rr, rm);
  if (rm == 1) {
    ++ top;
    rcl[top] = cl;
    rcr[top] = cr;
    rrl[top] = rl;
    rrr[top] = rr;
    return true;
  }

  int nowtop = top;
  
  for (int i = cl; i < cr; ++ i) {
    int sz = size(cl, i, rl, rr);
    int tl = ask(cl, i, rl, rr);
    if (sz % piece_size > 0 || tl * piece_size != sz) {
      continue;
    }
    if (dfs(cl, i, rl, rr, tl) && dfs(i + 1, cr, rl, rr, rm - tl)) {
      return true;
    }
    top = nowtop;
  }
  
  for (int i = rl; i < rr; ++ i) {
    int sz = size(cl, cr, rl, i);
    int tl = ask(cl, cr, rl, i);
    if (sz % piece_size > 0 || tl * piece_size != sz) {
      continue;
    }
    if (dfs(cl, cr, rl, i, tl) && dfs(cl, cr, i + 1, rr, rm - tl)) {
      return true;
    }
    top = nowtop;
  }
  
  return false;
}

std::vector<std::string> cut(const std::string &cake) {
  std::vector<std::string> ss = _split(cake);
  int col = ss.size(), row = ss[0].length();
  arr = MyArray(col+1, row+1);
  for (int i = 0; i < col; ++ i) {
    for (int j = 0; j < row; ++ j) {
      arr.set(i+1, j+1, (ss[i][j] == 'o') + arr.at(i, j+1) + arr.at(i+1, j) - arr.at(i, j));
    }
  }
  
  piece_size = col * row / arr.at(col, row);
  
  top = 0;
  if (!dfs(1, col, 1, row, arr.at(col, row))) {
    return {};
  }
  
  std::vector<std::string> vec;
  for (int i = 1; i <= top; ++ i) {
    std::string str = "";
    // printf("%d %d %d %d\n", rcl[i], rcr[i], rrl[i], rrr[i]);
    // printf("%s\n", ss[rcl[i]].c_str());
    for (int ii = rcl[i]; ii <= rcr[i]; ++ ii) {
      // printf("%d %d\n", rrl[i] - 1, rrr[i] - rrl[i] + 1);
      str += ss[ii - 1].substr(rrl[i] - 1, rrr[i] - rrl[i] + 1);
      if (ii < rcr[i]) {
        str += '\n';
      }
    }
    vec.push_back(str);
  }
  // puts("2333");
  return vec;
}

// TODO: Replace examples and use TDD development by writing your own tests

void test_assert(const std::vector<std::string> &actual, const std::vector<std::string> &expected) {
  bool wa = false;
  if (actual.size() != expected.size()) {
    puts("size dismatch");
    wa = true;
  }
  if (!wa) {
    for (unsigned int i = 0; i < actual.size(); ++ i) {
      if (actual[i].compare(expected[i])) {
        puts("Wrong Answer");
        wa = true;
        break;
      }
    }
  }

  if (wa) {
    puts("actual:");
    for (auto s : actual) {
      puts(s.c_str());
      puts("");
    }
    puts("expected:");
    for (auto s : expected) {
      puts(s.c_str());
      puts("");
    }
  }

  puts("=======");
}

int main() {
  std::string cake =
  "........\n"
  "..o.....\n"
  "...o....\n"
  "........";
  
  std::vector<std::string> result = 
  {
  "........\n"
  "..o.....",
  
  "...o....\n"
  "........"
  };
  test_assert(cut(std::string(cake)), result);
  
  cake =
  ".o......\n"
  "......o.\n"
  "....o...\n"
  "..o.....";
  result = {".o......","......o.","....o...","..o....."};
  test_assert(cut(std::string(cake)), result);
  
  cake =
  ".o.o....\n"
  "........\n"
  "....o...\n"
  "........\n"
  ".....o..\n"
  "........";
  result = {
  ".o\n"
  "..\n"
  "..\n"
  "..\n"
  "..\n"
  "..",
  
  ".o....\n"
  "......",
  
  "..o...\n"
  "......",
  
  "...o..\n"
  "......"
  };
  test_assert(cut(std::string(cake)), result);
  
  cake =
  ".o.o....\n"
  ".o.o....\n"
  "........\n"
  "........";
  result.clear();
  test_assert(cut(std::string(cake)), result);
  
  cake =
  ".o....o.\n"
  ".o....o.\n"
  "........\n"
  "o..oo..o";
  result = {
  ".o..",
  
  "..o.",
  
  ".o..",
  
  "..o.",
  
  "..\n"
  "o.",
  
  "..\n"
  ".o",
  
  "..\n"
  "o.",
  
  "..\n"
  ".o"
  };
  test_assert(cut(std::string(cake)), result);
  
  // A complex example ;-)
  cake =
  "................\n"
  ".....o..........\n"
  "................\n"
  "...............o\n"
  "................\n"
  "................\n"
  "................\n"
  ".....o..o.....o.\n"
  "................\n"
  "................\n"
  "...o............\n"
  "................\n"
  "................\n"
  "...............o\n"
  "................\n"
  ".o..............";
  result = {
  "................\n"
  ".....o..........",
  
  "................\n"
  "...............o",
  
  "........\n"
  "........\n"
  "........\n"
  ".....o..",
  
  "....\n"
  "....\n"
  "....\n"
  "o...\n"
  "....\n"
  "....\n"
  "....\n"
  "....",
  
  "....\n"
  "....\n"
  "....\n"
  "..o.\n"
  "....\n"
  "....\n"
  "....\n"
  "...." ,
  
  "........\n"
  "........\n"
  "...o....\n"
  "........",
  
  "................\n"
  "...............o" ,
  
  "................\n"
  ".o.............."
  };
  test_assert(cut(std::string(cake)), result);
}
