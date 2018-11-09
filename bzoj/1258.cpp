#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[100];
int a=1, b=1, c=1;
int main(){
	scanf("%s", &s);int len = strlen(s);
	if(s[len-1] == '4'){
		for(int i = 1; i <= 3; i++){
			for(int j = 0; j < len-1; j++) putchar(s[j]);
			printf("%d\n", i);
		}
		return 0;
	}
	while(len--&&(a||b||c)){
		if(a&&s[len]=='1'){
			for(int i = 0; i < len; i++) putchar(s[i]);
			puts("4");
			a = 0;
			continue;
		}
		if(b&&s[len]=='2'){
			for(int i = 0; i < len; i++) putchar(s[i]);
			puts("4");
			b = 0;
			continue;
		}
		if(c&&s[len]=='3'){
			for(int i = 0; i < len; i++) putchar(s[i]);
			puts("4");
			c = 0;
			continue;
		}
	}
	return 0;
}

