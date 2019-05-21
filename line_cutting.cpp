#include <iostream>
#include<graphics.h>
#include"DDA_line.h"
#include<conio.h>
#define LEFT 0x1
#define RIGHT 0x4
#define BOTTOM 0x2
#define TOP 0x8
double x1,y1,x2,y2;
int tx1,tx2,tx3,ty1,ty2,ty3;
int fx3(int x, int y)
{
    return (y-ty1) + (x-tx1)*(ty2-ty1)/(tx2-tx1);
}
int fx2(int x, int y)
{
    return (y-ty1) + (x-tx1)*(ty3-ty1)/(tx3-tx1);
}
int fx1(int x, int y)
{
    return (y-ty2) + (x-tx2)*(ty3-ty1)/(tx3-tx1);
}
double compute_region(double x, double y)
{
    int code;
    if(fx1(x,y) * fx1(tx1,ty1)<0)
        code|=0x1;
    if(fx2(x,y) * fx2(tx2,ty2)<0)
        code|=0x2;
    if(fx3(x,y) * fx3(tx3,ty3)<0)
        code|=0x4;

    return code;
}
double find_quadrant(int x, int y)
{
    int code=0;
    if(x<x1)
        code|=LEFT;
    if(x>x2)
        code|=RIGHT;
    if(y<y1)
        code|=BOTTOM;
    if(y>y2)
        code|=TOP;

    return code;
}
using namespace std;
void mm()
{

    x1=100;
    y1=100;
    x2=400;
    y2=400;
    DDA(x1,y1,x2,y1,RED);
    DDA(x1,y1,x1,y2,RED);
    DDA(x1,y2,x2,y2,RED);
    DDA(x2,y1,x2,y2,RED);
    double lx1=4;
    double ly1=4;
    double lx2=600;
    double ly2=650;
    int code1 = find_quadrant(lx1, ly1);
    int code2 = find_quadrant(lx2, ly2);
    double m  = (ly2-ly1)/(lx2-lx1);

    DDA(lx1,ly1,lx2,ly2,RED);

    while(true)
    {
        cout << "code1 : " << code1 << endl;
        cout << "code2 : " << code2 << endl;
        double x,y;
        if(code1==0 && code2==0)
            break;
        else if(code1&code2)
            {
                cout << "deda";
                return;
            }
        else
        {
            int code;
            if(code1!=0)
                code=code1;
            else
                code=code2;

            cout << "code : " << code << endl;
            if(code&TOP)
            {
                x = lx1 + (y2-ly1)/m;
                y = y2;
            }
            if(code&BOTTOM)
            {
                x = lx1 + (y1-ly1)/m;
                y=y1;
            }

            if(code&LEFT)
            {
                y = ly1 + (x1-lx1)*m;
                x = x1;
            }

            if(code&RIGHT)
            {
                y = ly1 + (x2-lx1)*m;
                x =x2;
            }
            cout << "x : " << x << "  y:  " << y << endl;
            if(code==code1)
            {

                lx1 = x;
                ly1 = y;
                code1 = find_quadrant(x,y);
            }
            else
            {
                lx2 = x;
                ly2 = y;
                code2 = find_quadrant(x,y);
            }
        }
    }
    cout << lx1 << "  " << ly1 << "  " << lx2 << "  " << ly2;
    DDA(lx1,ly1,lx2,ly2, BLUE);
    //DDA(nlx1,nly1,lx1,ly1,GREEN);
    delay(1000);
    getch();
}
void triangle_cutting()
{
    int tx1,tx2,tx3,ty1,ty2,ty3;
    DDA(tx1,ty1,tx2,ty2,RED);
    DDA(tx1,ty1,tx3,ty3,RED);
    DDA(tx2,ty2,tx3,ty3,RED);


    int tlx1,tly1,tlx2,tly2;

    int code1 = compute_region(tlx1,tly1);
    int code2 = compute_region(tlx2,tly2);

    if(code1==0 && code2==0)
    {

    }
    else if(code1&&code2)
    {


    }
    else
    {

    }

}
int main()
{
    initwindow(1300,700);
    mm();
    getch();
    cout << "Hello world!" << endl;
    return 0;
}
