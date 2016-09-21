#include <bits/stdc++.h>

using namespace std;

long long int c;

int main()
{
    freopen("in.txt", "r", stdin);

    signed long long int a,acpy,l,cs=0;

    while(cin >> a >> l)
    {
        if(a<0 && l<0) break;
        cs++;
        acpy=a;
        for(c=0; ; c++)
        {
            if(a==1) break;
            else if(a%2==0) a/=2;
            else if(a%2==1) a = a*3 +1;
            if(a>l) break;
        }
        cout << "Case " << cs << ": A = " << acpy <<", limit = " << l << ", number of terms = " << c+1 << endl;
    }

    return 0;
}
