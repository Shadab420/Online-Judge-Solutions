#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m,f=0;

    char c;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
        if(f>0) cout << endl;
        f++;

        int result[105][105] = {0};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> c;

                if(c == '*')
                {

                    result[i][j] = -1;

                    if(i-1 >= 0 && result[i-1][j] != -1) result[i-1][j]++;
                    if(i-1 >= 0 && j-1 >= 0 && result[i-1][j-1] != -1) result[i-1][j-1]++;
                    if(i-1 >= 0 && j+1 <= m-1 && result[i-1][j+1] != -1) result[i-1][j+1]++;
                    if(i+1 <= n-1 && result[i+1][j] != -1) result[i+1][j]++;
                    if(i+1 <= n-1 && j-1 >= 0 && result[i+1][j-1] != -1) result[i+1][j-1]++;
                    if(i+1 <= n-1 && j+1 <= m-1 && result[i+1][j+1] != -1) result[i+1][j+1]++;
                    if(j-1 >=0 && result[i][j-1] != -1) result[i][j-1]++;
                    if(j+1 <= m-1 && result[i][j+1] != -1) result[i][j+1]++;


                }
            }
        }

        cout << "Field #" << f <<":\n";

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(result[i][j] == -1) cout << '*';
                else cout << result[i][j];
            }
            cout << endl;
        }

    }



    return 0;
}
