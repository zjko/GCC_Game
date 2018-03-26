#define String char*
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
/* 
//代码默认环境为Linux GCC标准 //若要移植到Windows环境
//请删除外层注释 
   #define clrscr() system("cls") 
   #define getch() _getch()
*/
typedef struct Game2048 {
  int map[4][4];
  int score;
  const String RankFilePath = "2048.dat";
  // 数据模型
  void View() {
    // 输出映射
    for (int y = 0; y < 4; y++, putchar('\n'))
      for (int x = 0; x < 4; x++)
        switch (map[x][y]) {
          // 控制视图 屏幕显示的内容
          // 对数据模型进行输出映射
          case 0:
          printf("　　");
          break;
          case 2:break;
          case 4:break;
          case 8:break;
          case 16:break;
          case 32:break;
          case 64:break;
          case 128:break;
          case 256:break;
          case 512:break;
          case 1024:break;
          case 2048: break;
        } printf("分数%d", score);
  };
  void Control() {
    // 流程控制

    initMap();
    while (true) {
      // 获得输入并响应
      switch (getch()) {
      case '2':
        InputUp();
        break;
      case '4':
        InputLeft();
        break;
      case '5':
        InputDown();
        break;
      case '6':
        InputRight();
        break;
      default:;
      }
      // 刷新
      clrscr();
      View();
      // 判断游戏是否已经结束
      if (judgeDie() == true)
        return;
    }
  };
  void MapFill() {
    // 在地图空处随机产生两个数字 2 或 4
  };
  int judgeDie() {
    // 判断游戏是否结束 
  };
  void InputLeft() {
    // 响应左输入 下同
  };
  void InputRight() {
  };
  void InputDown() {
  };
  void InputUp() {
  };
  void initMap() {
    // 地图初始化
    // 设置随机种子 实现随机数
    srand(time(0));

  };
  void Rank() {
    // 分数排名 一般在游戏结束之后调用
  };
} Game2048;
int main() {
  Game2048 game;
  game.Control();
}