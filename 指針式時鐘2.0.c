/*********************
控制台指針式時鐘  v2.0
可以自動讀取手機系統時間
修復針指在12 和6 位置時的分不清楚的問題
仍存在 時針 進位不夠精確的問題 會在以後加以修改


※■■■■■請把字體調到最小  4*8點陣字體

by_小鞠爱猫猫  不太會指針 距高考還有199天
******************************/
#include "stdio.h"
#include"stdlib.h"
#include "conio.h"
#include "math.h"
#include "time.h"
#define PI 3.141592654          // 定義pi
#define PY PI/30                // 時鐘的一小格所代表的弧度數
int time_now();                 // 讀取時間函數
double abs(double a);           // 絕對值函數
int x = 0, y = 0, a = -28, b = 28, c = 1; // a,b是界面範圍c是單位長度
int h = 0, m = 0, s = 0;        // 時 分 秒 可以
int hh = 1, mm = 1, ss = 1;     // 爲了調整針的寬度寬度用
                                // 已基本實現
double angle, angle_s = PI / 2, angle_m = PI / 2, angle_h = PI / 2; // 初始化tan的弧度數

int main() {
  printf("\033[?25l");          // 隱藏光標
  time_now();
 /***根據時 分 秒初始化 针 的位置*/
  angle_s = angle_s - s * PY;
  angle_m = angle_m - m * PY;
  angle_h = angle_h - 5 * h * PY;



  for (;;) {                    // 死循環
    clrscr();
    // printf("%d:%d:%d\n", h, m, s);
    time_t t = time(0);
    printf("%s", ctime(&t));    // 顯示當前時間
    for (y = b; y >= b - abs(2 * a); y = y - c) {
      for (x = a; x <= a + abs(2 * b); x = x + c) {
        /***調整針寬度**/
        if (abs(tan(angle_s)) >= 6)
          ss = 10;
        else
          ss = 1;
        if (abs(tan(angle_m)) >= 6)
          mm = 10;
        else
          mm = 1;
        if (abs(tan(angle_h)) >= 6)
          hh = 10;
        else
          hh = 1;


        /****圓形錶盤**/
        if (x * x + y * y >= 600 && x * x + y * y <= 700)
          printf("\033[44;34m&&\033[0m");


         /***畫陰影 增加立體感 這樣一來看起來更加的 beautiful   →_→****/
        else if ((x - 1) * (x - 1) + (y + 1) * (y + 1) >= 600
                 && (x - 1) * (x - 1) + (y + 1) * (y + 1) <= 700)
          printf("\033[40;30m&&\033[0m");


     /*****秒針*分x<0,x>0,x==0繪製界面 下面同理***/
        else if (tan(angle_s) * x > y - ss && tan(angle_s) * x < y + ss
                 && x * x + y * y <= 400 && x > 0 && s < 30)
          printf("\033[45;35m&&\033[0m");
        else if (tan(angle_s) * x > y - ss && tan(angle_s) * x < y + ss
                 && x * x + y * y <= 400 && x < 0 && s > 30)
          printf("\033[45;35m&&\033[0m");
        else if (y > 0 && x * x + y * y <= 400 && x == 0 && s == 0)
          printf("\033[45;35m&&\033[0m");
        else if (y < 0 && x * x + y * y <= 400 && x == 0 && s == 30)
          printf("\033[45;35m&&\033[0m");


       /******分針 *****/
        else if (tan(angle_m) * x > y - mm && tan(angle_m) * x < y + mm
                 && x * x + y * y <= 300 && x > 0 && m < 30)
          printf("\033[43;33m&&\033[0m");
        else if (tan(angle_m) * x > y - mm && tan(angle_m) * x < y + mm
                 && x * x + y * y <= 300 && x < 0 && m > 30)
          printf("\033[43;33m&&\033[0m");
        else if (y > 0 && x * x + y * y <= 300 && x == 0 && m == 0)
          printf("\033[43;33m&&\033[0m");
        else if (y < 0 && x * x + y * y <= 300 && x == 0 && m == 30)
          printf("\033[43;33m&&\033[0m");


       /*******時針**/
        else if (tan(angle_h) * x > y - hh && tan(angle_h) * x < y + hh
                 && x * x + y * y <= 200 && x > 0 && h < 6)
          printf("\033[46;36m&&\033[0m");
        else if (tan(angle_h) * x > y - hh && tan(angle_h) * x < y + hh
                 && x * x + y * y <= 200 && x < 0 && h > 6)
          printf("\033[46;36m&&\033[0m");
        else if (y > 0 && x * x + y * y <= 200 && x == 0 && h == 0)
          printf("\033[46;36m&&\033[0m");
        else if (y < 0 && x * x + y * y <= 200 && x == 0 && h == 6)
          printf("\033[46;36m&&\033[0m");


       /****畫出錶盤的小格格**/
        else if (x == 0 && y != 0 && x * x + y * y >= 520
                 && x * x + y * y <= 600)
          printf("\033[42;32m&&\033[0m");
        else if (y == 0 && x != 0 && x * x + y * y >= 520
                 && x * x + y * y <= 600)
          printf("\033[42;32m&&\033[0m");
        else
          if ((tan(25 * PY) * x > y - 1 && tan(25 * PY) * x < y + 1
               || tan(20 * PY) * x > y - 1 && tan(20 * PY) * x < y + 1
               || tan(10 * PY) * x > y - 1 && tan(10 * PY) * x < y + 1
               || tan(5 * PY) * x > y - 1 && tan(5 * PY) * x < y + 1)
              && x * x + y * y >= 520 && x * x + y * y <= 600)
          printf("\033[42;32m&&\033[0m");
        else if (x == 0 && y == 0)
          printf("\033[41;31m&&\033[0m");
        else if (x * x + y * y <= 600)
          printf("\033[47;37;5mMM\033[0m");




          /**空白處*/
        else
          // printf("\033[40;30;5m \033[0m");
          // printf("\033[40;30;6m \033[0m");
          printf("\033[47;37m  \033[0m");
      }
      printf("\n");
    }
    angle_s = angle_s - PY;
    s++;
    if (s == 60)                // 秒針進位
    {
      m++;
      angle_m = angle_m - PY;
      s = 0;
    }
    if (m == 60)                // 分針進位
    {
      angle_h = angle_h - 5 * PY; // 時針一格是五個小格所以乘五
      h++;
      m = 0;
    }
    if (h == 12) {
      h = 0;
    }
    // getch();
    usleep(900000);             // 延时設成1s會慢
    // 設成0.9s才是準確的
    // 究竟是爲什麽呢？

  }

}

int time_now() {
  char c[55] = { }, hour[5], minute[5], second[5];
  time_t t = time(0);
  sprintf(c, "%s", ctime(&t));
  hour[0] = c[11];
  hour[1] = c[12];
  minute[0] = c[14];
  minute[1] = c[15];
  second[0] = c[17];
  second[1] = c[18];
  h = atoi(hour);
  m = atoi(minute);
  s = atoi(second);
  /* sprintf(h,"%s",hour); sprintf(m,"%s",minute); sprintf(s,"%s",second); */
  return 0;
}







double abs(double a) {
  if (a < 0)
    return -a;
  else
    return a;
}













/* int time() { int i=0; for(i=0;i<100;i++) { clrscr();
   printf("\033[22;32m当前運行时间%ds\n",i); sleep(1);
   //或usleep(2000);

   } } */