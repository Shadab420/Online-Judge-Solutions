#include <bits/stdc++.h>
using namespace std;

bool comp(int x, int y)
{
    if(x>y) return true;
    return false;
}

int main()
{
    int n,s,cnt,mark;
    vector<int>marks;
    map<int,int>prevmap;

    cin >> n;

    while(n>0)
    {
        cin >> s;

        for (int i=0; i<s; i++)
        {
            cin >> mark;
            marks.push_back(mark);
            prevmap.insert(make_pair(mark,i));
        }

        sort(marks.begin(),marks.end(),comp);
        cnt=0;

        for(int i=0; i<marks.size(); i++)
        {
            if(prevmap[marks[i]] == i)cnt++;
        }
        cout << cnt << endl;
        marks.clear();
        prevmap.clear();

        n--;
    }


    return 0;
}
