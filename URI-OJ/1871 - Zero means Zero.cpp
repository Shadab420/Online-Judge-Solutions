#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("i.txt","r",stdin);
    long long int m,n,result;




    while(cin >> m >> n)
    {
        if(m == 0 && m == 0) break;
        result = m+n;
        stringstream ss;
        ss << result;
        string val = ss.str();

        size_t ind = val.find("0");

        while(ind != string::npos)
        {
            val.erase(ind,1);
            ind = val.find("0");
        }

        cout << val << endl;

    }

    return 0;
}
