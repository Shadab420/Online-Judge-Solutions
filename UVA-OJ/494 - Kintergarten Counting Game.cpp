#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    char s[1000];
    while(gets(s))
    {

        int cnt = 0, len = strlen(s);
        for(int i=0; i<len; i++)
        {
            if(!isalpha(s[i]))
            {
                if(isalpha(s[i-1])) cnt++;
            }
            else if(i== len-1 && isalpha(s[i])) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
