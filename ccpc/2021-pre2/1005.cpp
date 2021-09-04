#include <bits/stdc++.h>
using namespace std;


// read a int t, and do following t times
// 1. read a int n
// 2. output 6*n and 3
// 3. output 1*n, 2*n and 3*n
int main() {
      int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 6ll*n << " " << 3ll << endl;
        cout << 1ll*n << " " << 2ll*n << " " << 3ll*n << endl;
    }
    return 0;
}
