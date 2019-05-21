#include<iostream>
#include<graphics.h>
using namespace std;
#define left 0x1;
#define bottom 0x2;
#define right 0x4;
#define top 0x8;
class point {
    public:
    int x,y;
    point(int a,int b){
    x=a;
    y=b;
    }
};
int gencode(point q){
    int code=0x0;
    if(q.x+q.y-50<0) code=code|left;
    if(q.y-2*q.x+100<0) code|=bottom;
    if(110-q.y-q.x<0) code|=right;
    if(2*q.x-q.y-40<0) code|=top;
    return code;
}
void ptable(point p1,point p2,point pm,int c1,int c2,int cm){
    cout<<"("<<p1.x<<","<<p1.y<<")\t\t"<<c1<<"\t\t";
    cout<<"("<<p2.x<<","<<p2.y<<")\t\t"<<c2<<"\t\t";
    cout<<"("<<pm.x<<","<<pm.y<<")\t\t"<<cm<<"\t\n";
    //cout<<"("<<p1.x<<","<<p1.y<<")\t"<<c1<<"\t";
    return;
}
point v1(30,20),v2(50,0),v3(70,40),v4(50,60);
void clipline(point q1,point q2){
    int cq1=0x0,cq2=0x0;
    cq1=gencode(q1);
    cq2=gencode(q2);
    if(cq1==0&&cq2==0){
      line(q1.x,q1.y,q2.x,q2.y);
      return;
    }
    if(cq1&cq2!=0) return;
    point qm((q1.x+q2.x)/2,(q1.y+q2.y)/2);
    int cqm=gencode(qm);
    ptable(q1,q2,qm,cq1,cq2,cqm);
    if((qm.x==q1.x&&qm.y==q1.y)||(qm.x==q2.x&&qm.y==q2.y))
        return ;
    if(cqm!=0){
        if((cq1&cqm)!=0){
            clipline(qm,q2);
            //cout<<(cq1&cqm)<<endl;
        }
        else if((cq2&cqm)!=0){
            clipline(q1,qm);
        }
    }
    else if(cqm==0){
        if(cq1==0){
            line(q1.x,q1.y,qm.x,qm.y);
            clipline(qm,q2);
        }
        else if(cq2==0){
            line(q2.x,q2.y,qm.x,qm.y);
            clipline(qm,q1);
        }
        else{
           clipline(q1,qm);
           clipline(qm,q2);
        }
    }
}
int main()
{
	int gdriver=DETECT, gmode, error;
	initgraph(&gdriver, &gmode, "");

	point q1(20,40),q2(80,70);
	line(v1.x,v1.y,v2.x,v2.y);
	line(v2.x,v2.y,v3.x,v3.y);
	line(v3.x,v3.y,v4.x,v4.y);
	line(v4.x,v4.y,v1.x,v1.y);
	//line(q1.x,q1.y,q2.x,q2.y);
	//drawline(v1.x,v1.y,v2.x,v2.y);
    cout<<"q1\t\tcodep1\t\tq2\t\tcodeq2\t\tqm\t\tcodeqm\t\n";
    clipline(q1,q2);
    getch();
	return 0;
}
