#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define V 20000
void SC(char map[][40]);        // 全局定义SC函数
void MID(char map[][40], int m, int n, int k) {
  for (int x = m; x < n + m; x++) {
    map[x][k] = '*';
    clrscr();
    usleep(V);  
    SC(map);
  }
}                               // 纵向 插入赋值函数

void Dm1(char map[][40], char c) {

  for (int a = 0; a < 8; a++) {
    for (int x = a; x < 14 - a; x++) {
      map[x][a] = c;
      usleep(V);
      clrscr();
      SC(map);
      // map[x][a] = ' ';
    }
    for (int y = a; y < 40 - a; y++) {
      map[13 - a][y] = c;
      usleep(V);
      clrscr();
      SC(map);
      // map[14 - a][y] = ' ';
    }
    for (int x = 14 - a; x > a; x--) {
      map[x][39 - a] = c;
      usleep(V);
      clrscr();
      SC(map);
      // map[x][40 - a] = ' ';
    }
    for (int y = 39 - a; y > a; y--) {
      map[a][y] = c;
      usleep(V);
      clrscr();
      SC(map);
      // map[a][y] = ' ';
    }


}}

void Dm2(char map[][40]) {
  int k;
  for (k = 0; k < 8; k++)
    if (k != 4) {
      MID(map, 2, 1, k);
      MID(map, 13, 1, k);
    } else
      MID(map, 2, 12, k);

  k = 8;
  MID(map, 4, 3, ++k);
  MID(map, 3, 5, ++k);
  MID(map, 2, 7, ++k);
  MID(map, 2, 8, ++k);
  MID(map, 2, 9, ++k);
  MID(map, 3, 9, ++k);
  MID(map, 3, 10, ++k);
  MID(map, 4, 11, ++k);
  MID(map, 3, 10, ++k);
  MID(map, 3, 9, ++k);
  MID(map, 2, 9, ++k);
  MID(map, 2, 9, ++k);
  MID(map, 2, 8, ++k);
  MID(map, 3, 6, ++k);
  MID(map, 3, 5, ++k);
  MID(map, 4, 3, ++k);
  k = 25;
  MID(map, 2, 7, ++k);
  MID(map, 9, 1, ++k);
  MID(map, 10, 1, ++k);
  MID(map, 11, 1, ++k);
  
  while (k < 35)
    MID(map, 12, 1,++ k);
  MID(map, 11, 1, ++k);
  MID(map, 10, 1, ++k);
  MID(map, 9, 1, ++k);
  MID(map, 2, 7, ++k);
}

void SC(char map[][40]) {
  for (int x = 0; x < 14; x++, putchar('\n'))
    for (int y = 0; y < 40; y++)
  printf("%c\033[?25l",map[x][y]); 
//putchar(map[x][y]);
}
int start() {
  srand(time(0));
  char map[14][40];
  for (int x = 0; x < 14; x++)
    for (int y = 0; y < 40; y++)
      map[x][y] = ' ';
  while (1) {
    switch (getch()) {
    case '1':
      for (int i = 0, x, y; i < 700; i++) {
        x = rand() % 14;
        y = rand() % 40;
        map[x][y] = '.';
        clrscr();
        SC(map);
        x = rand() % 14;
        y = rand() % 40;
        map[x][y] = ' ';
        usleep(V);
   
      } break;
    case '2':
      Dm1(map, 'O');
      Dm1(map, ' ');
      break;
    case '3':
      Dm2(map);
      break;
    }
  }
  SC(map);
}



int main() {
  start();

}