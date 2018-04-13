
//According to different system modifications
#define CLEARSCREEN system("cls")
#define Keying		getch()


//Game Setting
#define CB_Color_Space 	" "
#define CB_Color_First 	"#"
#define CB_Color_Second "+"
#define CB_Color_Select "^"

//Operation Key Setting
#define Operation_Down 	'2'
#define Operation_UP 	'8'
#define Operation_Left 	'4'
#define Operation_Right '6'
#define Operation_Enter '5'
/*
//Service
#define ServiceIP
#define ServicePort
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct Gobang {

	char CB[15][15];		//Checkerboard
	bool CP = true;			//true is first;
	char *MSG;
	char GameModel;

	struct {
		int x:4;
		int y:4;
	} Position;
	int MenuView() {
		while(1) {
			puts("a. AI");
			puts("b. Online");
			puts("c. Player by Yourself");
			printf("x. %s (Select to Change)\n",CP?"First":"Second");
			puts("y. FAQ");
			puts("z. About");
			puts("Q. Quit");
			switch(GameModel=Keying) {		//select
				case 'a':CLEARSCREEN;	AI();							break;
				case 'b':CLEARSCREEN;	Online();					break;
				case 'c':CLEARSCREEN;	PlayByYourself();	break;
				case 'x':CLEARSCREEN;	CP = !CP;					break;
				case 'y':
				case 'z':
					break;
				default:
					CLEARSCREEN;	puts("Bad Input,Please try again");
			}
		}

	};

	int GameView() {
		CLEARSCREEN;
		for(int i=0; i<15;i++,putchar('\n'))
			for(int j=0; j<15; j++) {
				if(i== Position.x && j== Position.y) {
					printf(CB_Color_Select);
					continue;
				}
				switch(CB[i][j]) {
					case 0:printf(CB_Color_Space);break;
					case 1:printf(CB_Color_First);break;
					case 2:printf(CB_Color_Second);break;
					default :
						CLEARSCREEN;
						puts("DATA ERROR! Plear Check CB DATA");
				}
			}
		puts(MSG);
	};

	int GameControl(int x,int y) { // -1 bad input
		if(x<0||x>14||y<0||y>14||CB[x][y]!=0) {
			MSG = "Bad Input";
			return 0;
		}
		GameView();	//Refresh GameView
		CP = !CP;	//Chess Player Change
		if(CP)MSG="First";
		else MSG="Second";
	};

	int Operation() {
		switch(Keying) {
			case Operation_UP		:if(Position.y+1<15)Position.y++;break;
			case Operation_Down	:if(Position.y-1>=0)Position.y--;break;
			case Operation_Left	:if(Position.x+1<15)Position.x++;break;
			case Operation_Right:if(Position.x-1>=0)Position.x--;break;
			case Operation_Enter:GameControl(Position.x,Position.y);break;
			default:
				MSG="Bad Input";
		}
	}
	int PlayByYourself(){
		for(int i=0;i<15;i++,putchar('\n'))
		for(int j=0;j<15;j++)
		printf("%d",CB[i][j]);
		
		GameView();
		while(1){
			Operation();
		}
	}
	int AI() {


	};
	int Online(){





			return 0; 
		}
	int init(){
		
		memset(CB,0,sizeof(sizeof(CB)));
		MenuView();
	};
		
};

int main(){
	struct Gobang game;
	game.init();
	
}

