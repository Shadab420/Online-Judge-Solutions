#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long int n,t; cin >> t;


    for(int cs=1; cs<=t; cs++)
    {

    cin >> n;

    if(n==0 || n==1)
    {
        cout << n << endl; continue;//return 0;
    }

    long long int ncpy = n;
    vector<int>v;
    int notdiv=0;
    unsigned long long int result,calc=1, sz;


    while(ncpy>1 && notdiv != 8)
    {
        notdiv = 0;
        for(int i=9; i>=2; i--)
        {
            if(ncpy%i==0)
            {
                ncpy/=i;
                v.push_back(i);
                calc*=i;
                break;
            }
            else notdiv++;
        }

    }



    if(ncpy>1 && ncpy<10)
    {
        v.push_back(ncpy); calc*=ncpy;
        if(calc != n)
        {
            cout << -1 << endl; continue;//return 0;
        }
    }
    else if(ncpy>=10)
    {
        cout << -1 << endl; continue;//return 0;
    }


    //for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    //cout << endl;

    sort(v.begin(),v.end());

    sz = v.size();

    for(int i=0; i<sz; i++)
    {

        if(i==0)
        {
            result = v[i];
        }
        else
        {
            result*=10;
            result += v[i];
        }
    }

    cout << result << endl;
    }


    return 0;
}

