#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("i.txt","r",stdin);
    int t; cin >> t;
    string mainStr, part1, part2;
    cin.ignore();

    for(int i=1; i<=t; i++)
    {
        getline(cin,mainStr);
        part1 = mainStr.substr(0,mainStr.length()/2);
        part2 = mainStr.substr(mainStr.length()/2);
        mainStr = "";

        for(int j=part1.length()-1; j>=0; j--)
        {
            mainStr+=part1.substr(j,1);
        }
        for(int j=part2.length()-1; j>=0; j--)
        {
            mainStr+=part2.substr(j,1);
        }
        cout << mainStr << endl;

    }

    return 0;
}
