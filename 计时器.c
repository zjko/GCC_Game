//c语言计时器(伪)
#include<stdio.h>
#include"conio.h"
#include"time.h"
int main() {
  // 初始化
  char c;
  int t = time(0);
  while (1) {
    while (kbhit())
      c = getch();
     clrscr();

    printf("%d\n%d\n计时器%d\n%c\n\033[?25l", time(0), t, time(0) - t, c);
    usleep(10000);
  }

}