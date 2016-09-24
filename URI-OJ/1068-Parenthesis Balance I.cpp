#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);

    char s[1005];
    map<char,int>m;

    while(cin >> s)
    {

        m.clear();

        if(s[0] == '\0' || s[0] == '\n')
        {
            cout << "Yes\n";
        }
        else
        {


            for(int i=0; i<strlen(s); i++)
            {
                if(s[i] == '(')
                {
                    m['(']++;
                }
                else if(s[i] == ')')
                {
                    if(m['('] > 0) m['(']--;
                    else
                    {
                        m[')']++;
                    }

                }

            }
            if(m['('] == 0 && m[')'] == 0 && m['['] == 0 && m[']'] == 0) cout << "correct\n";
            else cout << "incorrect\n";


        }


    }

    return 0;
}

