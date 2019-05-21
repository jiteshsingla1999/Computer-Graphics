#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<DDA_line.h>
using namespace std;
class Point
{
public:
    double x,y;
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
};
double find_region(Point a, Point l1, Point l2)
    {
        double result = (a.y - l1.y) - (a.x - l1.x)*(l2.y-l1.y)/(l2.x-l1.x);
        return result;
    }
double find_slope(Point p1, Point p2)
    {
        return (p2.y-p1.y)/(p2.x-p1.x);
    }
    Point find_intersection(Point l1, Point l2, Point l3, Point l4)
    {
        double x  = l3.y - l1.y + l1.x*(l2.y-l1.y)/(l2.x-l1.x) - l3.x*(l4.y-l3.y)/(l4.x-l3.x);
        x = x*(1/((l2.y-l1.y/(l2.x-l1.x) - (l4.y - l3.y)/(l4.x - l3.x))));
        double y = l3.y + (x-l3.x)*(l4.y-l3.y)/(l4.x - l3.x);
        Point res(x,y);
        return res;

    }

 void display(Point p1, Point p2, int color=BLUE)
    {
        DDA(p1.x,p1.y,p2.x,p2.y,color);
    }
int main()
{

    Point t1(0.0,0.0);
    Point t2(300.0,0.0);
    Point t3(0.0,400.0);

    Point l1(500.0,600.0);
    Point l2(600,600);
    initwindow(1300,768);
    display(l1,l2,BLUE);
    display(t1,t2,BLUE);
    display(t2,t3);
    display(t3,t1);

    ///Case 1: One Point is inside the triangular window
    Point in(0.0,0.0);
    if( find_region(t3, t1,t2)*find_region(l1,t1,t2)>0 && find_region (t1, t2,t3)*find_region(l1,t2,t3)>0 && find_region (t2, t3,t1)*find_region(l1,t3,t1)>0)
        in  = l1;
    else if ( find_region(t3, t1,t2)*find_region(l2,t1,t2)>0 && find_region (t1, t2,t3)*find_region(l2,t2,t3)>0 && find_region (t2, t3,t1)*find_region(l2,t3,t1)>0)
        in = l2;
    cout << "Point inside the figure is : ";
    cout << "(" << in.x << "," << in.y << ")" <<  endl;
    double slope1  = find_slope(in,t1);
    double slope2  = find_slope(in,t2);
    double slope3  = find_slope(in, t3);
    double m       = find_slope(l1,l2);

    if(slope1<=m && m<=slope2)
    {
        Point nn = find_intersection(l1,l2,t1,t2);

        display(nn,in,RED);
    }
    else if(slope2<=m && m<=slope3)
    {
        Point nn = find_intersection(l1,l2,t2,t3);
        display(nn,in,RED);
    }
    else
    {
        Point nn = find_intersection(l1,l2,t3,t1);
        display(nn,in,RED);
    }


}
