#include <iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;
void displaycircle(int x, int y, int xr, int yr, int color)
{
    int dify = y;
    int difx = x;

    putpixel(x+xr,y+yr,color);
    putpixel(y+xr,x+yr,color);
    putpixel(x+xr,yr-dify,color);
    putpixel(xr-dify,x+yr,color);
    putpixel(xr-difx,y+yr,color);
    putpixel(y+xr,yr-difx,color);
    putpixel(xr-difx,yr-dify,color);
    putpixel(xr-dify,yr-difx,color);

}
void draw_circle(int xr, int yr,  int Rad, int color)
{
   

    int x = 0;
    int y = Rad;

    int d = 1-Rad;

    displaycircle(x,y,xr,yr,color);

    while(x<=y)
    {
        if(d<=0)
            d += 2*x+3;
        else
        {
            d += 2*(x-y)+5;
            y--;
        }

        x++;

        displaycircle(x,y,xr,yr,color);
    }
    
}
