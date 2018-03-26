#include<stdio.h>
int main() {
  char map[8][8];
  for (int i1 = 0; i1 < 8; i1++)
    for (int i2 = 0; i2 < 8; i2++)
      if ((i1 + i2) % 2)
        map[i1][i2] = '1';
      else
        map[i1][i2] = '0';
  for (int i1 = 0; i1 < 8; i1++, putchar('\n'))
    for (int i2 = 0; i2 < 8; i2++)
      switch (map[i1][i2]) {
      case '1':
        printf("\033[40;37;5m  \033[43;37;0m");
        break;
      case '0':
        printf("\033[47;37;5m  \033[43;37;0m");

      }


}