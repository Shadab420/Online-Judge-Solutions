#include <bits/stdc++.h>
using namespace std;

class StarClass
{
    public:
        double x,y;
        int parent;
        int rankk;
        int starId;

        StarClass(double a, double b, int id)
        {
            x = a; y = b; parent = id; rankk = 0, starId = id;
        }
};

vector<StarClass>star;

double distance(StarClass star1, StarClass star2)
{
    return sqrt((star1.x - star2.x) * (star1.x - star2.x) + (star1.y - star2.y) * (star1.y - star2.y));
}

int findd(StarClass st)
{
    if(st.parent == st.starId) return st.parent;
    else return st.parent = findd(star[st.parent]);
}

void unionn(int star1, int star2)
{
    int parent1 = findd(star[star1]);
    int parent2 = findd(star[star2]);

    if(star[parent1].rankk < star[parent2].rankk)
    {
        star[parent1].parent = parent2;
        star[parent2].rankk += 1;
    }
    else
    {
        star[parent2].parent = parent1;
        star[parent1].rankk += 1;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t,n; scanf("%d", &t);
    double d,x,y,dd;

    for(int cs = 1; cs <= t; cs++)
    {
        scanf("%d %lf", &n, &d);
        if(n == 0)
        {
            printf("Case %d: 0\n");
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                scanf("%lf %lf", &x, &y);

                StarClass s(x,y,i);
                star.push_back(s);
            }


            for(int i=0; i<star.size()-1; i++)
            {
                for(int j=i+1; j<star.size(); j++)
                {
                    double dis = distance(star[i],star[j]);

                    if(dis <= d) unionn(i,j);
                }
            }

            int cnt = 0;

            for(int i=0; i<star.size(); i++)
            {
                if(star[i].parent == star[i].starId) cnt++;
            }
            printf("Case %d: %d\n", cs,cnt);
        }
        star.clear();
    }


    return 0;
}
