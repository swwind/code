#include <bits/stdc++.h>

#include <map>
#include <cstring>
std::map<int, std::string> mp;
bool initalized = false;
#define fuck() \
	mp[1000] = "M"; \
	mp[2000] = "MM"; \
	mp[3000] = "MMM"; \
	mp[100] = "C"; \
	mp[200] = "CC"; \
	mp[300] = "CCC"; \
	mp[400] = "CD"; \
	mp[500] = "D"; \
	mp[600] = "DC"; \
	mp[700] = "DCC"; \
	mp[800] = "DCCC"; \
	mp[900] = "CM"; \
	mp[10] = "X"; \
	mp[20] = "XX"; \
	mp[30] = "XXX"; \
	mp[40] = "XL"; \
	mp[50] = "L"; \
	mp[60] = "LX"; \
	mp[70] = "LXX"; \
	mp[80] = "LXXX"; \
	mp[90] = "XC"; \
	mp[1] = "I"; \
	mp[2] = "II"; \
	mp[3] = "III"; \
	mp[4] = "IV"; \
	mp[5] = "V"; \
	mp[6] = "VI"; \
	mp[7] = "VII"; \
	mp[8] = "VIII"; \
	mp[9] = "IX"; \
	mp[0] = "";
struct node {
std::string toRoman(const int x) {
  if (!initalized) {
    fuck();
    initalized = true;
  }
  return mp[x / 1000 * 1000] + mp[x % 1000 / 100 * 100] + mp[x % 100 / 10 * 10] + mp[x % 10];
}
int fromRoman(const std::string str) {
  for (int i = 0; true; ++ i) {
    if (toRoman(i) == str) {
      return i;
    }
  }
}
}RomanNumerals;

int main(int argc, char const *argv[]) {
  std::cout << RomanNumerals.toRoman(1000) << std::endl;
  std::cout << RomanNumerals.fromRoman("M") << std::endl;
	return 0;
}