#include<stdio.h>
#include<conio.h>
void sc(char *i) {
  printf("┌───┬───┬───┐\n");
  printf("│　%c　│　%c　│　%c　│\n", *i, *(i + 1), *(i + 2));
  printf("├───┼───┼───┤\n");
  printf("│　%c　│　%c　│　%c　│\n", *(i + 3), *(i + 4), *(i + 5));
  printf("├───┼───┼───┤\n");
  printf("│　%c　│　%c　│　%c　│\n", *(i + 6), *(i + 7), *(i + 8));
  printf("└───┴───┴───┘\n");
}
bool sl(char *n) {

}
main() {
  char map[9], c;
  int x;
  for (x = 0; x < 9; x++)
    map[x] = ' ';
  sc(map);
  x = 1;
  while (1) {
    c = getch();
    if (map[c - 49] != ' ')
      printf("此处已填！\n");
    else {
      switch (c - 48) {
      case 1:
        x == 1 ? map[0] = '*' : map[0] = 'O';
        break;
      case 2:
        x == 1 ? map[1] = '*' : map[1] = 'O';
        break;
      case 3:
        x == 1 ? map[2] = '*' : map[2] = 'O';
        break;
      case 4:
        x == 1 ? map[3] = '*' : map[3] = 'O';
        break;
      case 5:
        x == 1 ? map[4] = '*' : map[4] = 'O';
        break;
      case 6:
        x == 1 ? map[5] = '*' : map[5] = 'O';
        break;
      case 7:
        x == 1 ? map[6] = '*' : map[6] = 'O';
        break;
      case 8:
        x == 1 ? map[7] = '*' : map[7] = 'O';
        break;
      case 9:
        x == 1 ? map[8] = '*' : map[8] = 'O';
        break;
      }
      x *= -1;
      clrscr();
      sc(map);
      printf(x == 1 ? "请甲下棋" : "请乙下棋");
    }
sl(map);
  }
}