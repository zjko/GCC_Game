#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
int fs = 0;
void sc(int map[4][4]) {
  for (int y = 0; y < 4; y++, putchar('\n'))
    for (int x = 0; x < 4; x++)
      switch (map[x][y]) {
      case 0:
        printf("　　");
        break;
      case 2:
        printf("\033[48;32;5m 2　\033[47;32;0m");
        break;
      case 4:
        printf("\033[47;31;5m 4　\033[43;37;0m");
        break;
      case 8:
        printf("\033[41;37;5m 8　\033[43;37;0m");
        break;
      case 16:
        printf("\033[42;37;5m 16 \033[43;37;0m");
        break;
      case 32:
        printf("\033[43;37;5m 32 \033[43;37;0m");
        break;
      case 64:
        printf("\033[44;37;5m 64 \033[43;37;0m");
        break;
      case 128:
        printf("\033[45;37;5m128 \033[43;37;0m");
        break;
      case 256:
        printf("\033[46;37;5m256 \033[43;37;0m");
        break;
      case 512:
        printf("\033[47;37;5m512 \033[43;37;0m");
        break;
      case 1024:
        printf("\033[48;37;5m1024\033[43;37;0m");
        break;
      case 2048:
        printf("\033[49;37;5m2048\033[43;37;0m");
        break;
      }
  printf("分数%d", fs);
}


void rank() {
  FILE *p = NULL;
  int score[8];
  for (int i = 0; i < 8; i++)
    score[i] = 0;
  printf("游戏结束，您的分数是%d\n以下是排名：\n",fs);
  p=fopen("2048data.kzj","a+");
  fclose(p);
  p = fopen("2048data.kzj", "r");
    for (int i = 0; i < 8 && !feof(p); i++)
      fscanf(p, "%d\n", &score[i]);
    fclose(p);
   for (int i = 0; i < 8; i++)
    if (fs > score[i]) {
    	puts("\033[47;31;5m恭喜刷新记录!\033[43;37;0m");
      printf("击败了上一名%d的记录\n", score[i]);
      score[i]+=fs;
      fs=score[i]-fs;
      score[i]-=fs;
      while(i<8){
      i++;
       score[i]+=fs;
      fs=score[i]-fs;
      score[i]-=fs;
      }
      score[i]=fs;
      break;
    }
  p = fopen("2048data.kzj", "w");
  for (int i = 0; i < 8; i++)
    fprintf(p, "%d\n", score[i]);

  for (int i = 0; i < 8; i++)
    printf("NO.%d\t%d\n", i + 1, score[i]);
  fclose(p);
  exit(0);
}

void sjs(int map[4][4]) {
  int x, y;
  int i = 0;
  for (x = 0; x < 4; x++)
    for (y = 0; y < 4; y++)
      if (map[x][y] == 0)
        i++;
  while (i) {
    x = rand() % 4, y = rand() % 4;
    if (map[y][x] == 0) {
      map[y][x] = rand() % 2 ? 4 : 2;
      break;
    }
  }
}
int start() {
  int map[4][4], x, y, k, t = 0;
  for (y = 0; y < 4; y++)
    for (x = 0; x < 4; x++)
      map[y][x] = 0;
  sjs(map);
  sjs(map);
  sc(map);
  while (1) {
    t = fs;
    switch (getch()) {
    case '4':
      for (k = 4; --k > 0;)
        for (y = 1; y < 4; y++)
          for (x = 0; x < 4; x++)
            if (map[y - 1][x] == map[y][x] || map[y - 1][x] == 0)
              map[y - 1][x] += map[y][x], map[y][x] = 0;
      sjs(map);
      break;
    case '2':
      for (k = 4; --k > 0;)
        for (x = 1; x < 4; x++)
          for (y = 0; y < 4; y++)
            if (map[y][x - 1] == map[y][x] || map[y][x - 1] == 0)
              map[y][x - 1] += map[y][x], map[y][x] = 0;
      sjs(map);
      break;
    case '6':
      for (k = 4; --k > 0;)
        for (y = 2; y >=0; y--)
          for (x = 0; x < 4; x++)
            if (map[y + 1][x] == map[y][x] || map[y + 1][x] == 0)
              map[y + 1][x] += map[y][x], map[y][x] = 0;
      sjs(map);
      break;
    case '5':
      for (k = 4; --k > 0;)
        for (x = 2; x >=0; x--)
          for (y = 0; y < 4; y++)
            if (map[y][x + 1] == map[y][x] || map[y][x + 1] == 0)
              map[y][x + 1] += map[y][x], map[y][x] = 0;
      sjs(map);
    default:
      t = 0;
    }

    for (fs = 0, x = 0; x < 4; x++)
      for (y = 0; y < 4; y++)
        fs += map[x][y];

    clrscr();
    if (fs == t)
      rank();

    sc(map);

  }

}
int main() {
  srand(time(0));
  start();
  rank();
  return 0;
}