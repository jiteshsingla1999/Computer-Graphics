#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;


void myLine(int X1, int Y1, int X2, int Y2)
{
    int dx = abs(X2 - X1);
    int dy = abs(Y2 - Y1);
    int x,y,d,c;
    if(dx>dy)
    {
        d = dy - (dx/2);

        if(X2>X1)
        {
            x = X1, y = Y1;
            if(Y1<Y2)
                c=1;
            else
                c=-1;
            while (x < X2)
            {
                x++;
                if (d < 0)
                    d = d + dy;
                else
                {
                    d += (dy - dx);
                    y+=c;
                }
                putpixel(x,y,7);
            }
        }
        else
        {
            x = X2, y = Y2;
            if(Y2<Y1)
                c=1;
            else
                c=-1;
            while (x < X1)
            {
                x++;
                if (d < 0)
                    d = d + dy;
                else
                {
                    d += (dy - dx);
                    y+=c;
                }
                putpixel(x,y,7);
            }
        }
    }


    else
    {
        d = dx - (dy/2);

        if(Y2>Y1)
        {
            x = X1, y = Y1;
            if(X1<X2)
                c=1;
            else
                c=-1;
            while (y < Y2)
            {
                y++;
                if (d < 0)
                    d = d + dx;
                else
                {
                    d += (dx - dy);
                    x+=c;
                }
                putpixel(x,y,7);
            }
        }
        else
        {
            x = X2, y = Y2;
            if(X2<X1)
                c=1;
            else
                c=-1;
            while (y < Y1)
            {
                y++;
                if (d < 0)
                    d = d + dx;
                else
                {
                    d += (dx - dy);
                    x+=c;
                }
                putpixel(x,y,7);
            }
        }
    }

}







//x------------------------x-----------------------------x------------------------------x------------------------------------x---------------------x



void drawellipse(int xc, int yc , int a , int b , int ccode=15,int theta = 0){ int x, y,xdash,ydash;

float d1, d2 = 0, dx, dy;

x = 0;

y = b;

d1 = pow(b, 2) - (pow(a, 2) * b) + (0.25 * pow(a, 2));

dx = 2 * pow(b, 2) * x;

dy = 2 * pow(a, 2) * y;

do	{

xdash = (x)*cos(theta *3.14 / 90) - (y) *sin(theta *3.14/90); ydash = (x)*sin(theta *3.14 / 90) + (y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

xdash = (x)*cos(theta *3.14 / 90) - (-y) *sin(theta *3.14/90); ydash = (x)*sin(theta *3.14 / 90) + (-y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

xdash = (-x)*cos(theta *3.14 / 90) - (y) *sin(theta *3.14/90); ydash = (-x)*sin(theta *3.14 / 90) + (y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

xdash = (-x)*cos(theta *3.14 / 90) - (-y) *sin(theta *3.14/90); ydash = (-x)*sin(theta *3.14 / 90) + (-y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

if (d1 < 0)	{

x++;
dx = dx + (2 * (pow(b, 2)));

d1 = d1 + dx + (pow(b, 2));

}
else	{

x++;
y--;

dx = dx + (2 * (pow(b, 2)));
dy = dy - (2 * (pow(a, 2)));

d1 = d1 + dx - dy + (pow(b, 2));

}} while (dx < dy);

do{

xdash = (x)*cos(theta *3.14 / 90) - (y) *sin(theta *3.14/90); ydash = (x)*sin(theta *3.14 / 90) + (y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash,ccode);

xdash = (x)*cos(theta *3.14 / 90) - (-y) *sin(theta *3.14/90); ydash = (x)*sin(theta *3.14 / 90) + (-y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

xdash = (-x)*cos(theta *3.14 / 90) - (y) *sin(theta *3.14/90); ydash = (-x)*sin(theta *3.14 / 90) + (y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

xdash = (-x)*cos(theta *3.14 / 90) - (-y) *sin(theta *3.14/90); ydash = (-x)*sin(theta *3.14 / 90) + (-y) *cos(theta *3.14/90); putpixel(xc+ xdash,yc+ ydash, ccode);

if (d2 > 0)	{

x = x;

y--;

dy = dy - (2 * (pow(a, 2)));

d2 = d2 - dy + pow(a, 2);

}

else	{

x++;

y--;

dy = dy - (2 * (pow(a, 2)));

dx = dx + (2 * (pow(b, 2)));

d2 = d2 + dx - dy + pow(a, 2);

}

} while (y > 0);

}

int round(float n){

return floor((n+0.5));

}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");


    myLine(200,400,400,200);
    myLine(400,200,400,400);
    myLine(400,400,200,400);



int x=180,y=400,a=18,b=10;
int theta = 0;

while(theta<1080){

x = x+1;

y = y-1;

drawellipse(x,y,a,b,15,theta);

delay(50);
myLine(200,400,400,200);
drawellipse(x,y,a,b,0,theta);


theta+=5;

}

    getch();
    closegraph();
    return 0;
}
