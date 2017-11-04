#include<iostream>
#include<cstdio>
using namespace std;
char a[10];
int main()
{
    char r,t;int s=0;
    scanf("%c-%c%c%c%-%c%c%c%c%c-%c",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&t);
    for(int i=0;i<=8;i++)
      s+=(a[i]-'0')*(i+1);
    r=s%11+'0';
    if(r==10+'0')
      r='X';
    if(r==t)
       cout<<"Right"<<endl;
    else 
      printf("%c-%c%c%c-%c%c%c%c%c-%c",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],r);
    return 0;
}