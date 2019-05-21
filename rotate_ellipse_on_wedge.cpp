#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<DDA_line.h>
#define PI 3.1416
#include<math.h>
using namespace std;
void putpixelll(float a1, float a2, int c, float theta,float x0, float y0)
{
    float a11 = a1*cos(theta*PI/90) - a2*sin(theta*PI/90);
    float a22 = a1*sin(theta*PI/90) + a2*cos(theta*PI/90);

    putpixel(x0+a11,y0+a22,c);

}
void drawellipse(int a, int b, int x0, int y0, float theta,int c)
{
   int p=b*b-a*a*b+a*a/4;
   int x=0;
   int y=b;
   while(2.0*b*b*x <= 2.0*a*a*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*b*b*x+b*b;
	}
	else
	{
		x++;y--;
		p = p+2*b*b*x-2*a*a*y-b*b;
	}
	putpixelll(x,y,c, theta,x0,y0);
	putpixelll(x,-1*y,c,theta,x0,y0);
	putpixelll(-1*x,y,c,theta,x0,y0);
	putpixelll(-1*x,-1*y,c,theta,x0,y0);
   }

  //Region 2
   p= b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		p = p+2*b*b*x-2*a*a*y+a*a;
	}
	else
	{
		y--;
		p = p-2*a*a*y+a*a;
	}
	putpixelll(x,y,c,theta,x0,y0);
	putpixelll(x,-1*y,c,theta,x0,y0);
	putpixelll(-1*x,y,c,theta,x0,y0);
	putpixelll(-1*x,-1*y,c,theta,x0,y0);
   }
}

void revolve_ellipse_around_wedge(float x0, float y0, float m, float a, float b)
{

    float theta = 0;
    int x00 = 300;
    int y00=400;
    DDA(300,420,600,420,5);
    DDA(600,420,600,100,5);
    DDA(300,420,600,150,5);
    while(theta<=1080)
    {
    drawellipse(30,15,x00,y00,theta, 5);
    delay(30);
    drawellipse(30,15,x00,y00,theta,BLACK);
    DDA(300,420,600,150,5);
    x00++;
    y00--;
    theta+=5;
    }


    getch();

}

int main()
{

    initwindow(1300,768);
    revolve_ellipse_around_wedge(10,10,1,100,50);

}
