#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s,p,w,st[105];
map <string, int> m,ctc;
void turn(string &x) {
	for (int i = 0; i < x.length(); i++)
		if(x[i] <= 'Z' && x[i] >= 'A')
			x[i] -= 'A'-'a';
}
int main() {
	string szb, q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		turn(s);
		m[s] = 1;
	}
	getline(cin, szb);
	getline(cin, p);
	int flag = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] != ' ' && p[i] != '.' && p[i] != ',') {
			w.push_back(p[i]);
		} else {
			turn(w);
			if (m[w] == 1 && ctc[w] == 0) {
				st[flag++] = w;
				ctc[w] = 1;
				ans++;
			}
			w = "";
		}
		if (p[i] == '.') {
			for (int i = 0; i < flag; i++)
				ctc[st[i]] = 0;
			for(int i = 0; i < flag; i++)
			st[i] = " ";
			flag = 0;
		}
	}
	cout << ans << endl;
	return 0;
}