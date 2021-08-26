#include <bits/stdc++.h>

using namespace std;
const long double PI = 3.141592653589793238462643383279502884197169;

int main() {
  int n; cin >> n;
  while (n--) {
    long double w, h;
    cin >> w >> h;

    long double cost1 = min(w, h);
    long double cost2 = sqrt(w * w + h * h);

    // printf("cost1 = %.10f\n", cost1);
    // printf("cost2 = %.10f\n", cost2);

    long double worth1 = cost1 / 2;
    long double worth2 = cost2 / 3;

    int ans = 0;
    {
      int select1 = PI / cost1;
      int select2 = (PI - select1 * cost1) / cost2;
      ans = max(ans, select1 * 2 + select2 * 3);

      if (select1 > 0) {
        int select3 = (PI - (select1 - 1) * cost1) / cost2;
        ans = max(ans, (select1 - 1) * 2 + select3 * 3);
      }

      if (select1 > 1) {
        int select4 = (PI - (select1 - 2) * cost1) / cost2;
        ans = max(ans, (select1 - 2) * 2 + select4 * 3);
      }

      if (select1 > 2) {
        int select5 = (PI - (select1 - 3) * cost1) / cost2;
        ans = max(ans, (select1 - 3) * 2 + select5 * 3);
      }
    }  {
      int select2 = PI / cost2;
      int select1 = (PI - select2 * cost2) / cost1;
      ans = max(ans, select1 * 2 + select2 * 3);

      if (select2 > 0) {
        int select3 = (PI - (select2 - 1) * cost2) / cost1;
        ans = max(ans, select3 * 2 + (select2 - 1) * 3);
      }

      if (select2 > 1) {
        int select4 = (PI - (select2 - 2) * cost2) / cost1;
        ans = max(ans, select4 * 2 + (select2 - 2) * 3);
      }

      if (select2 > 2) {
        int select5 = (PI - (select2 - 3) * cost2) / cost1;
        ans = max(ans, select5 * 2 + (select2 - 3) * 3);
      }
    }

    cout << ans + 4 << endl;
  }
}
