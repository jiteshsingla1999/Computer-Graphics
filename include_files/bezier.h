
int lut[7][7] = {{1},           // n=0
            {1,1},          // n=1
           {1,2,1},         // n=2
          {1,3,3,1},        // n=3
         {1,4,6,4,1},       // n=4
        {1,5,10,10,5,1},    // n=5
       {1,6,15,20,15,6,1}};  // n=6
double Bezier(int n, double t, int *w)
{
  if(n==3)
  {

  double t2 = t * t;
  double mt = 1-t;
  double mt2 = mt * mt;
  return w[0]*mt2 + w[1]*2*mt*t + w[2]*t2;
  }

  double t2 = t * t;
  double t3 = t2 * t;
  double mt = 1-t;
  double mt2 = mt * mt;
  double mt3 = mt2 * mt;
  return w[0]*mt3 + 3*w[1]*mt2*t + 3*w[2]*mt*t2 + w[3]*t3;
}
void draw_curve(int n, int *w1, int *w2,int c)
{
    double t=0;
    while(t<=1)
    {
        double x = Bezier(4, t, w1);
        double y = Bezier(4, t, w2);
        putpixel(x,y,c);
        t+=0.0001;
    }
}