#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

char ch[100020];
vector<string> permutations(string s) {
	int len = s.length();
	for (int i = 0; i < len; i++)
		ch[i] = s[i];
	ch[len] = '\0';
	sort(ch, ch + len);
	std::vector<string> v;
	do {
		v.push_back(ch);
	} while (next_permutation(ch, ch + len));
	return v;
}

int main(int argc, char const *argv[]) {
	string str;
	cin >> str;
	std::vector<string> s = permutations(str);
	for (auto k : s)
		cout << k << endl;
	return 0;
}