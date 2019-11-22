#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <ctype.h> 
enum state{GAME,MENU,SETTING,GAMEOVER,INFO,OUT_GAME} state;       //enum chua cac hang co dinh trong chuong trinh
int ran[1000],moi=12006,dk=0;                                       //ran,moi -> bien dieu kien, dk bien dieu kien
int vx=1,vy=0;                                                      //vx,vy bien van toc, huong di ngang trai sang phai
int dai,score=0;
char c;
int random(int a, int b){
	return a+rand()%(b-a+1);
}
void indiem(){
	
	gotoxy(6,01);
	printf("%d",score);
}
void randommoi(){
	int kt=0,i;                                                       //kt -> bien kiem tra moi trung vs ran hay ko
	for(;;){
	moi=10000+random(6,75)*100;                                   //ham random moi gioi han x tu vi tri 6-75
    moi+=random(4,22);                                            //ham random moi gioi han y tu vi tri 2-22
	for(i=0;i<dai;i++){
	   if (moi==ran[i]) kt++;
    }
	if (kt==0) break;
    }
}
int getX(int a){
	return (a-10000)/100;
}
int getY(int a){
	return a%100;
}
void hamran(){                                              //khoi tao ham ran toa do (8,10)
	dai=3;
	ran[0]=10810;
	ran[1]=10811;
	ran[2]=10812;
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
			printf("\n");
			
}        
		void menu(){                                   
        	printf("menu");
		}
        void setting(){
        	printf("setting");
		}
        void gameover(){
        	system("cls");
			printf("score: %d\n\n", score);
        	printf("GAME OVER");
			printf("\nDO YOU WANT TO CONTINUE? (Y/N): ");
			scanf("%c", &c);
			c=toupper(c);
			switch(c)
			{
				case 'Y':
				{		
						score=0;
						system("cls");
						again();
						break;
				}
				case 'N':
				{
						out();
						 break;
				}
				default: gameover();
			}

		}
		void again()
		{
			state=GAME;{
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
		}
        void info(){
        	printf("info");
		}
        void out(){
			
        	system("cls");
        	printf("Exit");
			for(;;)
    		{
        		printf("\n\nPress any key to exit!!.\n");
        		fflush(stdin);
				scanf("%c", &c);
				exit(1);
				
   			}
		}		
		
        void game(){	
        	printf("\t\t\tGAME RAN SAN MOI");
			printf("\nScore:");
			indiem();
			printf("\n");
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
            			}
            			break;
            			case 80:
            				if(vx!=0){
            				vy=1;
            				vx=0;
            			}
            			break;
            			case 75:
            				if(vy!=0){
            				vy=0;
            				vx=-1;
            			}
            			break;
            			case 77:
            				if(vy!=0){
            				vy=0;
            				vx=1;
            			}
            			break;
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
			    	printf("o");
				gotoxy(getX(moi),getY(moi));
			    	printf("%c", 232);
				if(ran[0]==moi){
				    gotoxy(getX(moi),getY(moi));                       //dieu kien an moi
				    printf("o");
				    dai++;
					score+=5;
				    randommoi();
					indiem();
					
			}
				for(i=1;i<dai;i++){
					if(ran[0]==ran[i]){                          //dieu kien dam vao than la chet
					state = GAMEOVER;
					gameover();
					
					}
				}
			}
			dk++;
			}
        	state=7;
		}                                             
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
