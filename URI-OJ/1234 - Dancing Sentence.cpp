#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("i.txt", "r", stdin);
    char s[55];
    bool isUpper;

    while(gets(s))
    {
        isUpper = false;
        for(int i=0; i<strlen(s);)
        {
            if(s[i]==' ');
            else
            {
                if(isUpper)
                {
                    s[i] = tolower(s[i]);
                    isUpper = false;
                }
                else
                {
                    s[i] = toupper(s[i]);
                    isUpper = true;
                }

            }
            i++;

        }
        cout << s << endl;
    }



    return 0;
}
