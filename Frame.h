#ifndef FRAME_H_
#define FRAME_H_
#include"util.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<cmath>
class Frame
{
	public:
		void draw_frame()
		{
			DrawLine(5,700,5,1750,10,colors[WHITE]);
			DrawLine(995,700,995,1750,10,colors[WHITE]);
			DrawLine(0,695,1000,695,10,colors[WHITE]);
			for(int i=845;i<1840;i=i+150)//y1 and y2
			{
				DrawLine(0,i,1000,i,10,colors[WHITE]);
				if(i==1745)
				{
					DrawLine(0,i,1000,i,10,colors[WHITE]);	
				}
			}
			for(int i=145;i<995;i=i+140)
			{
				DrawLine(i,700,i,1750,10,colors[WHITE]);
			}
		}
};
#endif