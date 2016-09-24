#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int t; cin >> t;
    string a,b;
    map<string,int>m;
    long long int minop;

    m.insert(make_pair("a",1)); m.insert(make_pair("b",2)); m.insert(make_pair("c",3)); m.insert(make_pair("d",4)); m.insert(make_pair("e",5));
    m.insert(make_pair("f",6)); m.insert(make_pair("g",7)); m.insert(make_pair("h",8)); m.insert(make_pair("i",9)); m.insert(make_pair("j",10));
    m.insert(make_pair("k",11)); m.insert(make_pair("l",12)); m.insert(make_pair("m",13)); m.insert(make_pair("n",14)); m.insert(make_pair("o",15));
    m.insert(make_pair("p",16)); m.insert(make_pair("q",17)); m.insert(make_pair("r",18)); m.insert(make_pair("s",19)); m.insert(make_pair("t",20));
    m.insert(make_pair("u",21)); m.insert(make_pair("v",22)); m.insert(make_pair("w",23)); m.insert(make_pair("x",24)); m.insert(make_pair("y",25));
    m.insert(make_pair("z",26));

    for(int cs=1; cs<=t; cs++)
    {
        cin >> a >> b;
        if(a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            minop=0;
            for(int i=0; i<a.length(); i++)
            {
                if(a.substr(i,1) != b.substr(i,1))
                {
                    if(a.substr(i,1) == "z")
                    {
                        minop += m[b.substr(i,1)] % 26;
                    }
                    else if(m[a.substr(i,1)]+1 == m[b.substr(i,1)]) minop++;
                    else if(m[a.substr(i,1)] < m[b.substr(i,1)])
                    {
                        minop += (m[b.substr(i,1)] - m[a.substr(i,1)]);
                    }
                    else
                    {
                        minop += (26 - m[a.substr(i,1)]) + m[b.substr(i,1)] % 26;
                    }
                }
            }
            cout << minop << endl;
        }
   }

    return 0;
}
