#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
int nd = 5;
void sc(char map[10][10]) {
  int y, x;
  for (y = 0; y < nd; y++, putchar('\n'))
    for (x = 0; x < nd; x++)
      putchar(map[y][x]);
}
void start() {
  int y, x, a1, a2, b1, b2, k = 0;
  char map[10][10], c = 'A';
  srand(time(0));
  for (y = 0; y < nd; y++) {
    map[y][0] = '0' + y;
    map[0][y] = '0' + y;
  }
  for (x = 1; x < nd; x++)
    for (y = x; y < nd; y++, c++) {
      if (c > 'Z' && c < 'a')
        c += 6;
      map[x][y] = c;
      map[y][x] = c;
    }
  for (; k < nd * nd; k++) {
    a1 = rand() % (nd - 1) + 1;
    a2 = rand() % (nd - 1) + 1;
    b1 = rand() % (nd - 1) + 1;
    b2 = rand() % (nd - 1) + 1;
    c = map[a1][b1];
    map[a1][b1] = map[a2][b2];
    map[a2][b2] = c;
  }
  sc(map);
  while (1) {
    scanf("%1d%1d%1d%1d",&a1,&b1,&a2,&b2);
    printf("%d%d,%d%d",a1,b1,a2,b2);
    if (map[a1][b1] ==map[a2][b2])
      map[a1][b1] = ' ', map[a2][b2] = ' ';
      clrscr();
      sc(map);
  }
}
main() {
  start();
}