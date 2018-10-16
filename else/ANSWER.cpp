#include<stdio.h>
#include<math.h>
#define gc getchar
#define ll long long
inline int gi(){
    ll x=0,y=1;char c;
    while(c=gc(),c<48||57<c)if(c=='-')y=-1;x=c-48;
    while(c=gc(),47<c&&c<58)x=x*10ll+c-48;
    return x*y;
}
int main(){
    double a=gi(),b=gi();
    if(fabs(a-b)==1)return puts("Yes!"),0;
    puts((floor(sqrt(a*a+a*a*b*b+b*b))*floor(sqrt(a*a+a*a*b*b+b*b))==a*a+a*a*b*b+b*b)?"Yes!":"No!");
return 0;
}