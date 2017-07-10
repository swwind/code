#include <bits/stdc++.h>

using namespace std;

int n, vis[1000], ans;
string ch[100];

int equals(int x){
	for(int i = 0; i < ch[x].length(); i++) if(ch[n][i] != ch[x][i]) return 0;
	cout << "Compare : " << ch[x] << " to " << ch[n] << endl;
	return (ch[n].length() == ch[x].length() ? 1 : ch[n][ch[x].length()] == ' ');
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		cin >> ch[i];
		for(int x = 0; x < n; x++)
	for(int i = 0; i < ch[x].length(); i++) if(ch[x][i] <= 'Z') ch[x][i] += 'a' - 'A';
	while((cin >> ch[n]) && ch[n][0]!='E' && (cout << ch[n] << endl)){
		if(ch[n][ch[n].length() - 1] == ',' || ch[n][ch[n].length() - 1] == '.') ch[n][ch[n].length() - 1] = ' ';
		for(int i = 0; i < ch[n].length(); i++) if(ch[n][i] <= 'Z' && ch[n][i] >= 'A') ch[n][i] += 'a' - 'A';
		for(int i = 0; i < n; i++) if(!vis[i] && equals(i)) ans++, vis[i]++;
	}
	printf("%d", ans);
	return 0;
}

