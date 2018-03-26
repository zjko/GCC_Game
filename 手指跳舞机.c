#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define V 500000
int fs = 0, HP = 10, t ;
char pf = 0;
int main() {
	t=time(0);
  int start();
  while (1) {
    start();
    printf("重新开始？(Y)\n");
    if (getch() != 'Y') {
      t = time(0);
      fs = 0;
      HP = 10;
      clrscr();
    }
    return 0;
  }
}

int start() {
  int PF(char *p, char c);
  void SC(char str[10][5]);
  int game(char str[10][5]);
  srand(time(0));
  char map[10][5] = { 0 }, c;
  printf("🎶 　 \033[42;37;5m手指跳舞机\033[43;37;0m 　🎉\n");
  printf("\n\n  🔯　按任意键开始");
  getch();
  clrscr();

  while (1) {

    while (kbhit()) {
      c = getch();
      if (PF(&map[7][0], c))
        fs += 1, pf = 1;
      else if (PF(&map[8][0], c))
        fs += 3, pf = 2;
      else
        pf = 3, HP--;

    }
    for (int i = 0; i < 5; i++)
      if (map[9][i] != 0)
        pf = 4, HP--;




    game(map);
    usleep(V);
    clrscr();
    SC(map);
    if (HP < 0)
      return 0;

  }

}

void SC(char str[10][5]) {
  printf("🎶 　\033[42;37;5m手指跳舞机\033[43;37;0m　🎉\n");
  for (int y = 0; y < 8; y++, putchar('\n')) {
    for (int x = 0; x < 5; x++)
      switch (str[y][x]) {
      case '1':
        printf("↖　");
        break;
      case '2':
        printf("↑　");
        break;
      case '3':
        printf("↗　");
        break;
      case '4':
        printf("←　");
        break;
      case '5':
        printf("●　");
        break;
      case '6':
        printf("→　");
        break;
      case '7':
        printf("↙　");
        break;
      case '8':
        printf("↓　");
        break;
      case '9':
        printf("↘　");
        break;
      case '0':
        printf("✪　");
        break;
      case 0:
        printf("　　");
        break;
      default:
        printf("%c　", str[y][x]);
      }
    switch (y) {
    case 1:
      printf("分数:%d", fs);
      break;
    case 3:
      printf("生命值：");
      break;
    case 4:
      for (int i = 0; i < HP; i++)
        printf("\033[41;37;5m \033[43;37;0m");
      break;
    case 7:
      printf(pf == 1 ? "\033[41;37;5m真棒！\033[43;37;0m" : pf ==
             2 ? "\033[44;37;5m完美！\033[43;37;0m" : pf ==
             3 ? "\033[42;37;5m真遗憾\033[43;37;0m" : pf ==
             4 ? "\033[45;37;5m漏掉了\033[43;37;0m" : "");

      break;
    }


  }
  pf = printf("\033[45;37;5m　　　完　美　　　\033[43;37;0m\n");
}
int game(char str[10][5]) {
  for (int y = 8; y >= 0; y--)
    for (int x = 0; x < 5; x++)
      str[y + 1][x] = str[y][x];
  if (rand() % 2)
    for (int i = 0; i < 5; str[0][i++] = 0);
  else
    for (int t = 0; t < rand() % 2; t++)
      str[0][rand() % 5] = rand() % 10 + 48;

  return 0;

}

int PF(char *p, char c) {
  for (int i = 0; i < 5; i++)
    if (*(p + i) == c) {
      *(p + i) = 0;
      return 1;
    }
  return 0;

}