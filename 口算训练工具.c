//口算训练工具
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void sc(int a,int b,int HP,long fs)
{
	printf("★杰哥口算训练程序★\n");
	printf("当前分数为：%d\n",fs);
	printf("HP:");
	for(int x=1;x<=HP;x++,printf("♥"));
	putchar('\n');
	printf("───────────────────\n");
	printf("%d+%d=",a,b);
	
	
	}
main(){
	srand(time(0));
	long fs=0;
	for(int GK=10,i=5,HP=5;HP>0;GK*=10,i++){
		for(int a,b,G,t=1;t<i;t++)
		{
		G=NULL;
			a=rand()%GK;
			b=rand()%GK;
			sc(a,b,HP,fs);
			scanf("%d",&G);
			sleep(1);
			if(G!=a+b){
					printf("\n回答错误！！！正确答案是%d,HP=%d\n",a+b,--HP);
					fs-=a+b;
			}
			else	{printf("\n回答正确，进入下一关\n");
			fs+=G;
			}
		
		clrscr();

		}
	}
}