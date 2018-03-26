#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int cs = 0, G = 0;
void SC(char map[][21]) {
  for (int x = 0; x < 10; x++, putchar('\n'))
    for (int y = 0; y < 20; y++)
    if(map[x][y]=='H')printf("\033[47;37;5m \033[43;37;0m");
    else if(map[x][y]=='x')printf("\033[42;37;5m \033[43;37;0m");
    else printf(" ");  
  printf("\n%d步", cs);
  for (int i = 0; i < 20; i++)
    if (map[9][i] == 'x') {
      G = 1;
      printf("\n已经走出迷宫");
    }
}
int dgsf(char map[][21], int x, int y) {
 if (G == 1)
    return 0;
  cs++;
  clrscr();
  SC(map);
  usleep(300000);
  if (!map[x][y]) {
    map[x][y] = 'x';
    if (!map[x + 1][y]&&x+1<10)
      dgsf(map, x + 1, y);
    if (!map[x][y + 1]&&y+1<20 )
      dgsf(map, x, y + 1);
    if (!map[x][y - 1] &&y-1>=0)
      dgsf(map, x, y - 1);
  }
}
int main() {
  srand(time(0));
  char map[11][21]={0};
  for (int i = 0; i < 80; i++) {
    int x, y;
    y = rand() % 20;
    x = rand() % 10;
    if (map[x][y] == 'H')
      i--;
    else
      map[x][y] = 'H';
  }
  SC(map);
  clrscr();
  for (int i = 0; i < 20; i++) {
    dgsf(map, 0, i);
  }
  if (G == 0)
    printf("\n地图没有出口！");
}