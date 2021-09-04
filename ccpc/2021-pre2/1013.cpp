#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char dim) {
  vector<string> res;
  string tmp = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == dim) {
      res.push_back(tmp);
      tmp = "";
    } else {
      tmp += s[i];
    }
  }
  res.push_back(tmp);
  return res;
}

string shuangpin(string c) {
  if (c.length() == 1) return c;
  if (c == "iu") return "q";
  if (c == "ei") return "w";
  if (c == "uan") return "r";
  if (c == "ue") return "t";
  if (c == "un") return "y";
  if (c == "sh") return "u";
  if (c == "ch") return "i";
  if (c == "uo") return "o";
  if (c == "ie") return "p";
  if (c == "ong") return "s";
  if (c == "iong") return "s";
  if (c == "ai") return "d";
  if (c == "en") return "f";
  if (c == "eng") return "g";
  if (c == "ang") return "h";
  if (c == "an") return "j";
  if (c == "uai") return "k";
  if (c == "ing") return "k";
  if (c == "uang") return "l";
  if (c == "iang") return "l";
  if (c == "ou") return "z";
  if (c == "ia") return "x";
  if (c == "ua") return "x";
  if (c == "ao") return "c";
  if (c == "zh") return "v";
  if (c == "ui") return "v";
  if (c == "in") return "b";
  if (c == "iao") return "n";
  if (c == "ian") return "m";
  return "fuck";
}

string work(string s) {
  if (s.length() == 1) return s+s;
  if (s.length() == 2) return s;
  string fuck = shuangpin(s);
  if (fuck != "fuck") {
    return s.substr(0, 1) + fuck;
  }
  string st = s.substr(0, 2);
  if (st == "zh" || st == "ch" || st == "sh") {
    return shuangpin(st) + shuangpin(s.substr(2));
  } else {
    return shuangpin(s.substr(0, 1)) + shuangpin(s.substr(1));
  }
}

int main() {
  string str;
  while (getline(cin, str)) {
    vector<string> res = split(str, ' ');
    for (size_t i = 0; i < res.size(); i++) {
      cout << work(res[i]) << " \n"[i == res.size() - 1];
    }
  }
}