#include <graphics.h>
#include <iostream>
#include <bits/stdc++.h>
#include<DDA_line.h>
using namespace std;

pair<int, int> P1;
pair<int, int> P2;
pair<int, int> P3;
pair<int, int> P4;

pair<int, int> operator+(const pair<int, int> p1, const pair<int, int> p2)
{
    pair<int, int> ans = make_pair(p1.first + p2.first, p1.second + p2.second);
    return ans;
}

pair<int, int> operator-(const pair<int, int> p1, const pair<int, int> p2)
{
    pair<int, int> ans = make_pair(p1.first - p2.first, p1.second - p2.second);
    return ans;
}

pair<int, int> operator*(double t, const pair<int, int> p)
{
    pair<int, int> ans = make_pair((int)(t * p.first), (int)(t * p.second));
    return ans;
}

pair<int, int> getNormal(pair<int, int> edge)
{
    pair<int, int> normal = make_pair( abs(edge.first), abs(edge.second));
    int x = edge.first;
    int y = edge.second;
    if(x > 0 && y > 0)
    {
        normal.first = -normal.first;
        normal.second = normal.second;
    }
    else if(x < 0 && y > 0)
    {
        normal.first = -normal.first;
        normal.second = -normal.second;
    }
    else if(x < 0 && y < 0)
    {
        normal.first = normal.first;
        normal.second = -normal.second;
    }
    else
    {
        normal.first = normal.first;
        normal.second = normal.second;
    }

    return normal;
}

double dotP(pair<int, int> p1, pair<int, int> p2)
{
    return 1.0 * (p1.first * p2.first + p1.second * p2.second);
}

double generateT(pair<int, int> vector, pair<int, int> P, pair<int, int> P1, pair<int, int> P2)
{
    pair<int, int> normal = getNormal(vector);
    double denom = (-1.0) * dotP(normal, P2 - P1);
    if (denom == 0.0)
    {
        return INT_MAX;
    }
    double num = dotP(normal, P1 - P);
    return num / denom;
}

void linecustom(pair<int, int> p1, pair<int, int> p2)
{
    DDA(p1.first, p1.second, p2.first, p2.second,RED);
}

int main()
{
    int n;
    cout << "Enter number of points : ";
    cin >> n;

    pair<int, int> arr[n];
    cout << "Enter the points\n";
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }

   initwindow(1300,768);

    pair<int, int> vectors[n];
    for (int i = 0; i < n; i++)
    {
        vectors[i] = arr[(i + 1) % n] - arr[i];
        DDA(arr[(i + 1) % n].first, arr[(i + 1) % n].second,  arr[i].first, arr[i].second, RED);
    }

    cout << "Enter coordinates of subject polygon : ";
    cin >> P1.first >> P1.second >> P2.first >> P2.second >> P3.first >> P3.second >> P4.first >> P4.second;

    // linecustom(P1, P2);
    // delay(3000);

    double t1 = INT_MAX;
    double t2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        double t = generateT(vectors[i], arr[i], P1, P2);
        cout<<"t : "<<t<<endl;
        if (t >= 0 && t <= 1)
        {
            if (t1 == INT_MAX)
            {
                t1 = t;
            }
            else if (t2 == INT_MAX)
                t2 = t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        double t = generateT(vectors[i], arr[i], P2, P3);
        cout<<"t : "<<t<<endl;
        if (t >= 0 && t <= 1)
        {
            if (t1 == INT_MAX)
            {
                t1 = t;
            }
            else if (t2 == INT_MAX)
                t2 = t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        double t = generateT(vectors[i], arr[i], P3, P4);
        cout<<"t : "<<t<<endl;
        if (t >= 0 && t <= 1)
        {
            if (t1 == INT_MAX)
            {
                t1 = t;
            }
            else if (t2 == INT_MAX)
                t2 = t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        double t = generateT(vectors[i], arr[i], P4, P1);
        cout<<"t : "<<t<<endl;
        if (t >= 0 && t <= 1)
        {
            if (t1 == INT_MAX)
            {
                t1 = t;
            }
            else if (t2 == INT_MAX)
                t2 = t;
        }
    }

    if (t1 < t2)
    {
        cout<<"jdbvjdbvjv\n";
        //linecustom(P1 + t1 * (P2 - P1), P1 + t2 * (P2 - P1));
      //  DDA((P1 + t1 * (P2 - P1)).first, (P1 + t1 * (P2 - P1)).second, (P1 + t2 * (P2 - P1)).first, (P1 + t2 * (P2 - P1)).second, BLUE);
    }
    else
    {
      //  DDA(P1.first, P1.second, P2.first, P2.second, BLUE);
    }

    getch();

    return 0;
}
