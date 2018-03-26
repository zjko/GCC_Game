#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"time.h"
int nd = 3;
void SC(char a[9][9])
{
	for (int y = 0; y < nd; y++, putchar('\n'))
		for (int x = 0; x < nd; x++)
			putchar(a[y][x]);
}

void start()
{
	char map[9][9],c;
	int x, y, k;
	srand(time(0));
	for (y = 0; y < nd; y++)
		for (x = 0, k = 0; x < nd; x++, k++)
			map[y][x] = 'A' + k;
for(int a1,b1,a2,b2,d=0;d<nd*nd;d++){
a1=rand()%nd;
a2=rand()%nd;
b1=rand()%nd;
b2=rand()%nd;
c=map[a1][b1];
map[a1][b1]=map[a2][b2];
map[a2][b2]=c;
}
SC(map);
while(1)
{


}

}



main()
{
	start();
}