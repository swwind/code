#include <cstdio>
using namespace std;
int n, x, y, z;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        if(z == 0) y = x, z = 1;
        else if(y == x) z++;
        else z--;
    }
    printf("%d", y);
}

