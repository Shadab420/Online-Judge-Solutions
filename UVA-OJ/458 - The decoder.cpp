#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);

    char s[10000];

    while(gets(s))
    {
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i] == ' ') cout << " ";
            else cout << (char)(((int) s[i]) - 7);
        }
        cout << endl;
    }

    return 0;
}
