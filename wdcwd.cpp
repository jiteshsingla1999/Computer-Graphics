#include<iostream>
#include "graphics.h"
#include "DDA_line.h"
using namespace std;


void drawRectangle(int xwmin, int ywmin, int xwmax, int ywmax)
{
    DDA(xwmin, ywmin, xwmax, ywmin,1);
    DDA(xwmax, ywmin, xwmax, ywmax,1);
    DDA(xwmax, ywmax, xwmin, ywmax,1);
    DDA(xwmin, ywmax, xwmin, ywmin,1);
}

void input(int &p1x, int &p1y, int &p2x, int &p2y, int &xwmin, int &ywmin, int &xwmax, int &ywmax)
{
    cout<<"Enter x-coordinate of point 1:\t";
    cin>>p1x;
    cout<<"Enter y-coordinate of point 1:\t";
    cin>>p1y;
    cout<<"Enter x-coordinate of point 2:\t";
    cin>>p2x;
    cout<<"Enter y-coordinate of point 2:\t";
    cin>>p2y;
    cout<<"\n";
    cout<<"Enter x-coordinate of bottom-left corner of rectangle:\t";
    cin>>xwmin;
    cout<<"Enter y-coordinate of bottom-left corner of rectangle:\t";
    cin>>ywmin;
    cout<<"Enter x-coordinate of top-right corner of rectangle:\t";
    cin>>xwmax;
    cout<<"Enter y-coordinate of top-right corner of rectangle:\t";
    cin>>ywmax;

}

float calculateT(int Nx, int Ny, int P1x, int P1y, int P2x, int P2y, int PEx, int PEy, bool &enter){
    int num = Nx*(P1x-PEx) + Ny*(P1y-PEy);
    int den = -1*(Nx*(P2x-P1x)+Ny*(P2y-P1y));
    float t;
    if(den == 0){
        enter = true;
        t = 0;
        return true;
    }
    else if(den > 0){
        enter = true;
    }
    else{
        enter = false;
    }
    t = num/(float)den;
    return t;
}

void Ptcoordinates(float t, int P0x, int P0y, int P1x, int P1y, int &x, int &y){
    x = P0x + (P1x-P0x)*t;
    y = P0y + (P1y-P0y)*t;
}

bool clipLine(int xwmin, int ywmin, int xwmax, int ywmax, int &p0x, int &p0y, int &p1x, int &p1y){
    float maxenter = 0, minexit = 1;
    bool enter = false;
    int Nx[] = {-1, 0, 1, 0};
    int Ny[] = {0, -1, 0, 1};
    int clipx[] = {xwmin, xwmin, xwmax, xwmax};
    int clipy[] = {ywmax, ywmin, ywmin, ywmax};
    for(int i = 0; i<4; i++){
        float t = calculateT(Nx[i], Ny[i], p0x, p0y, p1x, p1y, clipx[i], clipy[i], enter);
        if(enter){
            maxenter = max(t, maxenter);
        }
        else{
            minexit = min(t, minexit);
        }
    }
    if(maxenter > minexit)
        return false;
    int xenter, yenter, xexit, yexit;
    Ptcoordinates(maxenter, p0x, p0y, p1x, p1y, xenter, yenter);
    Ptcoordinates(minexit, p0x, p0y, p1x, p1y, xexit, yexit);
    p0x = xenter; p0y = yenter; p1x = xexit; p1y = yexit;
    return true;
}

int main()
{
    initwindow(1300,700);

    int p1x, p1y, p2x, p2y;
    int xwmin, ywmin, xwmax, ywmax;

    input(p1x, p1y, p2x, p2y, xwmin, ywmin, xwmax, ywmax);

    drawRectangle(xwmin, ywmin, xwmax, ywmax);

    if(p1x == p2x && p1y == p2y){
        cout<<"Point Clipping\n";
        exit(0);
    }

    int x0 = p1x, y0 = p1y, x1 = p2x, y1 = p2y;
    bool done = false;

    done = clipLine(xwmin, ywmin, xwmax, ywmax, p1x, p1y, p2x, p2y);

    if(done){

        DDA(x0, y0, p1x, p1y, RED);
        DDA(p1x, p1y, p2x, p2y, YELLOW);
        DDA(p2x, p2y, x1, y1, RED);
    }

    else{
        DDA(x0, y0, x1, y1, RED);
    }

    getch();
    closegraph();
    return 0;
}
