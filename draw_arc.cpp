#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define PI 3.147
using namespace std;
void draw_arc(double x, double y, double rad, double start, double stop, int c=RED)
{
    int r = rad;
    double j = start;
    double xx=x;
    double yy=y;
    while(j<=stop)
    {
       double dist = sqrt((xx-649)*(xx-649) + (yy-349)*(yy-349));
       if(dist<=rad)
        putpixel(xx,yy,c);

       xx=(x)+r*cos(j);
       yy=(y)+r*sin(j);
       j+=0.00003;
    }

}
int main()
{
    initwindow(1300,700);
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    int rad=100;
    draw_arc(x,y,rad, 0, 2*PI,BLUE);
    for(int h=0;h<=6;h++)
        draw_arc(x + rad*cos(h*PI/3), y+rad*sin(h*PI/3), rad, 0 , 2*PI);
    getch();
    return 0;

}
