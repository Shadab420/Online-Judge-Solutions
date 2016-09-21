#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t; cin >> t;
    long long int n,rev_n,result;
    string rev,pal;


    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;
        int iteration = 0;
        while(1)
        {
            stringstream ss1,ss2;
            ss1<<n;
            rev = ss1.str();
            rev = string(rev.rbegin(), rev.rend());
            ss1.str("");
            ss1 << rev;
            ss1 >> rev_n;
            ss1.str("");

            result = n+rev_n;

            ss2 << result;
            pal = ss2.str();

            if (pal == string(pal.rbegin(),pal.rend()))
            {
                cout << iteration+1 << " " << pal << endl;
                break;
            }
            else
            {
                iteration++;
                n = result;
            }
        }
    }

    return 0;
}
