#include <bits/stdc++.h>
using namespace std;

vector<int>primes;

void sieve()
{
    bool prime[524300];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=524300; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=524300; i += p) prime[i] = false;
        }
    }

    for (int p=2; p<524300; p++)
    {
        if (prime[p]) primes.push_back(p);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    sieve();
    long long int g;

    while(cin >> g)
    {
        if(g == 0) break;
        if(g<0)
        {
            cout << g << " = " << -1 << " x ";
            g*=(-1);

        }
        else
        {
            cout << g << " = ";
        }


        int i=0;
        while(g>1)
        {
            if(g%primes[i] == 0)
            {
                cout << primes[i];
                g/=primes[i];

                if(g > 1)
                {
                    cout << " x ";
                }
                else
                {
                    cout << endl;
                    break;
                }

            }
            else
            {
                i++;

                if(i>=primes.size() || primes[i] > g)
                {
                    break;
                }
            }
        }
        if(g>1) cout << g << endl;
    }

    return 0;
}
