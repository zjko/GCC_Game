#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
/*-----------------------------------------
p 高四位为行 低四位为列
-----------------------------------------*/
int start();
// 游戏入口
int check(char x, char c, char map[9][9]);
// 输入检查
int printmap(char map[9][9]);
// 打印地图
int activity(char map[9][9]);
// 用户输入活动反馈
int mapinit(char map[9][9]);
// 地图初始化
int checkwin(char map[9][9]);
// 检测是否已通关
int data(char c);
// 输出映射
char *msg = "开始游戏";
// 提示信息
char p;
// -----------------------------------------
int main() {
  while (1)
    start();
  puts("重新开局请按Y");
  if (getch() != 'Y')
    return 1;
}
// ------------------------------------
int start() {
  char map[9][9] = { 0 };
  mapinit(map);
  // 初始化
  while (checkwin(map))
    activity(map);
}
int activity(char map[9][9]) {
  clrscr();
  printmap(map);
  switch (getch()) {
  case '2':
    if (p / 9 > 0)
      p -= 9;
    break;
  case '8':
    if (p / 9 < 8)
      p += 9;
    break;
  case '4':
    if (p % 9 > 0)
      p--;
    break;
  case '6':
    if (p % 9 < 8)
      p++;
    break;
  case '5':                    
  // 进入二级输入
    if (map[p / 9][p % 9] == 0 || map[p / 9][p % 9] > 15) {
      msg = "请输入数值";
      clrscr();
      printmap(map);
      map[p / 9][p % 9] = getch() - '0' + 16;
    } else
      msg = "此位置已被输入";
  }
  return 1;
}

int printmap(char map[9][9]) {
  char x, y;
  for (x = 0; x < 9; x++, putchar('\n'))
    for (y = 0; y < 9; y++)
      if ((x / 3 + y / 3) % 2) {
        if (map[x][y] < 16)
          printf("\033[47;30;5m"); // 色区
        else
          printf("\033[47;35;5m");

        if (x * 9 + y == p) {   // 指针位置
          printf("\033[44;37;5m");
          data(map[x][y]);
          printf("\033[43;37;0m");
        } else
          data(map[x][y]);
        printf("\033[43;33;0m");
      } else {
        if (map[x][y] < 16)
          printf("\033[43;37;5m");
        else
          printf("\033[43;35;5m");
        if (x * 9 + y == p) {
          printf("\033[44;37;5m");
          data(map[x][y]);
          printf("\033[43;37;0m");
        } else
          data(map[x][y]);

        /* printf(x * 9 + y == p ? "\033[44;37;5m%c\033[43;37;0m" : "%c",
           map[x][y] % 16 + '1'); */
        printf("\033[40;35;0m");
      }
  puts(msg);
  return 0;
}
int mapinit(char map[9][9]) {
  char x, tmp, nd;
  int t;
  srand(time(0));
for(t=0;t<3;t++)
  for (int i = 1; i < 10; i++) {
    // 随机产生第一行
    do
      x = rand() % 9;
    while (map[t][x]||!check(t*16+x,i,map));
    map[t][x] = i;
  }
  for(;t<9;t++)
  for(int x=0,i=rand()%9;x<9;x++)
 
  
  
  	
  	

     nd = rand() % 8; for (int i = 0; i < 30 + nd; i++) { 
     //随机产生30-38个已经填出了的数字 
     x = rand() % 81; 
     //产生一个随机坐标 
     tmp = rand() % 9 + 1; 
     // 产生一个值 
     if
     (check(x / 9 * 16 + x % 9, tmp, map)) map[x / 9][x % 9] = tmp; else i--;
     } 
}
int check(char x, char c, char map[9][9]) {//返回 0为不符合规则
  int r, l;
  for (int t = 0; t < 9; t++)
    if (map[t][x % 16] % 16 == c % 16 || map[x / 16][t] % 16 == c % 16)
      return 0;
  r = x / 16 / 3;
  l = x % 16 / 3;
  for (int a = r * 3; a < r * 3 + 3; a++)
    for (int b = l * 3; b < l * 3 + 3; b++)
      if (map[a][b] % 16 == c % 16)
        return 0;

  return 1;

}

int data(char c) {

  switch (c % 16) {
  case 0:
    printf("　");
    break;
  case 1:
    printf("１");
    break;
  case 2:
    printf("２");
    break;
  case 3:
    printf("３");
    break;
  case 4:
    printf("４");
    break;
  case 5:
    printf("５");
    break;
  case 6:
    printf("６");
    break;
  case 7:
    printf("７");
    break;
  case 8:
    printf("８");
    break;
  case 9:
    printf("９");
    break;
  default:
    printf("error");
  }
}
int checkwin(char map[9][9]) {
  for (int x = 0; x < 9; x++)
    for (int y = 0; y < 9; y++)
      if (check(x * 16 + y, map[x][y], map)) {
        msg = "游戏胜利";
        return 0;
      } else
        return 1;
}