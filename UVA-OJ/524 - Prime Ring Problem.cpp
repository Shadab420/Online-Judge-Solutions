#include <bits/stdc++.h>
using namespace std;

int n;
bool prime[51];
vector<int>circles,ans;
bool taken[20];

void sieve(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=50; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=50; i += p)
                prime[i] = false;
        }
    }
}

void prepareRing()
{
    if(ans.size() == n)
    {
        for(int i=0; i<n; i++)
        {
            cout << ans[i];
            if(i<n-1) cout << " ";
        }
        cout << endl;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(ans.size()>0 && ans[0] != 1) continue;
        if(ans.size()>0 && !prime[ans[ans.size()-1] + circles[i]]) continue;
        if(ans.size() == n-1 && !prime[ans[0]+circles[i]]) continue;

        if(!taken[i])
        {
            ans.push_back(circles[i]);
            taken[i] = true;

            prepareRing();

            ans.pop_back();
            taken[i] = false;
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    sieve(50);
    int cs=0;

    while(cin >> n)
    {
        if(cs>0) cout << endl;
        cs++;
        memset(taken,false,sizeof taken);
        for(int i=1; i<=n; i++) circles.push_back(i);
        cout << "Case " << cs << ":\n";
        if(n==1) cout << 1 << endl;
        else prepareRing();

        circles.clear();
        ans.clear();
    }

    return 0;
}
