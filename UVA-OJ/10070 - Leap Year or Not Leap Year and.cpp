#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%lld", &num)

void check(long long int year)
{
    int got = 0;
    if((year%4==0 && year%100==0) || year%400==0) { printf("This is leap year.\n"); got=1; }
    if(year%15==0) { printf("This is huluculu festival year.\n"); got=1; }
    if(year%55==0) { printf("This is bulukulu festival year.\n"); got=1; }
    if(got==0)printf("This is an ordinary year.\n");
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    long long int year,cs=0;
    while(read(year) != EOF)
    {
        if(cs >= 1) printf("\n");
        check(year); cs++;
    }

    return 0;
}
