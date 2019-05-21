#include<iostream>
#include<graphics.h>
#include<conio.h>
#include "ellipse.h"
#include<MidPointCircle.h>
#define PI 3.1416
#include<math.h>
using namespace std;


void revolve_circle_around_ellipse(float x0, float y0, float a, float b,  float r)
{
    drawellipse(a,b,x0,y0);

    for(float ff = PI/30;ff<=2*PI;ff+=PI/30)
    {
        float i = ff;
        float xx = a*cos(ff) + r*b*cos(ff)/(sqrt(a*a*sin(i)*sin(i) + b*b*cos(i)*cos(i)));
        float yy = b*sin(ff) + r*a*sin(ff)/(sqrt(a*a*sin(i)*sin(i) + b*b*cos(i)*cos(i)));

        draw_circle(x0+xx,y0+yy, r,RED);

        delay(100);
        draw_circle(x0+xx,y0+yy,r,BLACK);
        drawellipse(a,b,x0,y0);

    }


    getch();

}