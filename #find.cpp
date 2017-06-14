#include <bits/stdc++.h>
using namespace std;
int main(){
	string str, pos, tmp = "Array??";
	cout << "Please input the string you want to find:" << endl;
	getline(cin, str);
	for(int i = 1000; i <= 5000; i++){
		stringstream ss;
		ss << "BZOJ" << i << ".cpp";
		// cout << ss.str() << endl;
		freopen(ss.str().c_str(), "r", stdin);
		if(getchar() != EOF)
			while(getline(cin, pos)){
			// cout << pos << endl;
				if(~(int)pos.find(str)){
					cout << ss.str() << endl;
					break;
				}
			}
		fclose(stdin);
	}
	for(int i = 100; i <= 999; i++)for(char j = 'A'; j <= 'Z'; j++){
		stringstream ss;
		ss << "cf" << i << j << ".cpp";
		// cout << ss.str() << endl;
		freopen(ss.str().c_str(), "r", stdin);
		if(getchar() != EOF)
			while(getline(cin, pos)){
			// cout << pos << endl;
				if(~(int)pos.find(str)){
					cout << ss.str() << endl;
					break;
				}
			}
		fclose(stdin);
	}
}