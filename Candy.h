#ifndef CANDY_H_
#define CANDY_H_
#include"util.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<thread>
#include<chrono>
class Candy
{
	protected:
		int r;
		int color;
		int code[7][7];
		int x_axis[7][7];
		int y_axis[7][7];
	public:
		float scorefinal1,scorefinal2,scorefinal3,scorefinal4,level=1;
		float score1=0,score2=0,score3=0,score4=0;
		int move1=21,move2=36,move3=53,move4=69;
		int live1=3,live2=3,live3=3,live4=3;
		int hintcase;
		int xh,yh,xh1,xh2,yh1,yh2;
		Candy()
		{
			r=0;
			set_candy_coordinates();
		}
		void set_r()
		{
			r=time(0);
			srand(r);
		}
		void set_x_axis(int i,int j,int x)
		{
			x_axis[i][j]=x;
		}
		int get_x_axis(int i,int j)
		{
			return x_axis[i][j];
		}
		void set_y_axis(int i,int j,int y)
		{
			y_axis[i][j]=y;
		}
		int get_y_axis(int i,int j)
		{
			return y_axis[i][j];
		}
		void set_code(int i,int j,int color)
		{
			code[i][j]=color;
		}
		int get_code(int i,int j)
		{
			return code[i][j];
		}
		void set_score1(float score1)
		{
			this->scorefinal1=score1;
		}
		float get_score1()
		{
			return scorefinal1;
		}
		void set_score2(float score2)
		{
			this->scorefinal2=score2;
		}
		float get_score2()
		{
			return scorefinal2;
		}
		void set_score3(float score3)
		{
			this->scorefinal3=score3;
		}
		float get_score3()
		{
			return scorefinal3;
		}
		void set_score4(float score4)
		{
			this->scorefinal4=score4;
		}
		float get_score4()
		{
			return scorefinal4;
		}
		void set_move1(int moves)
		{
			this->move1=moves;
		}
		int get_move1()
		{
			return move1;
		}
		void set_move2(int moves)
		{
			this->move2=moves;
		}
		int get_move2()
		{
			return move2;
		}
		void set_move3(int moves)
		{
			this->move3=moves;
		}
		int get_move3()
		{
			return move3;
		}
		void set_move4(int moves)
		{
			this->move4=moves;
		}
		int get_move4()
		{
			return move4;
		}
		void set_live1(int lives)
		{
			this->live1=lives;
		}
		int get_live1()
		{
			return live1;
		}
		void set_live2(int lives)
		{
			this->live2=lives;
		}
		int get_live2()
		{
			return live2;
		}
		void set_live3(int lives)
		{
			this->live3=lives;
		}
		int get_live3()
		{
			return live3;
		}
		void set_live4(int lives)
		{
			this->live4=lives;
		}
		int get_live4()
		{
			return live4;
		}
		void set_xh(int x)
		{
			this->xh=x;
		}
		void set_yh(int y)
		{
			this->yh=y;
		}
		int get_xh()
		{
			return xh;
		}
		int get_yh()
		{
			return yh;
		}
		void set_xh1(int x)
		{
			this->xh1=x;
		}
		void set_yh1(int y)
		{
			this->yh1=y;
		}
		int get_xh1()
		{
			return xh1;
		}
		int get_yh1()
		{
			return yh1;
		}
		void set_xh2(int x)
		{
			this->xh2=x;
		}
		void set_yh2(int y)
		{
			this->yh2=y;
		}
		int get_xh2()
		{
			return xh2;
		}
		int get_yh2()
		{
			return yh2;
		}
		void set_candy_coordinates()
		{
			for(int y=1620,i=0;y>700,i<7;y=y-150,i++)
			{
				for(int x=50,j=0;x<995,j<7;x=x+140,j++)
				{
					r=rand()%7;
					if(r==0)
					{
						color=37;//DARK_SEA_GREEN
					}
					if(r==1)
					{
						color=75;//MEDIUM_PURPLE
					}
					if(r==2)
					{
						color=0;//MAROON
					}
					if(r==3)
					{
						color=68;//BLUE
					}
					if(r==4)
					{
						color=103;//CHOCOLATE
					}
					if(r==5)
					{
						color=89;//HOT_PINK
					}
					if(r==6)
					{
						color=73;//SLATE_BLUE
					}
					set_code(i,j,color);
					set_x_axis(i,j,x);
					set_y_axis(i,j,y);
				}
			}
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					if((get_code(i,j)==get_code(i+1,j)) && (get_code(i,j)==get_code(i+2,j)))
					{
						set_code(i+1,j,get_code(i+1,j+1));
					}
					if((get_code(i,j)==get_code(i,j+1)) && (get_code(i,j)==get_code(i,j+2)))
					{
						set_code(i,j+1,get_code(i+1,j+1));
					}
				}
			}
		}
		void draw_candies()
		{
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					DrawCandy(get_x_axis(i,j),get_y_axis(i,j),50,100,colors[get_code(i,j)],70);
				}
			}
		}
		void swap_candies(int x1,int y1,int x2,int y2)
		{
			static int swapx1,swapy1,swapx2,swapy2;
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					if(get_x_axis(i,j)==x1 && get_y_axis(i,j)==y1)
					{
						swapx1=i;
						swapy1=j;
					}
				}
			}
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					if(get_x_axis(i,j)==x2 && get_y_axis(i,j)==y2)
					{
						swapx2=i;
						swapy2=j;
					}
				}
			}
			if(swapx2==swapx1+1 && swapy2==swapy1)
			{
				check_pattern(swapx1,swapy1,swapx2,swapy2);
				refill();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
			}
			if(swapx2==swapx1-1 && swapy2==swapy1)
			{
				check_pattern(swapx1,swapy1,swapx2,swapy2);
				refill();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
			}
			if(swapx2==swapx1 && swapy2==swapy1+1)
			{
				check_pattern(swapx1,swapy1,swapx2,swapy2);
				refill();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
			}
			if(swapx2==swapx1 && swapy2==swapy1-1)
			{
				check_pattern(swapx1,swapy1,swapx2,swapy2);
				refill();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
				for(int i=0;i<7;i++)
				{
					for(int j=0;j<7;j++)
					{
						five_break(i,j);
						if(five_break(i,j)==false)
						{
							four_break(i,j);
							if(four_break(i,j)==false)
							{
								three_break(i,j);
								if(three_break(i,j)==false)
								{
								}
							}
						}
					}
				}
				refill1();
			}
		}
		void check_pattern(int swapx1,int swapy1,int swapx2,int swapy2)
		{
			int tempcolor;
			tempcolor=get_code(swapx1,swapy1);
			set_code(swapx1,swapy1,get_code(swapx2,swapy2));
			set_code(swapx2,swapy2,tempcolor);
			//FOR 5 BREAK->DIAGONALLY
			if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2+2) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2-2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2,swapy2-1,138);
				set_code(swapx2,swapy2+1,138);
				set_code(swapx2,swapy2-2,138);
				set_code(swapx2,swapy2+2,138);
				five_break(swapx1,swapx2);
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 5 BREAK(2)
			else if(get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2+2,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2-2,swapy2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2-1,swapy2,138);
				set_code(swapx2+1,swapy2,138);
				set_code(swapx2-2,swapy2,138);
				set_code(swapx2+2,swapy2,138);
				
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 4 BREAK (3rd Swap)->DIAGNOLLY
			else if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2-2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2,swapy2+1,138);
				set_code(swapx2,swapy2-1,138);
				set_code(swapx2,swapy2-2,138);
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 4 BREAK (2nd Swap)(2)->DIAGONALLY
			else if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2+2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2,swapy2-1,138);
				set_code(swapx2,swapy2+1,138);
				set_code(swapx2,swapy2+2,138);
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 4 BREAK (3rd Swap)
			else if(get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2-2,swapy2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2+1,swapy2,138);
				set_code(swapx2-1,swapy2,138);
				set_code(swapx2-2,swapy2,138);
				
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 4 BREAK (2nd Swap)(4)
			else if(get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2+2,swapy2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2-1,swapy2,138);
				set_code(swapx2+1,swapy2,138);
				set_code(swapx2+2,swapy2,138);
				
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 3 BREAK (FORWARDS)->DIAGONALLY
			else if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2+2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2,swapy2+1,138);
				set_code(swapx2,swapy2+2,138);
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 3 BREAK (CENTER SWAP)->DIAGONALLY
			else if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2,swapy2-1,138);
				set_code(swapx2,swapy2+1,138);
				
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}

			}
			//FOR 3 BREAK (BACKWARDS) ->DIAGONALLY
			else if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1) && get_code(swapx2,swapy2)==get_code(swapx2,swapy2-2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2,swapy2-1,138);
				set_code(swapx2,swapy2-2,138);
				
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 3 BREAK (DOWNWARDS)
			else if(get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2+2,swapy2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2+1,swapy2,138);
				set_code(swapx2+2,swapy2,138);
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
				
			}
			//FOR 3 BREAK (CENTER SWAP)
			else if(get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2-1,swapy2,138);
				set_code(swapx2+1,swapy2,138);
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			//FOR 3 BREAK (UPWARDS)
			else if(get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2) && get_code(swapx2,swapy2)==get_code(swapx2-2,swapy2))
			{
				set_code(swapx2,swapy2,138);
				set_code(swapx2-1,swapy2,138);
				set_code(swapx2-2,swapy2,138);
				
				if(five_break(swapx1,swapx2)==false)
				{
					four_break(swapx1,swapy1);
					if(four_break(swapx1,swapy1)==false)
					{
						three_break(swapx1,swapy1);
						if(three_break(swapx1,swapy1)==false)
						{
						}
					}
				}
				else
				{
					tempcolor=get_code(swapx2,swapy2);
					set_code(swapx2,swapy2,get_code(swapx1,swapy1));
					set_code(swapx1,swapy1,tempcolor);
				}
			}
			else if(get_code(swapx2,swapy2)!=get_code(swapx2+1,swapy2) || get_code(swapx2,swapy2)!=get_code(swapx2-1,swapy2) || get_code(swapx2,swapy2)!=get_code(swapx2,swapy2+1) || get_code(swapx2,swapy2)!=get_code(swapx2,swapy2-1))
			{
				tempcolor=get_code(swapx2,swapy2);
				set_code(swapx2,swapy2,get_code(swapx1,swapy1));
				set_code(swapx1,swapy1,tempcolor);	
			}
			else if(get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2) || get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2) || get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1) || get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1))
			{
				if(get_code(swapx2,swapy2)==get_code(swapx2+1,swapy2))
				{
					if(get_code(swapx2,swapy2)!=get_code(swapx2+2,swapy2))
					{
						tempcolor=get_code(swapx2,swapy2);
						set_code(swapx2,swapy2,get_code(swapx1,swapy1));
						set_code(swapx1,swapy1,tempcolor);	
					}
				}
				if(get_code(swapx2,swapy2)==get_code(swapx2-1,swapy2))
				{
					if(get_code(swapx2,swapy2)!=get_code(swapx2-2,swapy2))
					{
						tempcolor=get_code(swapx2,swapy2);
						set_code(swapx2,swapy2,get_code(swapx1,swapy1));
						set_code(swapx1,swapy1,tempcolor);	
					}
				}
				if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2+1))
				{
					if(get_code(swapx2,swapy2)!=get_code(swapx2,swapy2+2))
					{
						tempcolor=get_code(swapx2,swapy2);
						set_code(swapx2,swapy2,get_code(swapx1,swapy1));
						set_code(swapx1,swapy1,tempcolor);	
					}
				}
				if(get_code(swapx2,swapy2)==get_code(swapx2,swapy2-1))
				{
					if(get_code(swapx2,swapy2)!=get_code(swapx2,swapy2-2))
					{
						tempcolor=get_code(swapx2,swapy2);
						set_code(swapx2,swapy2,get_code(swapx1,swapy1));
						set_code(swapx1,swapy1,tempcolor);	
					}
				}
			}
		}
		bool five_break(int swapx1,int swapy1)
		{
			//FOR 5 BREAK
			if(get_code(swapx1,swapy1)==get_code(swapx1,swapy1-1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1+1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1+2) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1-2))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1,swapy1-1,138);
				set_code(swapx1,swapy1+1,138);
				set_code(swapx1,swapy1-2,138);
				set_code(swapx1,swapy1+2,138);
				
				return true;
			}
			else if(get_code(swapx1,swapy1)==get_code(swapx1-1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1+1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1+2,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1-2,swapy1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1-1,swapy1,138);
				set_code(swapx1+1,swapy1,138);
				set_code(swapx1-2,swapy1,138);
				set_code(swapx1+2,swapy1,138);
				score1=score1+5;
				return true;
			}
			return false;
		}
		bool four_break(int swapx1,int swapy1)
		{
			if(get_code(swapx1,swapy1)==get_code(swapx1,swapy1+1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1-1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1-2))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1,swapy1+1,138);
				set_code(swapx1,swapy1-1,138);
				set_code(swapx1,swapy1-2,138);
				
				return true;
			}
			//FOR 4 BREAK (2nd Swap)
			else if(get_code(swapx1,swapy1)==get_code(swapx1,swapy1-1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1+1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1+2))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1,swapy1-1,138);
				set_code(swapx1,swapy1+1,138);
				set_code(swapx1,swapy1+2,138);
				
				return true;
			}
			//FOR 4 BREAK (3rd Swap)
			else if(get_code(swapx1,swapy1)==get_code(swapx1+1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1-1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1-2,swapy1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1+1,swapy1,138);
				set_code(swapx1-1,swapy1,138);
				set_code(swapx1-2,swapy1,138);
				
				return true;
			}
			//FOR 4 BREAK (2nd Swap)
			else if(get_code(swapx1,swapy1)==get_code(swapx1-1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1+1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1+2,swapy1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1-1,swapy1,138);
				set_code(swapx1+1,swapy1,138);
				set_code(swapx1+2,swapy1,138);
				
				return true;
			}
			return false;
		}
		bool three_break(int swapx1,int swapy1)
		{
			//FOR 3 BREAK (FORWARDS)
			if(get_code(swapx1,swapy1)==get_code(swapx1,swapy1+1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1+2))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1,swapy1+1,138);
				set_code(swapx1,swapy1+2,138);
				
				
				return true;
			}
			//FOR 3 BREAK (CENTER SWAP)
			else if(get_code(swapx1,swapy1)==get_code(swapx1,swapy1-1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1+1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1,swapy1-1,138);
				set_code(swapx1,swapy1+1,138);
				
				
				return true;
			}
			//FOR 3 BREAK (BACKWARDS) 
			else if(get_code(swapx1,swapy1)==get_code(swapx1,swapy1-1) && get_code(swapx1,swapy1)==get_code(swapx1,swapy1-2))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1,swapy1-1,138);
				set_code(swapx1,swapy1-2,138);
				
				
				return true;
			}
			//FOR 3 BREAK (DOWNWARDS)
			if(get_code(swapx1,swapy1)==get_code(swapx1+1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1+2,swapy1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1+1,swapy1,138);
				set_code(swapx1+2,swapy1,138);
				
				
				return true;
			}
			//FOR 3 BREAK (CENTER SWAP)
			else if(get_code(swapx1,swapy1)==get_code(swapx1-1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1+1,swapy1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1-1,swapy1,138);
				set_code(swapx1+1,swapy1,138);
				
				
				return true;
			}

			//FOR 3 BREAK (UPWARDS)
			else if(get_code(swapx1,swapy1)==get_code(swapx1-1,swapy1) && get_code(swapx1,swapy1)==get_code(swapx1-2,swapy1))
			{
				set_code(swapx1,swapy1,138);
				set_code(swapx1-1,swapy1,138);
				set_code(swapx1-2,swapy1,138);
				
				
				return true;
			}
			return false;
		}
		int rand_color_generator()
		{
			r=rand()%7;
			if(r==0)
			{
				color=37;//DARK_SEA_GREEN
			}
			if(r==1)
			{
				color=75;//MEDIUM_PURPLE
			}
			if(r==2)
			{
				color=0;//MAROON
			}
			if(r==3)
			{
				color=68;//BLUE
			}
			if(r==4)
			{
				color=103;//CHOCOLATE
			}
			if(r==5)
			{
				color=89;//HOT_PINK
			}
			if(r==6)
			{
				color=73;//SLATE_BLUE
			}
			return color;
		}
		void refill()
		{
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					if(get_code(i,j)==138)
					{
						if(level==1)
						{
							score1=score1+10;
							set_score1(score1);
						}
						if(score1>=500)
						{
							level=2;
						}
						if(level==2)
						{
							score2=score2+10;
							set_score2(score2);
						}
						if(score2>=1000)
						{
							level=3;
						}
						if(level==3)
						{
							score3=score3+10;
							set_score3(score3);
						}
						if(score3>=1500)
						{
							level=4;
						}
						if(level==4)
						{
							score4=score4+10;
							set_score4(score4);
						}
						set_code(i,j,rand_color_generator());
					}
				}
			}
			if(level==1)
			{
				move1=move1-1;
				set_move1(move1);
				if(move1==0 && get_score1()<500)
				{
					live1=live1-1;
					set_live1(live1);
					score1=0;
					set_score1(score1);
					set_move1(20);
					set_candy_coordinates();
				}
			}
			if(level==2)
			{
				move2=move2-1;
				set_move2(move2);
				if(move2==0 && get_score2()<1000)
				{
					live2=live2-1;
					set_live2(live2);
					score2=0;
					set_score2(score2);
					set_move2(35);
					set_candy_coordinates();
				}
			}
			if(level==3)
			{
				move3=move3-1;
				set_move3(move3);
				if(move3==0 && get_score3()<1500)
				{
					live3=live3-1;
					set_live3(live3);
					score3=0;
					set_score3(score3);
					set_move3(52);
					set_candy_coordinates();
				}
			}
			if(level==4)
			{
				move4=move4-1;
				set_move4(move4);
				if(move4==0 && get_score4()<2000)
				{
					live4=live4-1;
					set_live4(live4);
					score4=0;
					set_score4(score4);
					set_move4(68);
					set_candy_coordinates();
				}
			}
		}
		void refill1()
		{
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					if(get_code(i,j)==138)
					{
						set_code(i,j,rand_color_generator());	
					}
				}
			}
		}
		int hint()
		{
			for(int i=0;i<7;i++)
			{
				for(int j=0;j<7;j++)
				{
					//AT THE SPOT
					if(get_code(i,j)==get_code(i+2,j) && get_code(i,j)==get_code(i+3,j))
					{
						hintcase=1;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						xh1=get_x_axis(i+2,j);
						set_xh1(xh1);
						yh1=get_y_axis(i+2,j);
						set_yh1(yh1);
						xh2=get_x_axis(i+3,j);
						set_xh2(xh2);
						yh2=get_y_axis(i+3,j);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i-2,j) && get_code(i,j)==get_code(i-3,j))
					{
						hintcase=2;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);

						xh1=get_x_axis(i-2,j);
						set_xh1(xh1);
						yh1=get_y_axis(i-2,j);
						set_yh1(yh1);
						xh2=get_x_axis(i-3,j);
						set_xh2(xh2);
						yh2=get_y_axis(i-3,j);
						set_yh2(yh2);
						
						break;
					}
					else if(get_code(i,j)==get_code(i,j+2) && get_code(i,j)==get_code(i,j+3))
					{
						hintcase=3;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);

						xh1=get_x_axis(i,j+2);
						set_xh1(xh1);
						yh1=get_y_axis(i,j+2);
						set_yh1(yh1);
						xh2=get_x_axis(i,j+3);
						set_xh2(xh2);
						yh2=get_y_axis(i,j+3);
						set_yh2(yh2);
						
						break;
					}
					else if(get_code(i,j)==get_code(i,j-2) && get_code(i,j)==get_code(i,j-3))
					{
						hintcase=4;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);

						xh1=get_x_axis(i,j-2);
						set_xh1(xh1);
						yh1=get_y_axis(i,j-2);
						set_yh1(yh1);
						xh2=get_x_axis(i,j-3);
						set_xh2(xh2);
						yh2=get_y_axis(i,j-3);
						set_yh2(yh2);
						
						break;
					}
					//AFTER RIGH SWAP
					else if(get_code(i,j)==get_code(i-1,j+1) && get_code(i,j)==get_code(i-2,j+1))
					{
						hintcase=5;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i-1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i-1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i-2,j+1);
						set_xh2(xh2);
						yh2=get_y_axis(i-2,j+1);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i+1,j+1) && get_code(i,j)==get_code(i+2,j+1))
					{
						hintcase=6;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);

						xh1=get_x_axis(i+1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i+2,j+1);
						set_xh2(xh2);
						yh2=get_y_axis(i+2,j+1);
						set_yh2(yh2);
						
						break;
					}
					else if(get_code(i,j)==get_code(i+1,j+1) && get_code(i,j)==get_code(i-1,j+1))
					{
						hintcase=7;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);

						xh1=get_x_axis(i+1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i-1,j+1);
						set_xh2(xh2);
						yh2=get_y_axis(i-1,j+1);
						set_yh2(yh2);
						
						break;
					}
					//AFTER LEFT SWAP
					else if(get_code(i,j)==get_code(i-1,j-1) && get_code(i,j)==get_code(i-2,j-1))
					{
						hintcase=8;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i-1,j-1);
						set_xh1(xh1);
						yh1=get_y_axis(i-1,j-1);
						set_yh1(yh1);
						xh2=get_x_axis(i-2,j-1);
						set_xh2(xh2);
						yh2=get_y_axis(i-2,j-1);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i+1,j-1) && get_code(i,j)==get_code(i+2,j-1))
					{
						hintcase=9;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i+1,j-1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j-1);
						set_yh1(yh1);
						xh2=get_x_axis(i+2,j-1);
						set_xh2(xh2);
						yh2=get_y_axis(i+2,j-1);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i+1,j-1) && get_code(i,j)==get_code(i-1,j-1))
					{
						hintcase=10;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i+1,j-1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j-1);
						set_yh1(yh1);
						xh2=get_x_axis(i-1,j-1);
						set_xh2(xh2);
						yh2=get_y_axis(i-1,j-1);
						set_yh2(yh2);
						break;
					}
					//AFTER UP SWAP
					else if(get_code(i,j)==get_code(i-1,j+1) && get_code(i,j)==get_code(i-1,j+2))
					{
						hintcase=11;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i-1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i-1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i-1,j+2);
						set_xh2(xh2);
						yh2=get_y_axis(i-1,j+2);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i-1,j-1) && get_code(i,j)==get_code(i-1,j-2))
					{
						hintcase=12;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i-1,j-1);
						set_xh1(xh1);
						yh1=get_y_axis(i-1,j-1);
						set_yh1(yh1);
						xh2=get_x_axis(i-1,j-2);
						set_xh2(xh2);
						yh2=get_y_axis(i-1,j-2);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i-1,j+1) && get_code(i,j)==get_code(i-1,j-1))
					{
						hintcase=13;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i-1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i-1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i-1,j-1);
						set_xh2(xh2);
						yh2=get_y_axis(i-1,j-1);
						set_yh2(yh2);
						break;
					}
					//AFTER DOWN SWAP
					else if(get_code(i,j)==get_code(i+1,j+1) && get_code(i,j)==get_code(i+1,j+2))
					{
						hintcase=14;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i+1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i+1,j+2);
						set_xh2(xh2);
						yh2=get_y_axis(i+1,j+2);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i+1,j-1) && get_code(i,j)==get_code(i+1,j-2))
					{
						hintcase=15;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i+1,j-1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j-1);
						set_yh1(yh1);
						xh2=get_x_axis(i+1,j-2);
						set_xh2(xh2);
						yh2=get_y_axis(i+1,j-2);
						set_yh2(yh2);
						break;
					}
					else if(get_code(i,j)==get_code(i+1,j+1) && get_code(i,j)==get_code(i+1,j-1))
					{
						hintcase=16;
						xh=get_x_axis(i,j);
						set_xh(xh);
						yh=get_y_axis(i,j);
						set_yh(yh);
						
						xh1=get_x_axis(i+1,j+1);
						set_xh1(xh1);
						yh1=get_y_axis(i+1,j+1);
						set_yh1(yh1);
						xh2=get_x_axis(i+1,j-1);
						set_xh2(xh2);
						yh2=get_y_axis(i+1,j-1);
						set_yh2(yh2);
						break;
					}
				}
			}	
			return hintcase;		
		}
		bool draw_hint()
		{
			if(hintcase>0 && hintcase<20)
			{
				DrawString(get_xh()+7,get_yh()+45,"$$$",colors[138]);
				DrawString(get_xh1()+7,get_yh1()+45,"$$$",colors[138]);
				DrawString(get_xh2()+7,get_yh2()+45,"$$$",colors[138]);	
				return true;
			}
			return false;
		}
		~Candy()
		{
			for(int i=0;i<7;i++)
			{
				delete[]x_axis[i];
			}
			delete[]x_axis;
			for(int i=0;i<7;i++)
			{
				delete[]y_axis[i];
			}
			delete[]y_axis;
			for(int i=0;i<7;i++)
			{
				delete[]code[i];
			}
			delete[]code;
		}	
};
#endif