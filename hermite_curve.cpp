#include<iostream>
#include "graphics.h"
//#include"DDALine.h"
using namespace std;

//float P0x = 100, P0y = 100, P1x = 150, P1y = 50, P2x = 250, P2y = 200, P3x = 350, P3y = 40, Px= 0, Py = 0, Pz = 0;
float P0x = 40, P0y = 250, P1x = 40, P1y = 200, P2x = 40, P2y = 150, P3x = 40, P3y = 100, Px= 0, Py = 0, Pz = 0;

void calcP(float &Px, float &Py, float &Pz, float t){
    Px = (-4.5 * t * t* t + 9*t*t - 5.5 *t +1)*P0x + (13.5 * t*t*t - 22.5 *t*t +9*t)*P1x + (-13.5 * t*t*t + 18*t*t -4.5*t)*P2x +(4.5*t*t*t -4.5*t*t +t)*P3x;
    Py = (-4.5 * t * t* t + 9*t*t - 5.5 *t +1)*P0y + (13.5 * t*t*t - 22.5 *t*t +9*t)*P1y + (-13.5 * t*t*t + 18*t*t -4.5*t)*P2y +(4.5*t*t*t -4.5*t*t +t)*P3y;
//    Pz = (-4.5 * t * t* t + 9*t*t - 5.5 *t +1)*P0z + (13.5 * t*t*t - 22.5 *t*t +9*t)*P1z + (-13.5 * t*t*t + 18*t*t -4.5*t)*P2z +(4.5*t*t*t -4.5*t*t +t)*P3z;
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
line(80,100,550,100);
line(540,100,540,250);
line(450,100,450,250);
line(80,175,140,175);
line(80,175,90,185);
line(190,100,150,50);
    float t = 0;
    P0x = 90, P0y = 185, P1x = 90, P1y = 150, P2x = 90, P2y = 125, P3x = 90, P3y = 100, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

 t=0;
P0x = 450, P0y = 150, P1x = 400, P1y =125 , P2x = 400, P2y = 175, P3x = 450, P3y = 150, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }
t=0;
P0x = 450, P0y = 150, P1x = 500, P1y =125 , P2x = 500, P2y = 175, P3x = 450, P3y = 150, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }
     t=0;
P0x = 150, P0y = 50, P1x = 152, P1y = 58, P2x = 154, P2y = 64, P3x = 170, P3y = 75, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t=0;
P0x = 140, P0y = 250, P1x = 140, P1y = 200, P2x = 140, P2y = 150, P3x = 140, P3y = 100, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t=0;
P0x = 190, P0y = 250, P1x = 190, P1y = 200, P2x = 190, P2y = 150, P3x = 190, P3y = 100, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }
    t=0;
    P0x = 240, P0y = 250, P1x = 240, P1y = 200, P2x = 240, P2y = 150, P3x = 240, P3y = 100, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t = 0;
    P0x = 370, P0y = 250, P1x = 370, P1y = 200, P2x = 370, P2y = 150, P3x = 370, P3y = 100, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t = 0;
    P0x = 300, P0y = 165, P1x = 295, P1y = 180, P2x = 285, P2y = 180, P3x = 280, P3y = 165, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t = 0;
    P0x = 280, P0y = 165, P1x = 320, P1y = 165, P2x = 340, P2y = 165, P3x = 370, P3y = 165, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t = 0;
    P0x = 280, P0y = 165, P1x = 320, P1y = 165, P2x = 340, P2y = 165, P3x = 360, P3y = 165, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }

    t = 0;
    P0x = 240, P0y = 100, P1x = 230, P1y = 70, P2x = 250, P2y = 45, P3x = 280, P3y = 50, Px= 0, Py = 0, Pz = 0;
    while(t<1){
        calcP(Px, Py, Pz, t);
        t+=0.001;
        putpixel(Px, Py, WHITE);
    }
    getch();
    closegraph();
    return 0;
}
