///Verdict: AC
#include <bits/stdc++.h>
using namespace std;

#define read(num1, num2, num3) scanf("%d %d %d", &num1, &num2, &num3)
typedef long long int lli;

int main()
{
    int a, b, c;
    while(read(a,b,c)!=EOF)
    {
        if(a+b+c == 17) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

