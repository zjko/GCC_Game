#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define V 100000
typedef struct D {
  char a;
  char b;
} dydt;

void SC(dydt map[][21]) {
  for (int x = 0; x < 10; x++, putchar('\n'))
    for (int y = 0; y < 20; y++)
      printf("%s",
             map[x][y].a == '#' ? "■" : map[x][y].a ==
             '*' ? "●" : "∏");
}
void zmg(dydt map[][21], int x, int y) {
  for (int a = 0; a < 20; a++)
    if (map[9][a].a == '*') {
      printf("\n已经走出迷宫！");

      exit(0);
    }
  if (map[x][y].a != '#') {
    usleep(V);
    clrscr();
    SC(map);
    map[x][y].a = '*';
    if (map[x][y + 1].a == ' ')
      zmg(map, x, y + 1);
    if (map[x + 1][y].a == ' ')
      zmg(map, x + 1, y);
    if (map[x][y - 1].a == ' ')
      zmg(map, x, y - 1);
    if (map[x - 1][y].a == ' ')
      zmg(map, x - 1, y);
  }
  usleep(V);
  clrscr();
  SC(map);
}
int main() {
  srand(time(0));
  dydt map[10][21];
  for (int x = 0; x < 10; x++)
    for (int y = 0; y < 20; y++) {
      map[x][y].a = ' ';
      map[x][y].b = '0';
    }
  for (int i = 0, x, y; i < 100; i++) {
    x = rand() % 10;
    y = rand() % 20;
    map[x][y].a = '#';
  }
  SC(map);
  for (int y = 0; y < 20; y++)
    zmg(map, 0, y);
}