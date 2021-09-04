#include <bits/stdc++.h>

const double PI = acos(-1.0);

using namespace std;

struct Vec3 {
  double x, y, z;
};

struct Point {
  double x, y, z;
};

// rotate a point around vec by angle
Point rotate(Vec3 vec, Point point, double angle) {
    Vec3 vec_norm = {vec.x / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z),
                   vec.y / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z),
                   vec.z / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)};
  double sin_angle = sin(angle), cos_angle = cos(angle);
  Point res = {point.x * (cos_angle + vec_norm.x * vec_norm.x * (1 - cos_angle)) +
                   point.y * (vec_norm.x * vec_norm.y * (1 - cos_angle) -
                              vec_norm.z * sin_angle) +
                   point.z * (vec_norm.x * vec_norm.z * (1 - cos_angle) +
                              vec_norm.y * sin_angle),
               point.x * (vec_norm.y * vec_norm.x * (1 - cos_angle) +
                          vec_norm.z * sin_angle) +
                   point.y * (cos_angle + vec_norm.y * vec_norm.y * (1 - cos_angle)) +
                   point.z * (vec_norm.y * vec_norm.z * (1 - cos_angle) -
                              vec_norm.x * sin_angle),
               point.x * (vec_norm.x * vec_norm.z * (1 - cos_angle) -
                          vec_norm.y * sin_angle) +
                   point.y * (vec_norm.y * vec_norm.z * (1 - cos_angle) +
                              vec_norm.x * sin_angle) +
                   point.z * (cos_angle + vec_norm.z * vec_norm.z * (1 - cos_angle))};
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    double A, B, C, x, y, z, r;
    cin >> A >> B >> C >> x >> y >> z >> r;
    Vec3 vec = {A, B, C};
    Point point = {x, y, z};
    double angle = r / 360 * 2 * PI;
    Point P = rotate(vec, point, angle);
    Point Q = rotate(vec, point, -angle);
    if (P.z > Q.z) {
      printf("%.10f %.10f %.10f\n", P.x, P.y, P.z);
    } else {
      printf("%.10f %.10f %.10f\n", Q.x, Q.y, Q.z);
    }
  }
}
