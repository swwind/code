#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x, y;
};
bool mult(point sp,point ep,point op){
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool operator < (const point &l,const point &r)
{
    return l.y<r.y||(l.y==r.y&&l.x<r.x);
}
int gra(point pnt[],int n,point res[])
{
    int i,len,top=1;
    sort(pnt,pnt+n);
    if(n==0)return 0;res[0]=pnt[0];
    if(n==1)return 1;res[1]=pnt[1];
    if(n==2)return 2;res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    len=top;
    res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    return top;
}
double dis(point a,point b)
{
    return sqrt(pow(fabs(a.x-b.x),2)+pow(fabs(a.y-b.y),2));
}
int main()
{
    int n,i;
    double a,b,sumx;
    point p[10001],r[10001];
    while(cin>>n){
        for(i=0;i<n;i++){
            cin>>a>>b;
            p[i].x=a;
            p[i].y=b;
        }
        int x=gra(p,n,r);
        sumx=0;
        for(i=1;i<x;i++){
            sumx+=dis(r[i],r[i-1]);
        }
        sumx+=dis(r[0],r[x-1]);
        printf("%.2lf\n",sumx);
    }
    return 0;
}