#ifndef CANVAS_H_
#define CANVAS_H_
#include"util.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include"Frame.h"
#include"Candy.h"
class Canvas
{
	public:
		ifstream ssn2;
		int display=0;
		int x1=350;
		int tscore=0,tscore1=0,tscore2=0,tscore3=0,tscore4=0;
		int moves1=20,moves2=20,moves3=20,moves4=20;
		int lives1=3,lives2=3,lives3=3,lives4=3;
		int hscore1[4],hscore2[4],hscore3[4];
		int hhx,hhy,h1,h2,h3,h4,hintcount1=5,hintcount2=5,hintcount3=5,hintcount4=5;
		string name;
		Frame san1;
		Candy san2;
		int get_display()
		{
			return display;
		}
		void set_totalscore1(int totalscore)
		{
			this->tscore1=totalscore;
		}
		int get_totalscore1()
		{
			return tscore1;
		}
		void set_totalscore2(int totalscore)
		{
			this->tscore2=totalscore;
		}
		int get_totalscore2()
		{
			return tscore2;
		}
		void set_totalscore3(int totalscore)
		{
			this->tscore3=totalscore;
		}
		int get_totalscore3()
		{
			return tscore3;
		}
		void set_totalscore4(int totalscore)
		{
			this->tscore4=totalscore;
		}
		int get_totalscore4()
		{
			return tscore4;
		}
		void set_totalscore(int totalscore)
		{
			this->tscore=totalscore;
		}
		int get_totalscore()
		{
			return tscore;
		}
		void set_moves1(int moves)
		{
			this->moves1=moves;
		}
		int get_moves1()
		{
			return moves1;
		}
		void set_moves2(int moves)
		{
			this->moves2=moves;
		}
		int get_moves2()
		{
			return moves2;
		}
		void set_moves3(int moves)
		{
			this->moves3=moves;
		}
		int get_moves3()
		{
			return moves3;
		}
		void set_moves4(int moves)
		{
			this->moves4=moves;
		}
		int get_moves4()
		{
			return moves4;
		}
		void set_hhx(int x)
		{
			this->hhx=x;
		}
		int get_hhx()
		{
			return hhx;
		}
		void set_hhy(int y)
		{
			this->hhy=y;
		}
		int get_hhy()
		{	
			return hhy;
		}
		void set_h1(int x)
		{
			this->h1=x;
		}
		int get_h1()
		{
			return h1;
		}
		void set_h2(int x)
		{
			this->h2=x;
		}
		int get_h2()
		{
			return h2;
		}
		void set_h3(int x)
		{
			this->h3=x;
		}
		int get_h3()
		{
			return h3;
		}
		void set_h4(int x)
		{
			this->h4=x;
		}
		int get_h4()
		{
			return h4;
		}
		void SetCanvasSize(int width, int height) 
        {
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0,width,0,height,-1,1); // set the screen size to given width and height.
            glMatrixMode (GL_MODELVIEW);
            glLoadIdentity();
        }
		void GameDisplay()
		{
			glClearColor(0,0,0,0);
			glClear (GL_COLOR_BUFFER_BIT); //Update the colors
			
			if(display==0)//MENU
			{
				for(int x=50;x<240;x=x+140)
				{
					for(int y=1770;y>-200;y=y-150)
					{
						DrawCandy(x,y,50,100,colors[san2.rand_color_generator()],70);
					}
				}
				for(int x=750;x<1000;x=x+140)
				{
					for(int y=1770;y>-200;y=y-150)
					{
						DrawCandy(x,y,50,100,colors[san2.rand_color_generator()],70);
					}
				}
				DrawRectangle(420,1085,200,50,colors[san2.rand_color_generator()]);
				DrawRectangle(420,985,200,50,colors[san2.rand_color_generator()]);
				DrawRectangle(420,885,200,50,colors[san2.rand_color_generator()]);
				DrawRectangle(420,785,200,50,colors[san2.rand_color_generator()]);
				DrawRectangle(420,685,200,50,colors[san2.rand_color_generator()]);
				DrawString(430,1100,"START GAME",colors[138]);
				DrawString(430,1000,"LEVELS",colors[138]);
				DrawString(430,900,"HIGH SCORES", colors[138]);
				DrawString(430,800,"SETTINGS", colors[138]);
				DrawString(430,700,"EXIT", colors[138]);
				DrawString(280,20,"CREATED BY: SYED ABDULLAH NASIR", colors[san2.rand_color_generator()]);
			}
			else if(display==1)//NAME INPUT NORMAL MODE
			{
				DrawString(380,1100,"ENTER YOUR'E NAME : ",colors[san2.rand_color_generator()]);
				DrawLine(360,1050,660,1050,10,colors[san2.rand_color_generator()]);
				DrawLine(360,1000,660,1000,10,colors[san2.rand_color_generator()]);
				DrawLine(360,1055,360,995,10,colors[san2.rand_color_generator()]);
				DrawLine(660,1055,660,995,10,colors[san2.rand_color_generator()]);
				DrawString(380,1015,name,colors[san2.rand_color_generator()]);
				DrawRectangle(440,890,150,50,colors[san2.rand_color_generator()]);
				DrawString(450,900,"CONTINUE",colors[138]);
			}
			else if(display==16)//NAME INPUT TIME ATTACK MODE
			{
				DrawString(380,1100,"ENTER YOUR'E NAME : ",colors[san2.rand_color_generator()]);
				DrawLine(360,1050,660,1050,10,colors[san2.rand_color_generator()]);
				DrawLine(360,1000,660,1000,10,colors[san2.rand_color_generator()]);
				DrawLine(360,1055,360,995,10,colors[san2.rand_color_generator()]);
				DrawLine(660,1055,660,995,10,colors[san2.rand_color_generator()]);
				DrawString(380,1015,name,colors[san2.rand_color_generator()]);
				DrawRectangle(440,890,150,50,colors[san2.rand_color_generator()]);
				DrawString(450,900,"CONTINUE",colors[138]);
			}
			else if(display==5)//SETTINGS -> HELP
			{
				DrawString(0,1820,"GUIDE:", colors[WHITE]);
				DrawString(0,1780,"1.In this game, you will be dealing with gems of different colors.", colors[WHITE]);
				DrawString(480,1620,"GEMS", colors[WHITE]);
				DrawCandy(490,1650,50,100,colors[san2.rand_color_generator()],70);
				DrawString(0,1580,"2. You will be using the mouse to click on any one of the candies and then you will keep the mouse", colors[WHITE]);
				DrawString(0,1550,"    clicked while you drag the mouse and release it on the candy you want to swap it with. Keep in",colors[WHITE]);
				DrawString(0,1520,"    mind that you can only swap adjacent candies meaning that you can only swap a candy with the ",colors[WHITE]);
				DrawString(0,1490,"    one immediately above it, immediately below it or immediately beside it on both the right and the left",colors[WHITE]);
				DrawString(0,1460,"    hand sides.",colors[WHITE]);
				DrawString(0,1420,"3. Now, your goal in this game is to swap candies so that they make a pattern of 3 or more similar", colors[WHITE]);
				DrawString(0,1390,"    color candies. Then the progress bar at the top of the screen will begin to increase untill it", colors[WHITE]);
				DrawString(0,1360,"    reaches a spcified lenght which indicates that you have acheived the score needed to pass", colors[WHITE]);
				DrawString(0,1330,"    the current level. As you move higher up the levels, the progress bar will start to move ", colors[WHITE]);
				DrawString(0,1300,"    more slowly meaning that the levels become more harder and harder as you move on.", colors[WHITE]);
				DrawString(0,1260,"4. In the menu, if you press 'NEW GAME', you start playing the 'NORMAL MODE' of the game.", colors[WHITE]);
				DrawString(0,1230,"    But, the game also has a 'TIME ATTACK MODE' but you can only use it to play a specific", colors[WHITE]);
				DrawString(0,1200,"    level. In the 'TIME ATTACK MODE', there will be a clock at the top of the screen telling", colors[WHITE]);
				DrawString(0,1170,"    you about how much time is left before you lose the so be quick in scoring points.", colors[WHITE]);
				DrawString(0,1130,"5. There will be a button at the bottom of each level to pause the game and one to acquire a", colors[WHITE]);
				DrawString(0,1100,"    hint from the computer about a possible pattern.", colors[WHITE]);
				DrawString(0,1060,"6. There is also an option in the menu to show High Scores of the player that have played the game.", colors[WHITE]);
				DrawString(0,1030,"    High scores are based on how the player performs in the 'TIME ATTACK MODE' at a particular ", colors[WHITE]);
				DrawString(0,1000,"    level.", colors[WHITE]);
				DrawString(300,800,"PRESS 'M' to go back to the menu.",colors[WHITE]);
			}
			else if(display==6)//LEVELS MENU
			{
				DrawRectangle(420,985,200,50,colors[san2.rand_color_generator()]);
				DrawRectangle(420,885,270,50,colors[san2.rand_color_generator()]);
				DrawString(370,1100,"GAME MODES:",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"NORMAL MODE",colors[138]);
				DrawString(430,900,"TIME ATTACK MODE", colors[138]);
			}
			else if(display==7)//PAUSE LEVEL1
			{
				DrawRectangle(420,985,120,50,colors[san2.rand_color_generator()]);
				DrawRectangle(370,885,220,50,colors[san2.rand_color_generator()]);
				DrawString(350,1100,"THE GAME IS PAUSED !!!",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"RESUME",colors[138]);
				DrawString(380,900,"EXIT THE GAME",colors[138]);
			}
			else if(display==13)//PAUSE LEVEL2
			{
				DrawRectangle(420,985,120,50,colors[san2.rand_color_generator()]);
				DrawRectangle(370,885,220,50,colors[san2.rand_color_generator()]);
				DrawString(350,1100,"THE GAME IS PAUSED !!!",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"RESUME",colors[138]);
				DrawString(380,900,"EXIT THE GAME",colors[138]);
			}
			else if(display==14)//PAUSE LEVEL3
			{
				DrawRectangle(420,985,120,50,colors[san2.rand_color_generator()]);
				DrawRectangle(370,885,220,50,colors[san2.rand_color_generator()]);
				DrawString(350,1100,"THE GAME IS PAUSED !!!",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"RESUME",colors[138]);
				DrawString(380,900,"EXIT THE GAME",colors[138]);
			}
			else if(display==15)//PAUSE LEVEL4
			{
				DrawRectangle(420,985,120,50,colors[san2.rand_color_generator()]);
				DrawRectangle(370,885,220,50,colors[san2.rand_color_generator()]);
				DrawString(350,1100,"THE GAME IS PAUSED !!!",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"RESUME",colors[138]);
				DrawString(380,900,"EXIT THE GAME",colors[138]);
			}
			else if(display==9)//SETTINGS
			{
				DrawRectangle(420,985,200,50,colors[san2.rand_color_generator()]);
				DrawString(370,1100,"SETTINGS:",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"HELP",colors[138]);
			}
			else if(display==4)//HIGH SCORES NORMAL MODE
			{
				DrawString(20,1780,"HIGH SCORES:",colors[san2.rand_color_generator()]);
				ssn2.open("HighScoresNormalMode.txt");
				int line_no=1,l1,l2,l3;
				int score[50];
				string name,convert,hscore1,hscore2,hscore3;
				for(int i=0;i<50;i++)
				{
					score[i]=0;
				}
				getline(ssn2,convert);
				int i=0;
				while(!ssn2.eof())
				{
					getline(ssn2,convert);
					score[i]=score[i]+stoi(convert);
					getline(ssn2,convert);
					i=i+1;
				}
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				for(int i=0;i<50-1;i++) 
				{
					int min=i;
					for (int j=i+1;j<50;j++) 
					{
						if(score[j]>score[min])
						{
							min=j;
						}
					}
					int temp=score[min];
					score[min]=score[i];
					score[i]=temp;
				}
				hscore1=to_string(score[0]);
				hscore2=to_string(score[1]);
				hscore3=to_string(score[2]);
				int j=220,k=1680;
				while(!ssn2.eof())
				{
					getline(ssn2,name);
					if(name==hscore1)
					{
						DrawString(j,k,name,colors[san2.rand_color_generator()]);
						l1=line_no;
						break;
					}
					line_no++;
				}
				line_no=1;
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				k=k-50;
				while(!ssn2.eof())
				{
					getline(ssn2,name);
					if(name==hscore2)
					{
						DrawString(j,k,name,colors[san2.rand_color_generator()]);
						l2=line_no;
						break;
					}
					line_no++;
				}
				line_no=1;
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				k=k-50;
				while(!ssn2.eof())
				{
					getline(ssn2,name);
					if(name==hscore3)
					{
						DrawString(j,k,name,colors[san2.rand_color_generator()]);
						l3=line_no;
						break;
					}
					line_no++;
				}
				//cout<<l1<<l2<<l3<<endl;
				k=1680;
				line_no=1;
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				while(!ssn2.eof())
				{
					getline(ssn2,name);
					if(line_no==l1-1)
					{
						DrawString(20,k,name,colors[san2.rand_color_generator()]);
					}
					line_no++;
				}
				line_no=1;
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				k=k-50;
				while(!ssn2.eof())
				{
					getline(ssn2,name);
					if(line_no==l2-1)
					{
						DrawString(20,k,name,colors[san2.rand_color_generator()]);
					}
					line_no++;
				}
				line_no=1;
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				k=k-50;
				while(!ssn2.eof())
				{
					getline(ssn2,name);
					if(line_no==l3-1)
					{
						DrawString(20,k,name,colors[san2.rand_color_generator()]);
					}
					line_no++;
				}
				ssn2.clear();
				ssn2.seekg(ssn2.beg);
				ssn2.close();
				DrawString(50,100,"PRESS 'M' to go to the menu.",colors[san2.rand_color_generator()]);
			}
			else if(display==2)//LEVEL 1 NORMAL MODE
			{
				static int once1=0;
				if(once1==0)
				{
					san2.set_candy_coordinates();
				}
				once1=1;
				DrawString(450,1820,"LEVEL 1",colors[san2.rand_color_generator()]);
				DrawRectangle(10,1765,150,50,colors[san2.rand_color_generator()]);
				DrawRectangle(790,1765,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,1780,"PROGRESS:",colors[138]);
				if(san2.get_score1()<500)
				{
					DrawLine(200.0,1810.0,200.0+(san2.get_score1()*1.125),1810.0,10.0,colors[37]);
					DrawString(800,1780,"SCORE: "+Num2Str(san2.get_score1())+"/500",colors[138]);
				}
				else if(san2.get_score1()==500 || san2.get_score1()>500)
				{
					DrawLine(200,1810,200+(580),1810,10,colors[37]);
					DrawString(800,1780,"SCORE: "+Num2Str(600)+" /500",colors[138]);	
					DrawString(420,520,"EXCELLENT !!!",colors[san2.rand_color_generator()]);
					DrawString(400,420,"LEVEL COMPLETE !!!",colors[san2.rand_color_generator()]);
				}
				DrawCircle(500,100,70,colors[san2.rand_color_generator()]);
				DrawLine(480,50,480,150,10,colors[138]);
				DrawLine(520,50,520,150,10,colors[138]);
				DrawSquare(895,500,90,colors[san2.rand_color_generator()]);
				DrawString(900,550,"H I N T",colors[138]);
				DrawRectangle(10,525,250,50,colors[san2.rand_color_generator()]);
				DrawRectangle(10,425,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,540,"MOVES:"+Num2Str(san2.get_move1()),colors[138]);
				DrawString(20,440,"LIVES:"+Num2Str(san2.get_live1()),colors[138]);
				tscore1=san2.get_score1();
				set_totalscore1(tscore1);
				san1.draw_frame();
				san2.draw_candies();
				if(hintcount1>=0)
				{
					san2.draw_hint();
				}
				DrawString(920,520,Num2Str(hintcount1)+" / "+Num2Str(5),colors[138]);
			}
			else if(display==8)//LEVEL 2 NORMAL MODE
			{
				static int once2=0;
				if(once2==0)
				{
					san2.set_candy_coordinates();
				}
				once2=1;
				DrawString(450,1820,"LEVEL 2",colors[san2.rand_color_generator()]);
				DrawLine(200,1810,200+(580),1810,10,colors[37]);
				DrawRectangle(10,1765,150,50,colors[san2.rand_color_generator()]);
				DrawRectangle(790,1765,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,1780,"PROGRESS:",colors[138]);
				if(san2.get_score2()<1000)
				{
					DrawLine(200.0,1800.0,200.0+(san2.get_score2()*0.5625),1800.0,10.0,colors[68]);
					DrawString(800,1780,"SCORE: "+Num2Str(san2.get_score2())+" /1000",colors[138]);
				}
				else if(san2.get_score2()>1000 || san2.get_score2()==1000)
				{
					DrawLine(200,1800,200+(580),1800,10,colors[68]);
					DrawString(800,1780,"SCORE: "+Num2Str(600)+" /1000",colors[138]);	
				}
				DrawCircle(500,100,70,colors[san2.rand_color_generator()]);
				DrawLine(480,50,480,150,10,colors[138]);
				DrawLine(520,50,520,150,10,colors[138]);
				DrawSquare(895,500,90,colors[san2.rand_color_generator()]);
				DrawString(900,550,"H I N T",colors[138]);
				DrawRectangle(10,525,250,50,colors[san2.rand_color_generator()]);
				DrawRectangle(10,425,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,540,"MOVES:"+Num2Str(san2.get_move2()),colors[138]);
				DrawString(20,440,"LIVES:"+Num2Str(san2.get_live2()),colors[138]);
				tscore2=san2.get_score1()+san2.get_score2();
				set_totalscore2(tscore2);
				san1.draw_frame();
				san2.draw_candies();
				if(hintcount2>=0)
				{
					san2.draw_hint();
				}
				DrawString(920,520,Num2Str(hintcount2)+" / "+Num2Str(5),colors[138]);
			}
			else if(display==10)//LEVEL 3 NORMAL MODE
			{
				static int once3=0;
				if(once3==0)
				{
					san2.set_candy_coordinates();
				}
				once3=1;
				DrawString(450,1820,"LEVEL 3",colors[san2.rand_color_generator()]);
				DrawLine(200,1810,200+(580),1810,10,colors[37]);
				DrawLine(200,1800,200+(580),1800,10,colors[68]);
				DrawRectangle(10,1765,150,50,colors[san2.rand_color_generator()]);
				DrawRectangle(790,1765,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,1780,"PROGRESS:",colors[138]);
				if(san2.get_score3()<1500)
				{
					DrawLine(200.0,1790.0,200.0+(san2.get_score3()*0.39),1790.0,10.0,colors[103]);
					DrawString(800,1780,"SCORE: "+Num2Str(san2.get_score3())+" /1500",colors[138]);
				}
				else if(san2.get_score3()>1500 || san2.get_score3()==1500)
				{
					DrawLine(200,1790,200+(580),1790,10,colors[103]);
					DrawString(800,1780,"SCORE: "+Num2Str(600)+" /1500",colors[138]);	
				}
				DrawCircle(500,100,70,colors[san2.rand_color_generator()]);
				DrawLine(480,50,480,150,10,colors[138]);
				DrawLine(520,50,520,150,10,colors[138]);
				DrawSquare(895,500,90,colors[san2.rand_color_generator()]);
				DrawString(900,550,"H I N T",colors[138]);
				DrawRectangle(10,525,250,50,colors[san2.rand_color_generator()]);
				DrawRectangle(10,425,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,540,"MOVES:"+Num2Str(san2.get_move3()),colors[138]);
				DrawString(20,440,"LIVES:"+Num2Str(san2.get_live3()),colors[138]);
				tscore3=san2.get_score1()+san2.get_score2()+san2.get_score3();
				set_totalscore3(tscore3);
				san1.draw_frame();
				san2.draw_candies();
				if(hintcount3>=0)
				{
					san2.draw_hint();
				}
				DrawString(920,520,Num2Str(hintcount3)+" / "+Num2Str(5),colors[138]);
			}
			else if(display==11)//LEVEL 4 NORMAL MODE
			{
				static int once4=0;
				if(once4==0)
				{
					san2.set_candy_coordinates();
				}
				once4=1;
				DrawString(450,1820,"LEVEL 4",colors[san2.rand_color_generator()]);
				DrawLine(200,1810,200+(580),1810,10,colors[37]);
				DrawLine(200,1800,200+(580),1800,10,colors[68]);
				DrawLine(200,1790,200+(580),1790,10,colors[103]);
				DrawRectangle(10,1765,150,50,colors[san2.rand_color_generator()]);
				DrawRectangle(790,1765,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,1780,"PROGRESS:",colors[138]);
				if(san2.get_score4()<2000)
				{
					DrawLine(200.0,1780.0,200.0+(san2.get_score4()*0.28125),1780.0,10.0,colors[75]);
					DrawString(800,1780,"SCORE: "+Num2Str(san2.get_score4())+" /2000",colors[138]);
				}
				else if(san2.get_score4()>2000 || san2.get_score4()==2000)
				{
					DrawLine(200,1780,200+(580),1780,10,colors[75]);
					DrawString(800,1780,"SCORE: "+Num2Str(600)+" /2000",colors[138]);	
				}
				DrawCircle(500,100,70,colors[san2.rand_color_generator()]);
				DrawLine(480,50,480,150,10,colors[138]);
				DrawLine(520,50,520,150,10,colors[138]);
				DrawSquare(895,500,90,colors[san2.rand_color_generator()]);
				DrawString(900,550,"H I N T",colors[138]);
				DrawRectangle(10,525,250,50,colors[san2.rand_color_generator()]);
				DrawRectangle(10,425,250,50,colors[san2.rand_color_generator()]);
				DrawString(20,540,"MOVES:"+Num2Str(san2.get_move4()),colors[138]);
				DrawString(20,440,"LIVES:"+Num2Str(san2.get_live4()),colors[138]);
				tscore4=san2.get_score1()+san2.get_score2()+san2.get_score3()+san2.get_score4();
				set_totalscore4(tscore4);
				san1.draw_frame();
				san2.draw_candies();
				if(hintcount4>=0)
				{
					san2.draw_hint();	
				}
				DrawString(920,520,Num2Str(hintcount4)+" / "+Num2Str(5),colors[138]);
			}
			else if(display==12)//FINAL SCREEN 
			{
				tscore=san2.get_score1()+san2.get_score2()+san2.get_score3()+san2.get_score4();
				set_totalscore(tscore);
				DrawString(430,1100,"CONGARTULATIONS !!!",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"YOU HAVE WON THE GAME",colors[san2.rand_color_generator()]);
				DrawString(430,900,"PRESS 'ESC' to escape to exit game.",colors[san2.rand_color_generator()]);
			}
			else if(display==100)
			{
				DrawString(430,1100,"GAME OVER !!!",colors[san2.rand_color_generator()]);
				DrawString(430,1000,"YOU HAVE LOST THE GAME",colors[san2.rand_color_generator()]);
			}
			glutSwapBuffers();
		}
};
#endif