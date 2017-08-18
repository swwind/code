#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,t,map[101][101][4],f[101][101][4],a[102][102],dx[4],dy[4];
struct node
{
    int x,y,step;
}h[100001];
void find(int x,int y)
{
    int head=1,tail=1;
    h[1].x=x; h[1].y=y; h[1].step=0;
    f[x][y][0]=1; map[x][y][0]=0;
    while(head<=tail)
    {
        for(int i=0;i<4;i++)
        {
            int xx=dx[i]+h[head].x,yy=dy[i]+h[head].y,step=(h[head].step+1)%3,sum;
            printf("%d %d %d\n", xx, yy, step);
            if(step==0) sum=map[h[head].x][h[head].y][h[head].step]+a[xx][yy];
            else sum=map[h[head].x][h[head].y][h[head].step];
            sum+=t;
            if((xx<=0)||(xx>n)||(yy<=0)||(yy>n)||(sum>map[xx][yy][step])) continue;
            if(f[xx][yy][step]==0) 
            {
                tail++;
                f[xx][yy][step]=tail;
                h[tail].x=xx; h[tail].y=yy; h[tail].step=step;
            }
            map[xx][yy][step]=sum;
        }
        head++;
        f[h[head].x][h[head].y][h[head].step]=0;
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]);
        for(int k=0;k<3;k++)
            map[i][j][k]=0X3f3f3f3f;
    }
    dx[1]=dx[0]=dy[2]=dy[3]=0;
    dx[2]=dy[0]=1;
    dx[3]=dy[1]=-1;
    find(1,1);
    printf("%d",min(map[n][n][0],min(map[n][n][1],map[n][n][2])));
    return 0;
}