#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    freopen("in.txt","r",stdin);
    int t; read(t);
    int a,b,cntDig,powOfTen;

    for(int i=1; i<=t; i++)
    {
        read(a); read(b);
        cntDig = b==0?1:log10(abs(b)) + 1;
        powOfTen = pow(10,cntDig);

        if(a%powOfTen == b) printf("encaixa\n");
        else printf("nao encaixa\n");
    }

    return 0;
}
