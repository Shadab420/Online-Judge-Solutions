#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string n;
    map<string,int> m;
    m["0"] = 0;
    m["1"] = 1;
    m["2"] = 2;

    while(cin >> n)
    {
        if(n=="0") break;

        int len = n.length();

        int decimal=0;

        for(int i=0; i<len; i++)
        {
            string key = n.substr(i,1);
            decimal += ((int)pow(2,len-i)-1) * m[key];
        }
        cout << decimal << endl;

    }

    return 0;
}
