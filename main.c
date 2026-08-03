#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

#include <dos.h>


void border()
{
	int i;
	for(i=0;i<12;i++)
	{
		if(i<2)
		{
			setcolor(5);
		}
		else if(i<4)
		{
			setcolor(13);
		}
		else if(i<6)
		{
			setcolor(1);
		}
		else if(i<8)
		{
			setcolor(9);
		}
		else if(i<10)
		{
			setcolor(3);
		}
		else
		{
			setcolor(11);
		}

		rectangle(0+i,0+i,639-i,479-i);
	}
}

void l_rock(int a)
{
	setcolor(YELLOW);
	circle(170-a, 50, 50);
	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(170-a, 50, YELLOW);
}

void l_paper(int a)
{
	setfillstyle(1,15);
	bar(120-a,0,220-a,100);
}

void l_scissor(int a)
{
	int i=0,p;
	int pt1[8]={120,0,205,70,194,74,120,0};
	int pt2[8]={220,0,135,70,146,74,220,0};

	for(i=0;i<8;i++)
	{
		pt1[i]=pt1[i]-a;
		pt2[i]=pt2[i]-a;
		i++;
	}
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(4,pt1);
	fillpoly(4,pt2);


	setcolor(BROWN);
	circle(135-a,85,15);
	circle(205-a,85,15);
	for(p=10;p<15;p++)
	{
		circle(135-a,85,p);
		circle(205-a,85,p);
	}
}

void r_rock(int a)
{
	setcolor(YELLOW);
	circle(170+a,50,50);
	setfillstyle(1,DARKGRAY);
	floodfill(170+a,50,YELLOW);
}

void r_paper(int a)
{
	setfillstyle(1,15);
	bar(120+a,0,220+a,100);
}

void r_scissor(int a)
{
	int i=0,p;

	int pt1[8]={120,0,205,70,194,74,120,0};
	int pt2[8]={220,0,135,70,146,74,220,0};

	for(i=0;i<8;i++)
	{
		pt1[i]=pt1[i]+a;
		pt2[i]=pt2[i]+a;
		i++;
	}
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(4,pt1);
	fillpoly(4,pt2);

	setcolor(BROWN);
	circle(135+a,85,15);
	circle(205+a,85,15);
	for(p=10;p<15;p++)
	{
		circle(135+a,85,p);
		circle(205+a,85,p);
	}
}

void displayCh(int a,int b)
{
	settextstyle(0,0,1);
	setcolor(5);

	if(a==0)
	{
		outtextxy(45,70,"YOUR CHOICE : ROCK");
	}
	else if(a==1)
	{
		outtextxy(45,70,"YOUR CHOICE : PAPER");
	}
	else if(a==2)
	{
		outtextxy(45,70,"YOUR CHOICE : SCISSOR");
	}


	if(b==0)
	{
		outtextxy(405,70,"COMPUTER CHOICE : ROCK");
	}
	else if(b==1)
	{
		outtextxy(405,70,"COMPUTER CHOICE : PAPER");
	}
	else if(b==2)
	{
		outtextxy(405,70,"COMPUTER CHOICE : SCISSOR");
	}
}

void clash(int m,int n)
{
	int z;
	displayCh(m,n);
	border();

	for(z=120;z>50;z--)
	{
		setviewport(150,130,490,230,1);
		clearviewport();

		if(m==0)
		{
			l_rock(z);
		}
		else if(m==1)
		{
			l_paper(z);
		}
		else if(m==2)
		{
			l_scissor(z);
		}

		if(n==0)
		{
			r_rock(z);
		}
		else if(n==1)
		{
			r_paper(z);
		}
		else if(n==2)
		{
			r_scissor(z);
		}

		delay(40);
	}
}

void clashResult(int m,int n)
{

	setviewport(150,130,490,230,1);
	clearviewport();

	if((m==0&&n==2)||(m==2&&n==0)||(m==0&&n==0))
	{
		l_rock(0);
	}
	else if((m==1&&n==0)||(m==0&&n==1)||(m==1&&n==1))
	{
		l_paper(0);
	}
	else if((m==2&&n==1)||(m==1&&n==2)||(m==2&&n==2))
	{
		l_scissor(0);
	}

	setviewport(0,0,639,479,1);
	displayCh(m,n);
}

void round(int a)
{
	gotoxy(30,3);
	printf("---- ROUND : %d ----",a);
}
int main()
{
	int gd = DETECT, gm,playerCh,computerCh,a=1;
	char playerChoice;
	int playerScore = 0, computerScore = 0;

	initgraph(&gd, &gm, "C://turboc3//bgi");

	srand(time(NULL));

	printf("\n\n       \t\t*WELCOME TO THE ROCK PAPER SCISSOR GAME*\n");
	printf("\n\t-----------------------------------------------------------------\n\n");
	printf("\n\n\n   RULES OF THE GAME:\n");
	printf("\n\n   - ROCK beats SCISSOR\n");
	printf("\n\n   - SCISSOR beats PAPER\n");
	printf("\n\n   - PAPER beats ROCK\n\n");
	printf("\n\n\t\t\t  ----HERE WE START GAME----\n");


	 do
	 {
		gotoxy(11,28);
		label:
		printf("\n   Choose your move (r for Rock, p for Paper, s for Scissors, q to quit): ");

		border();

		scanf(" %c", &playerChoice);

		clearviewport();

		computerCh=rand() % 3;


		switch (playerChoice)
		{
			case 'q':goto endLoop;

			case 'r':playerCh=0;
				break;
			case 'p':playerCh=1;
				break;
			case 's':playerCh=2;
				    break;

			default:gotoxy(20,25);
				printf("  Invalid choice! Please choose again.\n");
				goto label;
		}

		

		border();
		round(a);
		clash(playerCh,computerCh);

		clashResult(playerCh,computerCh);

		a++;

		if ((playerCh == 0 && computerCh == 2) ||
		(playerCh == 1 && computerCh == 0) ||
		(playerCh == 2 && computerCh ==1))
		{
			gotoxy(35,17);
			printf("*YOU WIN*");;
			playerScore++;
		}
		else if ((playerCh == 0 && computerCh == 1) ||
			(playerCh == 1 && computerCh == 2) ||
			(playerCh == 2 && computerCh == 0))
		{
			gotoxy(35,17);
			printf("*YOU LOSE*");
			computerScore++;
		}
		else if((playerCh == 0 && computerCh == 0)||
			(playerCh == 1 && computerCh == 1)||
			(playerCh == 2 && computerCh == 2))
		{
			gotoxy(31,17);
			printf("*It's a Tie*");
			playerScore++;
			computerScore++;
		}


		gotoxy(20,20);
		printf("Score :");
		gotoxy(20,22);
		printf("Player : %d",playerScore);
		gotoxy(20,23);
		printf("Computer : %d",computerScore);

		gotoxy(20,25);


	} while (1);

	endLoop:

	cleardevice();
	border();

	setcolor(WHITE);
	settextstyle(10,0,3);
	outtextxy(100,100,"---FINAL SCORE---");

	rectangle(170,200,470,300);
	line(170,230,470,230);
	line(320,200,320,300);

	setcolor(RED);
	settextstyle(1,0,2);
	outtextxy(205,205,"PLAYER");
	outtextxy(345,205,"COMPUTER");

	gotoxy(30,17);
	printf("%d",playerScore);
	gotoxy(50,17);
	printf("%d",computerScore);


	gotoxy(15,25);
	printf("Press any key to exit....");

	getch();

	closegraph();
	return 0;
}