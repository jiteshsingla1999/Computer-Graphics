#include <iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;
void displaycircle(int x, int y, int xr, int yr)
{
    int dify = y;
    int difx = x;

    putpixel(x+xr,y+yr,RED);
    putpixel(y+xr,x+yr,RED);
    putpixel(x+xr,yr-dify,RED);
    putpixel(xr-dify,x+yr,RED);
    putpixel(xr-difx,y+yr,RED);
    putpixel(y+xr,yr-difx,RED);
    putpixel(xr-difx,yr-dify,RED);
    putpixel(xr-dify,yr-difx,RED);

}
int main()
{
    initwindow(640,640);
    int xr = getmaxx()/2;
    int yr = getmaxy()/2;

    int Rad = 50;

    int x = 0;
    int y = Rad;

    int d = 1-Rad;

    displaycircle(x,y,xr,yr);

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

        displaycircle(x,y,xr,yr);
    }
    getch();
    closegraph();
}
