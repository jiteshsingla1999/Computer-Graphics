#include <bits/stdc++.h>
#include<graphics.h>
#include<DDA_line.h>
#define pb push_back
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
void cyrus_beck(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4,  double lx1, double ly1, double lx2, double ly2)
{
    edge point1(x1,y1);
    edge point2(x2,y2);
    edge point3(x3,y3);
    edge point4(x4,y4);
    DDA(point1.x, point1.y, point2.x, point2.y, BLUE);
    DDA(point2.x, point2.y, point3.x, point3.y, BLUE);
    DDA(point3.x, point3.y, point4.x, point4.y, BLUE);
    DDA(point4.x, point4.y, point1.x, point1.y, BLUE);

    edge side12 = point1.sub_edge(point1, point2 );
    edge side23 = point2.sub_edge(point2, point3 );
    edge side34 = point3.sub_edge(point3, point4 );
    edge side41 = point4.sub_edge(point4, point1 );

    edge normal12 = side12.find_normal();
    edge normal23 = side23.find_normal();
    edge normal34 = side34.find_normal();
	edge normal41 = side41.find_normal();

    edge p1(lx1,ly1);
    edge p2(lx2,ly2);
    DDA(p1.x,p1.y,p2.x,p2.y,BLUE);

    edge diff = p1.sub_edge(p1,p2);

	vector<double> enter,exitt;
  	enter.clear();
  	exitt.clear();
  	
    double temp1 = normal12.dotProduct(normal12, p1.sub_edge(point1, p1));
    double temp2 = normal12.dotProduct(normal12, diff);
    double t1 = (-1.00)*(temp1/temp2);
    if(temp2<0)
    enter.pb(t1);
    else
    exitt.pb(t1);
    
    
    double t2 = (-1.00)*normal23.dotProduct(normal23, p1.sub_edge(point2, p1))/normal23.dotProduct(normal23, diff);
    if(normal23.dotProduct(normal23, diff)<0)
    enter.pb(t2);
    else
    exitt.pb(t2);
    
    
    double t3 = (-1.00)*normal34.dotProduct(normal34, p1.sub_edge(point3, p1))/normal34.dotProduct(normal34, diff);
    if(normal34.dotProduct(normal34, diff)<0)
    enter.pb(t3);
    else
    exitt.pb(t3);
    
    
    double t4 = (-1.00)*normal41.dotProduct(normal41, p1.sub_edge(point4, p1))/normal41.dotProduct(normal41, diff);
	if(normal41.dotProduct(normal41, diff)<0)
    enter.pb(t4);
    else
    exitt.pb(t4);
  	
  	sort(enter.begin(), enter.end());
  	sort(exitt.begin(), exitt.end());
  	
  	t1 = enter[enter.size()-1];
  	t2 = exitt[0];

    edge n1 = p1.add_edge(p1, diff.prod(diff,t1));
    edge n2 = p1.add_edge(p1, diff.prod(diff,t2));
    DDA(n1.x, n1.y, n2.x, n2.y, RED);


    getch();
}
