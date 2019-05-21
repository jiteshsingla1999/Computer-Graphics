#include <bits/stdc++.h>
#include<graphics.h>
#include<DDA_line.h>

using namespace std;
class edge
{
public:
    double x,y;
    edge(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    edge sub_edge(edge b, edge a)
    {

        edge v(0,0);
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        return v;
    }
    edge add_edge(edge a, edge b)
    {

        edge v(0,0);
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        return v;
    }
    double dotProduct(edge a, edge b)
    {
        return a.x*b.x + a.y*b.y;
    }
    edge prod(edge a, double t)
    {
   //     cout << "prod :" << t << " -> " << a.x << " " << a.y << endl;
        edge yy(0,0);
        //cout << t << endl;
        yy.x= a.x*t;
        yy.y= a.y*t;

        return yy;
    }
    edge find_normal()
    {

        edge v(0,0);
        v.x = abs(y);
        v.y = abs(x);
        if(x<0)
            v.y = -1*v.y;
        if(y>0)
            v.x = -1*v.x;
        return v;
    }


};
int main()
{
    initwindow(1300,700);
    edge point1(10,10);
    edge point2(10,400);
    edge point3(400,10);
    DDA(point1.x, point1.y, point2.x, point2.y, BLUE);
    DDA(point2.x, point2.y, point3.x, point3.y, BLUE);
    DDA(point3.x, point3.y, point1.x, point1.y, BLUE);

    edge side12 = point1.sub_edge(point1, point2 );

    edge side23 = point2.sub_edge(point2, point3 );
    edge side31 = point3.sub_edge(point3, point1 );

    edge normal12 = side12.find_normal();
    edge normal23 = side23.find_normal();
    edge normal31 = side31.find_normal();
 //   cout << "Normal : " << normal12.x << " " << normal12.y << endl;
   // cout << "Normal : " << normal23.x << " " << normal23.y << endl;
   // cout << "Normal : " << normal31.x << " " << normal31.y << endl;

    edge p1(50,120);
    edge p2(50,500);
    DDA(p1.x,p1.y,p2.x,p2.y,BLUE);

    edge diff = p1.sub_edge(p1,p2);
 //   cout << diff.x << " " << diff.y << endl;

    double temp1 = normal12.dotProduct(normal12, p1.sub_edge(point1, p1));
    double temp2 = normal12.dotProduct(normal12, diff);
   // cout << temp1 << " [[[[[" << temp2 << endl;
    double t1 = (-1)*(temp1/temp2);
    double t2 = (-1)*normal23.dotProduct(normal23, p1.sub_edge(point2, p1))/normal23.dotProduct(normal23, diff);
    double t3 = (-1)*normal31.dotProduct(normal31, p1.sub_edge(point3, p1))/normal31.dotProduct(normal31, diff);
 //   cout << t1 << " " << t2 << " " << t3 << endl;
     if(t1<0 || t1>1)
    {
        t1=t3;
    }
    else if(t2<0 || t2>1)
        t2=t3;
//cout << t1 << " " << t2 << endl;
    edge n1 = p1.add_edge(p1, diff.prod(diff,t1));
    edge n2 = p1.add_edge(p1, diff.prod(diff,t2));
   // cout << diff.prod(diff,t2).x << " [[ " << diff.prod(diff,t2).y << endl;
  //  cout << n1.x << " " << n1.y << " " << n2.x << " " << n2.y;
    DDA(n1.x, n1.y, n2.x, n2.y, RED);
    //outtextxy(400,400,"huhuhiuhuhuhuhuhuhuhuhuhu");

    getch();
}
