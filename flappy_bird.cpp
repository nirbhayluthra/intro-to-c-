//https://www.youtube.com/watch?v=yASrfF1C3ms


#include<iostream>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>


#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 70
#define  GAP_SIZE 7
#define PIPE_DIF 45

using namespace std;
//cout<<"+_+_+_+_+_+_+";

HANDLE console= GetStdHandle(STD_OUTPUT_HANDLE);

COORD CursorPosition;

int pipepos[3];
int gappos[3];
int pipeflag[3];
char bird[2][6]={'/','-','-','o','\\',' ',
                 '|','_','_','_',' ','>'};

int birdpos=6;
int score=0;

void gotoxy(int x,int y)
{
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(console,CursorPosition);
}

void setcursor(bool visible,DWORD size)
{
	if(size==0)
	{
		size=20;
	}
	
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible=visible;
	lpCursor.dwSize=size;
	
	SetConsoleCursorInfo(console,&lpCursor);
}


void drawborder()
{
	for(int i=0;i<SCREEN_WIDTH;i++)
	{
		gotoxy(i,0);
		cout<<"+-";
		gotoxy(i,SCREEN_HEIGHT);
		cout<<"+-";
	}
	for(int i=0;i<SCREEN_HEIGHT;i++)
	{
		gotoxy(0,i);
		cout<<"+-";
		gotoxy(SCREEN_WIDTH,i);
		cout<<"+-";
	}
	
	for(int i=0;i<SCREEN_HEIGHT;i++)
	{
		gotoxy(WIN_WIDTH,i);
		cout<<"+-";
	}
	

	
}


	void genpipe(int ind)
	{
		gappos[ind]=3+rand()%14;
		
  }


void drawpipe(int ind)
{
	if(pipeflag[ind]==true)
	{
		for(int i=0;i<gappos[ind];i++)
		{
			gotoxy(WIN_WIDTH-pipepos[ind],i+1);
			cout<<"***";
		}
		
			for(int i=gappos[ind]+GAP_SIZE;i<SCREEN_HEIGHT-1;i++)
		{
			gotoxy(WIN_WIDTH-pipepos[ind],i+1);
			cout<<"***";
		}
		
	}
}

void erasepipe(int ind)
{
	if(pipeflag[ind]==true)
	{
			for(int i=0;i<gappos[ind];i++)
		{
			gotoxy(WIN_WIDTH-pipepos[ind],i+1);
			cout<<"   ";
		}
	}
	for(int i=gappos[ind]+GAP_SIZE;i<SCREEN_HEIGHT-1;i++)
		{
			gotoxy(WIN_WIDTH-pipepos[ind],i+1);
			cout<<"   ";
		}
}		


void drawbird()
		{
			
			
			for(int i=0;i<2;i++)
			{
			for(int j=0;j<6;j++)
			{
				gotoxy(j+2,i+birdpos);
				
				cout<<bird[i][j];
				}	
			}
		}
		
		
			
void erasebird()
{
					
			for(int i=0;i<2;i++)
			{
			for(int j=0;j<6;j++)
			{
				gotoxy(j+2,i+birdpos);
				
				cout<<" ";
				}	
			}
}


int collision()
{
	if(pipepos[0]>=61)
	{
		if(birdpos<gappos[0] || birdpos>gappos[0]+GAP_SIZE)
		{
			//cout<<"HIT";
			//getch();
			return 1;
		}
	}
	
	
	return 0;
}	
		
		
		void debug()
		{
			//gotoxy(SCREEN_WIDTH+3,4);
			//cout<<"Pipe Pos: "<<pipepos[0];
		}
		
		
		void gameover()
		{
			system("cls");
			cout<<endl;
			cout<<"\t\t-----------------------"<<endl;
			cout<<"\t\t--------GAME OVER------"<<endl;
		   cout<<"\t\t-----------------------"<<endl<<endl;
		   	cout<<"\t\t Press any key to go back to menu "<<endl;
		   	getch();
			
			
		}
		
		void updatescore()
		{
			gotoxy(WIN_WIDTH+7,5);
			cout<<"SCORE: "<<score<<endl;
		}
			
			
	
	   void instructions()
	   {
	   	system("cls");
	   	cout<<"Instructions";
	   	cout<<"\n-----------------------";
	   	cout<<"\n Press Space Bar to make Bird Fly";
	   	cout<<"\n\n Press any key to go back to menu";
	   	getch();
	   	
	   }
		
		void play()
		{
			birdpos=6;
			score=0;
			pipeflag[0]=1;
			pipeflag[1]=0;
			pipepos[0]=pipepos[1]=4;
			
			system("cls");
			drawborder();
			genpipe(0);
			updatescore();
			
			gotoxy(WIN_WIDTH+5,2);
			cout<<"FLAPPY BIRDS";
			
			gotoxy(WIN_WIDTH+6,4);
			cout<<"------------";
			
			gotoxy(WIN_WIDTH+6,6);
			cout<<"------------";
			
			gotoxy(WIN_WIDTH+7,12);
			cout<<"CONTROL";
			
		
			gotoxy(WIN_WIDTH+7,13);
			cout<<"-------------";
			
			gotoxy(WIN_WIDTH+2,14);
			cout<<"SPACEBAR = Jump";
			
			
			gotoxy(10,5);
			
			cout<<"Press any key to start";
			getch();
			
			gotoxy(10,5);
			cout<<"                      ";
			
			while(1)
			{
				if(kbhit())
				{
					char ch=getch();
					if(ch==32)
					{
						if(birdpos>3)
						{
							birdpos-=3;
						}
					}
					
					if(ch==27)
					{
						break;
					}
					
				}
			}
			
			drawbird();
			drawpipe(0);
			drawpipe(1);
			debug();
			
			if(collision()==1)
			{
				gameover();
				return;
			}
			
			Sleep(100);
			erasebird();
			erasepipe(0);
			erasepipe(1);
			birdpos +=1;
			
			if(birdpos>SCREEN_HEIGHT-2)
			{
				gameover();
				return;
			}
			
			if(pipeflag[0]==1)
			{
				pipepos[0]+=2;
			}
			
				if(pipeflag[1]==1)
			{
				pipepos[1]+=2;
			}
			
			
			if(pipepos[0]>=40 && pipepos[0]<42)
			{
				pipeflag[1]=1;
				pipepos[1]=4;
				genpipe(1);
			}
			
			if(pipepos[0]>68)
			{
				score++;
				updatescore();
				pipeflag[1]=0;
				pipepos[0]=pipepos[1];
				gappos[0]=gappos[1];
				
			}
			
			
		
		}
		
		
		int main()
		{
			setcursor(0,0);
			srand((unsigned)time(NULL));
			
			//play();
			
			do{
				system("cls");
				gotoxy(10,5);
				cout<<"------------------------------------------";
				gotoxy(10,6);
				cout<<"|          FLAPPY BIRDS                  |";
				gotoxy(10,7);
				cout<<"------------------------------------------";
				gotoxy(10,9);
				cout<<"1. start game";
				gotoxy(10,10);
				cout<<"2.instructions";
				gotoxy(10,11);
				cout<<"3.quit";
				gotoxy(10,13);
				cout<<"Select Option";
				
				char op=getche();
				
				if(op=='1')
				{
					play();
				}
				
				else if(op=='2')
				{
					instructions();
				}
				
				else if(op=='3')
				{
					exit(0);
				}
				
			}
           while(1);
           
           
           return 0;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
