#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


enum state{GAME,MENU,SETTING,GAMEOVER,INFO,OUT_GAME} state;       //enum chua cac hang co dinh trong chuong trinh
int ran[1000],dk=0;                                                 //ran -> bien dieu kien, dk bien dieu kien
int vx=1,vy=0;                                                      //vx,vy bien van toc, huong di ngang trai sang phai
int dai;
int getX(int a){
	return (a-10000)/100;
}
int getY(int a){
	return a%100;
}
void hamran(){                                              //khoi tao ham ran toa do (8,10)
	dai=12;
	ran[0]=10810;
	ran[1]=10811;
	ran[2]=10812;
	ran[3]=10813;
	ran[4]=10814;
	ran[5]=10815;
	ran[6]=10816;
	ran[7]=10817;
	ran[8]=10818;
	ran[9]=10819;
	ran[10]=10820;
	ran[11]=10821;
}
void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}
void box(){                                                            //tao ham box -> khung hoat dong
		int i=0,j=0;
        	for(i;i<80;i++)
			{
				if(i==0) 
				{
					printf("%c", 201);
				}	else if(i==79)
					{
						printf("%c", 187);
					} else printf("%c", 205);
			}
        	for(j;j<25;j++){
        		printf("\n");
        		for(i=0;i<41;i++){
					if(i==0 || i==40)
					{
						printf("%c", 186);
					} else printf("  ");
				}
			}
			printf("\n");
			for(i=0;i<80;i++)
			{
				if(i==0) 
				{
					printf("%c", 200);
				}	else if(i==79)
					{
						printf("%c", 188);
					} else printf("%c", 205);
			}
}        
		void menu(){                                   
        	printf("menu");
		}
        void setting(){
        	printf("setting");
		}
        void gameover(){
        	system("cls");
        	printf("GAME-OVER");
			
		}
        void info(){
        	printf("info");
		}
        void out(){
        	printf("out");
		}
        void game(){
        	printf("score: \n\n");
            box();
            hamran();
            int key=0;
            gotoxy(getX(ran[0]),getY(ran[0]));
            while(state==GAME){                //vong lap vo han cho toi 1 dk nao do o man game
            	if(kbhit()){                   //ham kbhit() xuat nhap 1 phim tu ban phim tra ve gia tri 1/0
            		key=getch();
            		switch(key){
            			case 72:
            				if(vx!=0){
            				vy=-1;
            				vx=0;
							break;
            			}
            			
            			case 80:
            				if(vx!=0){
            				vy=1;
            				vx=0;
							break;
            			}
            			
            			case 75:
            				if(vy!=0){
            				vy=0;
            				vx=-1;
							break;
            			}
            			
            			case 77:
            				if(vy!=0){
            				vy=0;
            				vx=1;
							break;
            			}
            			
					}
				}
				if(dk%5000==0){                     //dieu kien de van toc ban dau tuy thuoc vao so dc chia
				gotoxy(getX(ran[dai-1]),getY(ran[dai-1]));
				printf(" ");
				int i=dai-1;
				for(i;i>0;i--){
					ran[i]=ran[i-1];
				}
				ran[0] += vy;
				ran[0] += vx*100;
				if(getY(ran[0])==2) ran[0]+=25;
				if(getY(ran[0])==28) ran[0]-=25;
				if(getX(ran[0])==0) ran[0]+=77*100;
				if(getX(ran[0])==78) ran[0]-=77*100;
				gotoxy(getX(ran[0]),getY(ran[0]));
				printf("%c", 254);
				for(i=1;i<dai;i++){
					if(ran[0]==ran[i])                          //dieu kien dam vao than la chet
					{
					state = GAMEOVER;
					gameover();
					}
				}
			}
			dk++;
			}
        	state=7;
		}                                             //
int main(){
	while(1){
		switch(state){
			case MENU:
				menu();
				break;
			case SETTING:
				setting();
				break;
			case INFO:
				info();
				break;
			case OUT_GAME:
				out();
				break;
			case GAME:
				game();
				break;
			case GAMEOVER:
				gameover();
				break;
		}
	}
	return 0;
}

