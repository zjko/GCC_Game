#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"time.h"
int GG = 0;
void SC(char map[3][3]) {
  for (int y = 0; y < 3; y++, putchar('\n'))
    for (int x = 0; x < 3; x++)
      if (map[y][x] == 'A')
        printf("\033[46;32;5m◆ \033[47;32;0m");
      else if (map[y][x] == 'B')
        printf("\033[43;32;5m■ \033[47;32;0m");
      else
        printf("\033[41;32;5m● \033[47;32;0m");
  printf("%d\n", GG);
}
void START() {
  int x, y;
  srand(time(0));
  char map[3][3];
  for (y = 0; y < 3; y++)
    for (x = 0; x < 3; x++)
      map[y][x] = 'A' + rand() % 3;
  SC(map);
  while (1) {
    switch (getch()) {
    case '2':
      for (x = 0; x < 3; x++)
        map[0][x] = (map[0][x] - 'A' + 1) % 3 + 'A';
      break;
    case '8':
      for (x = 0; x < 3; x++)
        map[2][x] = (map[2][x] - 'A' + 1) % 3 + 'A';
      break;
    case '4':
      for (y = 0; y < 3; y++)
        map[y][0] = (map[y][0] - 'A' + 1) % 3 + 'A';
      break;
    case '6':
      for (y = 0; y < 3; y++)
        map[y][2] = (map[y][2] - 'A' + 1) % 3 + 'A';
      break;
    case '1':
      map[0][0] = (map[0][0] - 'A' + 1) % 3 + 'A';
      map[0][1] = (map[0][1] - 'A' + 1) % 3 + 'A';
      map[1][0] = (map[1][0] - 'A' + 1) % 3 + 'A';
      break;
    case '3':
      map[0][2] = (map[0][2] - 'A' + 1) % 3 + 'A';
      map[0][1] = (map[0][1] - 'A' + 1) % 3 + 'A';
      map[1][2] = (map[1][2] - 'A' + 1) % 3 + 'A';
      break;
    case '7':
      map[1][0] = (map[1][0] - 'A' + 1) % 3 + 'A';
      map[2][0] = (map[2][0] - 'A' + 1) % 3 + 'A';
      map[2][1] = (map[2][1] - 'A' + 1) % 3 + 'A';
      break;
    case '9':
      map[1][2] = (map[1][2] - 'A' + 1) % 3 + 'A';
      map[2][2] = (map[2][2] - 'A' + 1) % 3 + 'A';
      map[2][1] = (map[2][1] - 'A' + 1) % 3 + 'A';
      break;
    case '5':
      for (x = 0; x < 3; x++)
        map[1][x] = (map[1][x] - 'A' + 1) % 3 + 'A';
      map[0][1] = (map[0][1] - 'A' + 1) % 3 + 'A';
      map[2][1] = (map[2][1] - 'A' + 1) % 3 + 'A';
    }
    clrscr();
    SC(map);
    GG++;
    bool s;
    for (x = 1; x < 9; x++)
      if (**map != *(*(map+x/3)+x%3)) {
        s = false;
        break;
      } else
        s = true;
    if (s) {
      printf("游戏胜利！");
      return;
    }
  }
}
int main() {
  START();
}