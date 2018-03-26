#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>


int jckg(char map[][10], char sr[][10], int x, int y) {
  if(sr[x][y]=='1')return 0;
  sr[x][y] = '1';
  if (map[x - 1][y] == '0')
    jckg(map, sr, x - 1, y);
  if (map[x + 1][y] == '0')
    jckg(map, sr, x + 1, y);
  if (map[x][y + 1] == '0')
    jckg(map, sr, x, y + 1);
  if (map[x][y - 1] == '0')
    jckg(map, sr, x, y - 1);

}         

void SC(char map[10][10], char sr[][10]) {
  for (int x = 0; x < 9; x++, putchar('\n'))
    for (int y = 0; y < 9; y++) {
    	
     if (sr[x][y] == '1')
        putchar(map[x][y]);
      else 
        putchar('?');
        
    }

}


int start() {
  char map[10][10];               // 地图的大小
  char sr[10][10];
  int lei = 10;                 // 地雷的个数
  for (int x = 0; x < 9; x++)
    for (int y = 0; y < 9; y++)
      sr[x][y] = map[x][y] = '0';

  // 初始化地图
  for (int x = 0; x < lei; x++) {
    int a, b;
    a = rand() % 9;
    b = rand() % 9;
    if (map[a][b] == '@')
      x--;
    map[a][b] = '@';
  }
  // 随机产生地雷 有雷为1，无雷为0(字符)

  for (int a = 0; a < 9; a++)
    for (int b = 0; b < 9; b++) {
      for (int i = -1; i < 2; i++)
        for (int n = -1; n < 2; n++) {
          if (map[a][b] == '@')
            continue;
          if (map[a + i][b + n] == '@')
            map[a][b]++;
        }
    }
  SC(map, sr);
  while (1) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    if (map[x][y] != '@')
      if (map[x][y] != '0')
         sr[x][y] = '1';
      else 
        jckg(map, sr, x, y);  /*此处有bug*/
        
    // 用递归算法求出相邻的空格
    // 能被显示的格子为1(字符)
    else {
      printf("GAME OVER !\n");
      return 0;
    }
    clrscr();
    SC(map, sr);
    fflush(stdout);
  }
}

int main() {
  int start();
  srand(time(0));               // 初始化随机函数
  start();

}