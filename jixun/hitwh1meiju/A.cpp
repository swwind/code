#include <bits/stdc++.h>
using namespace std;
int main() {
int a, b;
while(~scanf("%d%d", &a, &b)){
bool s=1;
for(int i = a; i <=b; ++i){
int s1=i/100;
int s2=(i/10)%10;
int s3=i%10;
if (s1*s1*s1+s2*s2*s2+s3*s3*s3==i){printf(s?"%d":" %d", i);s=0;}
}puts(s?"no":"");
}
}