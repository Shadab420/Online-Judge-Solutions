#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int prime[1000005/32];
int Eu_phi[1000005];

bool check(int ind, int pos) {return ind & (1<<pos);}
int setBit(int ind, int pos) {return ind |= (1<<pos);}

void Euler_Phi()
{
    for(int i=1; i<=1000005; i++) Eu_phi[i] = i;
    for(int i=2; i<=1000; i++)
    {
        if(check(prime[i>>5], i&31) == 0)
        {
            Eu_phi[i] = i-1;
            for(int j=i+i; j<=1000005; j+=i)
            {
                Eu_phi[j] -= Eu_phi[j]/i;
                prime[j>>5] = setBit(prime[j>>5], j&31);
            }
        }
    }
}


int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    Euler_Phi();
    //for(int i=2; i<=1000000; i++) cout << Eu_phi[i] << endl;
    int t,n,lucky[10001]; read(t);
    long long int ans;

    for(int cs=1; cs<=t; cs++)
    {
        read(n);
        ans = 0;
        for(int i=0; i<n; i++) read(lucky[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=lucky[i]+1; j<=1000005; j++)
            {
                if(Eu_phi[j] >=lucky[i])
                {
                    ans+=j; break;
                }
            }
        }
        printf("Case %d: %lld Xukha\n", cs, ans);
    }

    return 0;
}
