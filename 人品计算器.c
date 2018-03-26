#include"stdio.h"
#include"conio.h"
main()
{

	char xm[20];
	int x, s;
	while (1)
	{
		x = 0;
		while (x < 20)
			xm[x++] = 0;
		printf("终极人品计算器\n");
		printf("请输入姓名：");
		scanf("%s", xm);
		printf("%s\n",xm);
		for (x = 0, s = 0; x < 20; x++)
			s += xm[x];
		s %= 100;
		printf("此人的人品为  %d\n", s);
		printf("评语:");
		if (s >= 95)
			printf("您如天宫之皓月，吾等计算器怎敢比拟\n");
		else if (s >= 90)
			printf("\n");
		else if (s >= 80)
			printf("\n");
		else if (s >= 70)
			printf("\n");
		else if (s >= 60)
			printf("\n");
		else if (s >= 50)
			printf("\n");
		else if (s >= 40)
			printf("扪心自问一下是不是干了什么缺德事\n");
		else if (s >= 30)
			printf("\n");
		else if (s >= 20)
			printf("\n");
		else if (s >= 10)
			printf("\n");
		else if (s >= 0)
			printf
				("隔壁老王家的母猪为何半夜连连惨叫，敬老院的避孕套为何频频失窃，这一切的一切到底是精神的扭曲还是道德的沦丧，是荷尔蒙的爆发还是饥渴与无奈，敬请关注%s的不归路——\n",
				 xm);
		else
			printf("\n");


		x = getchar();
		x = getchar();
		clrscr();
	}
}