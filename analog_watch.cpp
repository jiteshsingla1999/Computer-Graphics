#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "DDA_line_right_to_left.h"
#define PI 3.147

void clockLayout();
void secHand();
void hrHand();
void minHand();
int maxx,maxy;

int main()
{
    initwindow(1300,768);

    while(1)
    {
        clockLayout();
        secHand();
        minHand();
        hrHand();
        delay(1000);/* pausing the outputscreen for 1 sec */
        cleardevice();           /* clearing the previous picture of clock */
    }
}

void clockLayout()
{
    int i,x,y,r;
    float j;
    maxx=getmaxx();
    maxy=getmaxy();

    for(i=1; i<5; i++)
    {
        /* printing a round ring with outer radius of 5 pixel */
        setcolor(BLUE);
        circle(maxx/2,maxy/2,120-i);
    }

    pieslice(maxx/2,maxy/2,0,360,5);    /* displaying a circle in the middle of clock */
    x=maxx/2+100;
    y=maxy/2;
    r=100;
    setcolor(BLUE);

    for(j=PI/6; j<=(2*PI); j+=(PI/6))
    {
        /* marking the hours for every 30 degrees */
        pieslice(x,y,0,360,4);
        x=(maxx/2)+r*cos(j);
        y=(maxy/2)+r*sin(j);
    }

    x=maxx/2+100;
    y=maxy/2;
    r=100;
    setcolor(RED);

    for(j=PI/30; j<=(2*PI); j+=(PI/30))
    {
        /* marking the minutes for every 6 degrees */
        pieslice(x,y,0,360,2);
        x=(maxx/2)+r*cos(j);
        y=(maxy/2)+r*sin(j);
    }
}

void secHand()
{
    time_t t;
    int r=80,x=maxx/2,y=maxy/2,sec;
    float O;

    maxx=getmaxx();
    maxy=getmaxy();
    time(&t);
//gettime(&t);
    /*getting the seconds in system clock */
    sec= t%60;
    O=sec*(PI/30)-(PI/2);           /* determining the angle of the line with respect to vertical */
    setcolor(YELLOW);
    DDA(maxx/2,maxy/2,x+r*cos(O),y+r*sin(O));
}

void hrHand()
{
    int r=50,hr,minn;
    int x,y;
    time_t tt;
    float O;
    time(&tt);
    maxx=getmaxx();
    maxy=getmaxy();
    x=maxx/2,y=maxy/2;
    int  hh = tt;
    hh = hh/60;
    minn = hh%60;
    hh = hh/60;
    hr=hh%24;
//min=t.ti_min;

    /* determining the angle of the line with respect to vertical */
    if(hr<=12)
        O=(hr*(PI/6)-(PI/2))+((minn/12)*(PI/30));
    if(hr>12)
        O=((hr-12)*(PI/6)-(PI/2))+((minn/12)*(PI/30));
    setcolor(BLUE);
    DDA(maxx/2,maxy/2,x+r*cos(O),y+r*sin(O));
}

void minHand()
{
    int r=60,minn;
    int x,y;
    float O;
    time_t t;
    maxx=getmaxx();
    maxy=getmaxy();
    x=maxx/2;
    y=maxy/2;
    time(&t);
    int gg = t;
    gg = gg/60;  /*getting the seconds in system clock */
    minn=gg%60;
    O=(minn*(PI/30)-(PI/2)); /* determining the angle of the line with respect to vertical */
    setcolor(RED);
    DDA(maxx/2,maxy/2,x+r*cos(O),y+r*sin(O));
}
