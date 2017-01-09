///Verdict: AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[20];

    while(cin>>s)
    {
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i] == ',') s[i] = ' ';
        }
        printf("%s\n", s);
    }

    return 0;
}
