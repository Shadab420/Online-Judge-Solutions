#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n,m,curr; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n >> m;

        if(n==1 || m==0)
        {
            cout << "Yes\n"; continue;
        }

        int IRev[50][50];


        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> curr;
                IRev[j][i] = curr;

            }
        }





        bool repeated = false;
        bool invalid = false;

        int g[50][50] = {0},a,b;

        for(int i=0; i<m; i++)
        {
            int c=0;
            for(int j=0; j<n; j++)
            {
                if(IRev[i][j] == 1)
                {
                    c++;
                    if(c>2)
                    {
                        cout << "No\n";
                        invalid = true;
                        break;
                    }
                    else if(c == 1) a = j;
                    else if(c == 2)
                    {
                        b = j;
                        if(g[a][b] == 0) g[a][b] = 1;
                        else
                        {
                            cout << "No\n";
                            invalid = true;
                            break;
                        }
                    }

                }


            }
            if(invalid) break;
            else if(c<2)
            {
                cout << "No\n";
                invalid = true;
                break;

            }


        }
        if(!invalid) cout << "Yes\n";


    }

    return 0;
}
