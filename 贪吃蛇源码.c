
/*推荐字体，，，，。10点阵！！！！！

*/
// 首先我们要包含头文件
#include<stdio.h>				// 基本输入输出
#include<conio.h>				// 屏幕操作
#include<stdlib.h>				// 系统相关

void move();
void start();
void draw();
void getturn();
void turn(char direction);
void judge();
void getfood();
void over();
/* 接着，让我们来宏定义几个数据 */
#define H 12 /*地图的高*/ 
#define W 30/*地图的宽*/ 
#define N 10	/* 难度系数 */
/* 既然有了大致思路，那么我们就来一个个实现,先是定义变量 */
 int a, b, x, y, l = 0, n, i, j;
int x1, y1;
char *head  , *tail  ,*tt , map[H][W];
char *belly[H * W]  , *food /* 食物 */ ;
char left, right, front, back;	/* 各个方向 */
/* 我们要有一个基本思路，所以先写main函数 */ int main()
{
	start();					/* 初始化游戏的数据 */
	turn(front);				/* 转向函数 */
	getfood();					/* 产生食物 */
	draw();						/* 画图 */
	while (1)					/* 游戏就是循环，直到死亡 */
	{
		usleep(5000000 / N);	/* 休眠函数，不然蛇跑的太快，N是我们定义的难度系数 */
		getturn();				/* 得到我们输入的转向 */
		move();					/* 接着蛇就移动 */
		judge();				/* 移动完成后判断一下，是撞墙了，还是吃到蛋了 */
		clrscr();				/* 系统的清屏函数 */
		draw();					/* 游戏就是反复的画图给我们看 */
	}
}

																														
/* 然后是各个函数 */ void start()
{
	for (i = 0; i != H; ++i)
		for (j = 0; j != W; ++j)
		{
			if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1))
				map[i][j] = '9';
			else
				map[i][j] = '0';
		}						/* 以上是初始化地图,地图数组的四周被赋予'9',其它的赋予'0' */
	x = W / 2, y = H / 2;		/* x,y是蛇的坐标，这里赋值在地图的中心 */
	head = &map[y][x + 1];		/* 给蛇头一个坐标指针 */
	belly[l] = &map[y][x];		/* 蛇身 */
	tail = &map[y][x - 1];		/* 蛇尾 */
	*head = '1';				/* 蛇头指向的坐标赋予1 */
	*belly[0] = '2';			/* 蛇身赋予2 */
	*tail = '3';				/* 蛇尾赋予3 */
	left = '2', right = '8';
	front = '6', back = '4';	/* 定义上下左右为2846,手机方便操控 */
}

/* 按照顺序，这个是转向 */ void turn(char direction)
{
	switch (direction)			/* 判断传进的字符 */
	{
	case '2':
		--y;					/* 为什么是--y?因为手机的左上角是（0,0）,我们要向上，当然要减小 */
		break;
	case '8':
		++y;
		break;
	case '4':
		--x;
		break;
	case '6':
		++x;
		break;
	}
}

/* 我们需要得到食物 */
void getfood()
{
	do
	{
		x1 = random() % (W - 2) + 1;
		y1 = random() % (H - 2) + 1;	/* 产生随机的蛋蛋坐标 */
	}
	while (map[y1][x1] != '0');	/* 当蛋蛋的坐标代表的地图那里不是空白，继续执行上面的循环 */
	food = &map[y1][x1];		/* 将食物指针指向得到的坐标 */
	*food = '4';				/* 将坐标处的值替换成4 */
}

/* 接下来就是重要的。把游戏显示出来 */
void draw()
{
	for (i = 0; i != H; ++i)
	{
		for (j = 0; j != W; ++j)	/* 我们用两个循环来查看整个地图 */
			switch (map[i][j])	/* 对地图坐标代表的值进行判断 */
			{
			case '0':			/* 当遇到空白时，我们打印空格 */
				printf(" ");
				break;
			case '9':			/* 当遇到墙时，我们打印#号 */
				printf("#");
				break;
			case '1':			/* 遇到蛇头时 */
				printf("O");
				break;
			case '2':			/* 遇到蛇身时 */
				printf("o");
				break;
			case '3':			/* 遇到蛇尾 */
				printf(".");
				break;
			case '4':			/* 遇到食物 */
				printf("♥");
				break;
			}
		printf("\n");			/* 每次打印完一排，我们就要换行，不然就不是方形墙了 */
	}
}

/* 蛇不能光自己跑，还要按我们控制的方向跑 */ void getturn()
{
	char t;						/* 定义一个字符变量，用来接受我们的输入 */
	while (kbhit())				/* 这里比较难理解,kbhit()函数是：当我们有输入时，值为true,没有输入时，值为false,当我们有输入时，执行循环（得到我们的输入），没有输入时，就跳过while循环，让蛇继续原方向走 */
	{
		t = getch();			/* 这个函数是得到一个输入 */
		if (t == left)			/* 判断输入的是不是left,left我们定义的是2 */
		{
			turn(left);
			left = back;		/* 方向一边，那么原本定义的上下左右值就全变了，所以来个转换 */
			back = right;
			right = front;
			front = t;
			goto gett;			/* 跳到gett标志处 */
		}
		else if (t == right)	/* 同上 */
		{
			turn(right);
			right = back;
			back = left;
			left = front;
			front = t;
			goto gett;
		}
	}
	turn(front);				/* 如果没有输入，我们默认是像前进 */
  gett:;
	while (kbhit())
		t = getch();
}

/* 我们得到了前进的方向，那么我们就开始移动吧 */
void move()
{
	tt = belly[l];				/* 零时的尾巴 */
	for (i = l; i != 0; --i)	/* 蛇身如果有多节，那么久伸长 */
		belly[i] = belly[i - 1];
	belly[0] = head;			/* 因为蛇在前进，所以蛇身的第一节伸到原来的头部 */
	*belly[0] = '2';			/* 将值替换成蛇身的值 */
	head = &map[y][x];			/* 头部赋予新的坐标 */

}

/* 我们的蛇已经前进了，那么前方是什么呢？ */
void judge()
{

	switch (*head)				/* 判断头部的值是什么 */
	{
	case '2':
	case '9':
		over();					/* 如果是蛇身或墙，直接over */
		break;
	case '4':					/* 如果是食物，那么我们吃掉它 */
		getfood();
		++l;					/* 吃完之后蛇要伸长 */
		belly[l] = tt;
		break;

	case '0':					/* 如果前面是空白 */
		*tail = '0';			/* 把尾巴的值变成空白，因为我们移走了 */
	case '3':
		*head = '1';			/* 如果是蛇尾，我们继续前进，不管 */
		tail = tt;
		*tail = '3';
		break;
	}

}

void over()/*这个函数在蛇死的时候提示是否继续*/
{
	printf("\tGame over!!!\n");
	printf("\t\tAgain?\n");
	getch();
	clrscr();
	start();
}