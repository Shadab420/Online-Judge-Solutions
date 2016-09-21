#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int phi[50001];

void Euler_Phi()
{
    for(int i=1; i<=50000; i++) phi[i] = i;
    for(int i=2; i<=50000; i++)
    {
        if(phi[i] == i)
        {
            for(int j=i; j<=50000; j+=i) phi[j] -= phi[j]/i;
        }
    }
    for(int i=2; i<=50000; i++) phi[i]*=2;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    Euler_Phi();
    //for(int i=1; i<=10; i++) cout << phi[i] << endl;
    int n,sum;
    while(read(n)!=EOF)
    {
        if(n==0) break;
        sum=0;
        for(int i=1; i<=n; i++) sum+=phi[i];
        printf("%d\n", sum);
    }

    return 0;
}
