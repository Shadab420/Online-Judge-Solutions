#include <bits/stdc++.h>
using namespace std;

#define ri(num) scanf("%d", &num)
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

struct Problem
{
    int m;
    char id;
    string verdict;
};

bool cmp(Problem p1, Problem p2)
{
    if((int)p1.id < (int)p2.id) return true;
    return false;
}

int main()
{
    //fin; fout;

    vector<Problem>problems;
    map<char,int>wrongTry;

    Problem p;
    int solved = 0, totalTime=0;

    while(ri(p.m) != EOF)
    {
        if(p.m == -1)
        {
            for(int i=0; i<problems.size(); i++)
            {
                if(problems[i].verdict == "right")
                {
                    totalTime += problems[i].m + wrongTry[problems[i].id] * 20;
                }
            }
            printf("%d %d\n", solved,totalTime);
            solved = 0;
            totalTime = 0;
            problems.clear();
            wrongTry.clear();
            continue;
        }

        cin>>p.id;
        cin>>p.verdict;

        if(p.verdict == "right") solved++;
        if(p.verdict == "wrong") wrongTry[p.id]++;
        problems.push_back(p);

    }

    return 0;
}
