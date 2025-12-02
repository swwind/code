#include <bits/stdc++.h>
#include <cstdio>

#define N 200030

int main() {
  int X, Y, Z;
  scanf("%d%d%d", &X, &Y, &Z);

  if (X == Y) {
    printf("%d", X);
    for (int i = 0; i < X; ++i)
      printf(" 0");
    printf("\n");

    printf("%d", Z);
    for (int i = 0; i < Z; ++i)
      printf(" 0");
    printf("\n");

    printf("%d", Z);
    for (int i = 0; i < Z; ++i)
      printf(" 0");
    printf("\n");
    return 0;
  }

  int s1 = X + Y - 1;
  printf("%d", s1);
  for (int i = 0; i < Y; ++i)
    printf(" %d", 0);
  for (int i = 1; i < X; ++i)
    printf(" %d", 1);
  printf("\n");

  int s2 = Z + X - 1;
  printf("%d", s2);
  for (int i = 1; i < Z; ++i)
    printf(" %d", 1);
  printf(" %d", 0);
  for (int i = 1; i < X; ++i)
    printf(" %d", 1);
  printf("\n");

  int s3 = Y + Z - 1;
  printf("%d", s3);
  for (int i = 1; i < Z; ++i)
    printf(" %d", 1);
  for (int i = 0; i < Y; ++i)
    printf(" %d", 0);
  printf("\n");
}
