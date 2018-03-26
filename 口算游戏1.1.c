#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int start();
int SC(int t, int t1, int HP, int a, int b, long fs, long G, int dj[5]) {
  printf("★口算训练工具★\n");
  printf("--------------\n\033[?25l");
  printf("%d+%d=%ld\n\033[?25l", a, b, G);
  printf("生命值：\033[?25l");
  for (int i = 0; i < HP; i++, printf("❤"));
  printf("\n🕒:%d　\t💰:%ld\n\033[?25l", t - (time(0) - t1), fs);
  printf("🕑×%d  💟×%d  🌀×%d\n", dj[0], dj[1], dj[2]);
  return 0;
}
void JSHS() {
  clrscr();
  printf
    ("通过各种手段来通过游戏，让你在游戏中提高自己的心算能力\n本游戏分为三种模式\n1.经典模式 难度适中,得分一般\n2.疯狂模式 难度较高,得分较高\n3.练习模式 不计时 不限道具\n善于使用一些道具，它能在紧急的时候帮到你\n🕑　本局延长5秒钟\n💟　自动得出百位之前的数据\n🌀　跳过本轮\n按下空格则取消输入\n按任意键开始\n");

  getch();
  clrscr();
  start();
}

int SHOOP(int dj[5], long fs, int HP) {


  int a[5], t = time(0);
  for (int i = 0; i < 5; a[i++] = rand() % (fs / 15) + fs / 12);

  while (1) {
    printf
      ("💰💰　RP商店　💰💰\n🕑　%d×💰　本局延迟五秒\n💟　%d×💰　自动求出百位之前\n🌀　%d×💰　更换此局题目\n💗　%d×💰　生命值加一 \n输入0退出商城\n每个道具上限为五个，超过则无法购买\n",
       a[0], a[1], a[2], a[3]);
    printf("🕒:%d　\t分数：%d\n\033[?25l", 12 - time(0) + t, fs);
    printf("🕑×%d  💟×%d  🌀×%d\n", dj[0], dj[1], dj[2]);
    while (kbhit()) {
      switch (getch()) {
      case '1':
        if (dj[0] < 5) {
          dj[0]++;
          fs -= a[0];
        }
        break;
      case '2':
        if (dj[1] < 5) {
          dj[1]++;
          fs -= a[1];
        }
        break;
      case '3':
        if (dj[2] < 5) {
          dj[2]++;
          fs -= a[2];
        }
        break;
      case '4':
        if (HP < 5) {
          HP++;
          fs -= a[3];
        }
        break;
       case '0':return 0;
      }
    }
    if (12  - time(0) + t < 0||fs-a[0]-a[1]<0)
      return 0;
    clrscr();
    usleep(80000);
  }
}
int start() {
  int t = 5, HP = 5, ND = 10, m = 1, MS;
  long fs = 0, G,a,b;
  // t设定时间初始值，HP生命值，ND难度系数，fs分数，G答案，商店

  int dj[5];
  for (int i = 0; i < 5; dj[i++] = 3);
  printf
    ("🍎　口算训练游戏 🍊\n请选择游戏模式\n🔯　经典模式\n♉　疯狂模式\n♐　练习模式\n♈　玩法介绍\n");
  MS = getch();

  while (1) {
    if (fs > 800)
      if (rand() % 8 == 0)
        SHOOP(dj, fs, HP);
    // 10%的概率碰到商店
    m = 1;
    switch (MS) {
    case '1':
      if (fs > ND) {            // 难度根据得分来调整
        ND += t * t;
        t += 1;
      }
      break;
    case '2':
      if (fs > ND) {
        ND += fs;
        t += 2;
      }
      break;
    case '3':
      t = 9999;
      for (int i = 0; i < 5; dj[i++] = 999);
      if (fs > ND)
        ND += fs / 4;
      break;
    case '4':
      JSHS();
    }

    while (m) {
      int t1 = time(0);
      G = 0;
      a = rand() % ND;
      b = rand() % ND;
      while (1) {
        while (kbhit()) {

          char c;

          c = getch();
          if (c > 47 && c < 58) {
            G *= 10;
            G += c - 48;
          } else
            switch (c) {

            case ' ':
              G = 0;
              break;
            case '@':
              if (dj[0] > 0) {
                dj[0]--;
                t1 += 5;
              }
              break;
            case '%':
              if (dj[1] > 0) {
                dj[1]--;
                G = (a + b) / 100;
              }
              break;
            case '+':
              if (dj[2] > 0) {
                dj[2]--;
                a = 0;
                b = 0;
                G = 0;
              }
              break;
             case '-':
             clrscr();
             puts("游戏暂停，按任意键开始");
             while(!kbhit());
            }
        }
        if (G == a + b) {
          fs += G;
          m = 0;
          break;
        }
        if (t - time(0) + t1 < 0) {
          printf("时间到,HP=%d\n", --HP);
          sleep(1);
          break;
        }
        SC(t, t1, HP, a, b, fs, G, dj);
        usleep(50000);
        clrscr();
      }

      if (HP < 1) {
        printf("游戏结束！\n\t你的分数是%d\n按-重新开始\n", fs);
        while (1)
          if (getch() == '-')
            return 0;
      }
      else if(fs<0){
      	printf("恭喜你已经通关,你已获得超级神算的称号！\n去寻找更强的挑战吧！"); 
      	
      	}

    }
  }
}
int main() {
  srand(time(0));
  while (1)
    start();
}