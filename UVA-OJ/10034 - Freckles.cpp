#include <bits/stdc++.h>
using namespace std;
#define readInt(num) scanf("%d", &num);
#define readDouble(num) scanf("%lf", &num)

struct Point
{
    double x, y;
};

struct Edge
{
    int p1, p2;
    double distance;
    bool operator < (const Edge& e) const {return distance < e.distance;}
};

int parent[101];
map<int,Point>pointMap;
vector<Edge>edges;

int findd(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = findd(parent[x]);
}

double kruskal(int noOfFreckles)
{
    for(int i=1; i<=noOfFreckles; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
//    for(int i=0; i<edges.size(); i++)
//    {
//        cout << edges[i].p1 << ", " << edges[i].p2 << " - " << edges[i].distance << endl;
//    }
    int edgCnt = 0;
    double dist = 0.0;

    for(int i=0; i<edges.size(); i++)
    {
        int parent1 = findd(edges[i].p1);
        int parent2 = findd(edges[i].p2);

        //cout << parent1 << " " << parent2 << endl;

        if(parent1 != parent2)
        {
            parent[parent1] = parent2;
            dist+=edges[i].distance;
            edgCnt++;
            //cout  << dist << endl;
        }
        if(edgCnt == noOfFreckles-1) break;
    }
    return dist;
}


int main()
{
    int t, noOfFreckles; readInt(t);
    double a, b;

    for(int cs=1; cs<=t; cs++)
    {
        if(cs > 1) printf("\n");

        readInt(noOfFreckles);

        Point p;
        for(int i=1; i<=noOfFreckles; i++)
        {
            readDouble(a);
            readDouble(b);
            p.x = a;
            p.y = b;
            pointMap[i] = p;
        }

        Edge edg;
        for(int i=1; i<noOfFreckles; i++)
        {
            for(int j=i+1; j<=noOfFreckles; j++)
            {
                edg.p1 = i;
                edg.p2 = j;
                edg.distance = sqrt(((pointMap[i].x - pointMap[j].x)*(pointMap[i].x - pointMap[j].x)) + ((pointMap[i].y - pointMap[j].y)*(pointMap[i].y - pointMap[j].y)));
                edges.push_back(edg);
            }
        }

        double ans = kruskal(noOfFreckles);
        printf("%0.2f\n", ans);
        pointMap.clear();
        edges.clear();
    }

    return 0;
}
