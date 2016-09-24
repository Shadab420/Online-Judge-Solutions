#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int prime[5000000/32];
unsigned long long int Eu_Phi[5000001];

bool check(int ind, int pos) {return ind & (1<<pos);}
int setBit(int ind, int pos) {return ind|=(1<<pos);}

void Euler_Phi()
{
    //memset(prime,true,sizeof prime);
    for(int i=1; i<=5000000; i++) Eu_Phi[i] = i;
    for(int i=2; i<=5000000; i++)
    {
        if(check(prime[i>>5],i&31) == 0)
        {
            Eu_Phi[i] = i-1;
            for(int j=i+i; j<=5000000; j+=i)
            {
                Eu_Phi[j] -= Eu_Phi[j]/i;
                prime[j>>5] = setBit(prime[j>>5], j&31);
            }
        }
    }
    for(int i=2; i<=5000000; i++)
    {
        Eu_Phi[i]*=Eu_Phi[i];
        Eu_Phi[i] += Eu_Phi[i-1];
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    Euler_Phi();
    /*for(int i=2; i<=10; i++)
    {
        if(check(prime[i>>5],i&31)==0) cout << i << endl;
    }*/
    int t,a,b; read(t);
    unsigned long long int sum, ep;

    for(int cs=1; cs<=t; cs++)
    {
        read(a); read(b);
        printf("Case %d: %llu\n", cs,Eu_Phi[b] - Eu_Phi[a-1]);
    }

    return 0;
}
