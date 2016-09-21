#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int t,n; cin >> t;
    map<int,int>m;

    for(int i=1; i<=t; i++)
    {
        cin >> n;
        m.clear();
        for(int j=1; j<=n; j++)
        {
            int temp = j;
            while(temp>0)
            {
                m[temp%10]++;
                temp/=10;
            }
        }
        for(int j=0; j<10; j++)
        {
            cout << m[j];
            if(j < 9) cout << " ";
        }
        cout << endl;


    }

    return 0;
}
