#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
typedef complex<double> cp;                     //complex库
const double M_PI = acos(-1);
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
void fft(cp *a,int n,int flag)                  //作用：求出a的点值表达，存进a
{
    int i;
    cp a0[n/2+1],a1[n/2+1];

    if(n==1) return;
    cp w_n(cos(2*M_PI/n),sin(flag*2*M_PI/n));   //flag=1:求值  flag=2:插值
    cp w(1,0);

    for(i=0;i<n/2;i++) a0[i]=a[i*2],a1[i]=a[i*2+1];     //分治

    fft(a0,n/2,flag);
    fft(a1,n/2,flag);

    for(i=0;i<n/2;i++)
    {
        a[i]=a0[i]+w*a1[i];
        a[i+n/2]=a0[i]-w*a1[i];
        w=w*w_n;                                //递推单位复数根
    }

}

cp x[300005]={0},y[300005]={0};
int n,m;

void init()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<=n;i++) x[i].real(read());
    for(i=0;i<=m;i++) y[i].real(read());
    m+=n;
    for(n=1;n<=m;n=n*2);
}

int main(void)
{
    int i;
    init();
    fft(x,n,1);                                 //求值
    fft(y,n,1);                                 //求值

    for(i=0;i<n;i++) x[i]=x[i]*y[i];            //点值乘法
    fft(x,n,-1);                                //插值

    for(i=0;i<=m;i++)
        printf("%d ",int((x[i].real())/n+0.5));       //四舍五入输出

    return 0;
}