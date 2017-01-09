///Verdict: AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[101];

    while(scanf("%s", s) != EOF)
    {
        int len = strlen(s);

        int frequency[26] = {0};

        for(int i=0; i<len; i++) frequency[s[i] - 'a']++;

        bool beautiful = true;

        for(int i=0; i<26; i++)
        {
            if(frequency[i] % 2!=0)
            {
                beautiful = false;
                break;
            }
        }

        if(beautiful) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
