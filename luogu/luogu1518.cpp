#include <bits/stdc++.h>
using namespace std;
int mp[12][12], px[4] = {-1, 0, 1, 0}, py[4] = {0, 1, 0, -1}, n;
char ch[12];
struct person{
	int x, y, to;
	int canGo(){
		return x+px[to] <= 10 && x+px[to] > 0 && y+py[to] <= 10 && y+py[to] > 0 && !mp[x+px[to]][y+py[to]];
	}
	void go(){
		x += px[to];
		y += py[to];
	}
	void turn(){
		to = (to + 1) % 4;
	}
} Cow, John;
int main(){
	for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++)
		if(i > 10 || i < 1 || j > 10 || j < 1) mp[i][j] = 1;
	for(int i = 1; i < 11; i++){
		scanf("%s", ch+1);
		for(int j = 1; j < 11; j++){
			if(ch[j]=='C') Cow.x = i, Cow.y = j, Cow.to = 0;
			else if(ch[j]=='F') John.x = i, John.y = j, John.to = 0;
			else mp[i][j] = (ch[j] == '*');
		}
	}
	//for(int i = 0; i < 12; i++){for(int j = 0; j < 12; j++) printf("%d", mp[i][j]);printf("\n");}
	while(++n < 2000){
		if(Cow.canGo()) Cow.go(); else Cow.turn();
		if(John.canGo()) John.go(); else John.turn();
		//printf("Time : %d, Cow (%d, %d) John (%d, %d)\n",n , Cow.x, Cow.y, John.x, John.y);
		if(Cow.x == John.x && Cow.y == John.y) return printf("%d", n)&0;
	}
	printf("%d\n", 0);
	return 0;
}

