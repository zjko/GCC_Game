
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int t, hammer = 10, HP = 5, cash = 30; // 读取当前时间

void JSHS(){
	
	}




int CSHM(char map[][302], int x, int y) {

  for (int i = 0; i < x * y / 2; i++)
    map[rand() % x + 1][rand() % y + 1] = ' ';
  // 空白区域

  for (int i = 0; i < 40; i++)
    map[rand() % x + 1][rand() % y + 1] = 'H';
  // 锤子
  for (int i = 0; i < 40; i++)
    map[rand() % x + 1][rand() % y + 1] = 'T';
  // 时间
  for (int i = 0; i < 60; i++)
    map[rand() % x + 1][rand() % y + 1] = '$';
  // 钱
  for (int i = 0; i < 20; i++)
    map[rand() % x + 1][rand() % y + 1] = '1';
  // 💀
  for (int i = 0; i < 15; i++)
    map[rand() % x + 1][rand() % y + 1] = '2';
  // 🐍
  for (int i = 0; i < 15; i++)
    map[rand() % x + 1][rand() % y + 1] = '3';
  // 🐗
  for (int i = 0; i < 15; i++)
    map[rand() % x + 1][rand() % y + 1] = '4';
  // 🐛
  for (int i = 0; i < 10; i++)
    map[rand() % x + 1][rand() % y + 1] = '5';
  // 🌊
  for (int i = 0; i < 10; i++)
    map[rand() % x + 1][rand() % y + 1] = '6';
  // 🍎

  for (int x1 = 0; x1 < x + 1; x1++)
    map[x1][0] = map[x1][y] = '|';
  for (int y1 = 0; y1 < y + 1; y1++)
    map[0][y1] = map[x][y1] = '-';
    //画地图边界

}


void syw(char sy[][15]) {
  for (int x1 = 0; x1 < 8; x1++, putchar('\n'))
    for (int y1 = 0; y1 < 15; y1++)
      switch (sy[x1][y1]) {
      case '6':
        printf("🍎");
        break;
      case '#':
        printf("🌴");
        break;
      case 'O':
        printf("🏃");
        break;
      case '$':
        printf("💰");
        break;
      case 'H':
        printf("🔨");
        break;
      case 'T':
        printf("🕒");
        break;
      case ' ':
        printf("  ");
        break;
      case '-':
        printf("🚧");
        break;
      case '|':
        printf("⚠");
        break;
      case '1':
        printf("💀");
        break;
      case '2':
        printf("🐍");
        break;
      case '3':
        printf("🐗");
        break;
      case '4':
        printf("🐛");
        break;
      case '5':
        printf("🌊");
        break;
      }




  printf("🕒:%d 🔨:%d 💜:%d 💰:%d\n", 120 - (time(0) - t),
         hammer, HP, cash);
}

void window(int px, int py, char sy[][15], char map[][302]) {
  int x1 = px - 4, y1 = py - 7;
  if (x1 < 0)
    x1 = 0;
  if (y1 < 0)
    y1 = 0;
  for (int m = 0; m < 8; m++, x1++)
    for (int n = 0, i = y1; n < 15; n++, i++)
      sy[m][n] = map[x1][i];
}

int CPS(char map[][302], int px, int py) { // 触碰系统
  switch (map[px][py]) {
  case '6':
    HP++;
    break;
  case '1':
    return 1;
    break;
  case '2':
    HP--;cash+=3;
    break;
  case '3':
    if (hammer > 2) {
      hammer -= 2;
      HP--;
      cash+=50;
    } else
      return 1;
    break;
  case '4':
    rand() % 2 ? HP-- : HP -= 2;
    break;
  case '5':
    return 1;

  case ' ':
    break;
  case '#':
    if (hammer > 0){
      hammer--;cash+=1;
    }
    else
      return 1;
    break;
  case 'H':
    hammer++;
    break;
  case 'T':
    t += 5;
    break;
  case '$':
    cash += 5;
    break;
  case '-':
    return 1;
    break;
  case '|':
    return 1;
    break;
  }

  return 0;
}




int main() { printf("游戏介绍\n爱冒险的你，为了挑战自我只身来到了这个孤岛，然而这个小岛上的一切并不是你想的这样简单，你需要做的是在这里活下去！❗强烈建议字体设置20点阵，9宫格数字键盘\n按5键开始\n详细介绍输入1\n");
  if(getch()=='1')JSHS();
  clrscr();
  int start(int gq);
  srand(time(0));
  t=time(0);
  int gq = 1;                   // 难度系数(关卡)
  while (gq < 251) {
    start(gq);
    gq += 10;
  }
  return 0;
}




// 开始游戏
int start(int gq) {
  char map[302][302];
  // 地图极限大小为300*300
  char sy[8][15];
  int px, py;
  // px py玩家坐标


  int x, y;
  x = 50 + rand() % gq;
  y = 50 + rand() % gq;
  // 随机产生地图空间

  for (int x1 = 1; x1 < x; x1++)
    for (int y1 = 1; y1 < y; y1++)
      map[x1][y1] = '#';
  // 初始化地图

  CSHM(map, x, y);
  // 随机生成地图



  px = rand() % 10 + 5;
  py = rand() % 10 + 5;
  // 确定初始位置
  map[px][py] = 'O';
  window(px, py, sy, map);
  syw(sy);
  while (1) {

if(HP<1||120-time(0)+t);
else {
	printf("挑战失败！\n\t你未能存活下来。\n"); 
	exit(0);
}

    while (kbhit()) {           // 计时系统，判断按键

      switch (getch()) {        // 根据按键做出反应
      case '2':

        if (CPS(map, px - 1, py) != 1) {
          map[px][py] = ' ';
          sy[px][py] = ' ';
          map[--px][py] = 'O';
        }
        break;
      case '5':
        if (CPS(map, px + 1, py) != 1) {
          map[px][py] = ' ';
          sy[px][py] = ' ';
          map[++px][py] = 'O';
        }

        break;


      case '4':
        if (CPS(map, px, py - 1) != 1) {
          map[px][py] = ' ';
          sy[px][py] = ' ';
          map[px][--py] = 'O';

        }
        break;
      case '6':
        if (CPS(map, px, py + 1) != 1) {
          map[px][py] = ' ';
          sy[px][py] = ' ';
          map[px][++py] = 'O';
        }
        break;
      }

    }
    window(px, py, sy, map);    // 进行窗口锁定
    syw(sy);                    // 输出视野
    usleep(100000);              // 0.1秒钟一帧
    clrscr();
  }
  
}