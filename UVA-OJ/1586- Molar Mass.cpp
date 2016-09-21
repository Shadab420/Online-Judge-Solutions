#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int t,n; cin >> t;
    char chemical[85];
    map<char,double>m;
    map<char,int>m1;
    double molarMass;

    m.insert(make_pair('C',12.010));
    m.insert(make_pair('H',1.008));
    m.insert(make_pair('O',16.000));
    m.insert(make_pair('N',14.010));

    int val = 1;
    for(int i=49; i<58; i++)
    {
        m1.insert(make_pair((char)i,val));
        val++;
    }



    for(int i=1; i<=t; i++)
    {
        cin >> chemical;
        molarMass = 0.000;
        int n;

        for(int j=0; j<strlen(chemical); j++)
        {
            n=0;

            if(isalpha(chemical[j]))
            {
                if(isdigit(chemical[j+1]))
                {
                    int k=j+1;

                    while(isdigit(chemical[k]))
                    {
                        if(n==0)
                        {
                            n = m1[chemical[k]];
                        }
                        else
                        {
                            n+=m1[chemical[k]];
                        }
                        k++;
                        if(isdigit(chemical[k])) n *= 10;
                    }

                    molarMass += m[chemical[j]] * n;
                }
                else molarMass = molarMass + m[chemical[j]];
            }


        }
        cout << fixed << setprecision(3) << molarMass<< endl;

    }

    return 0;
}
