#include <bits/stdc++.h>
using namespace std;

string s,ans;
int r,len;
bool taken[30];

void comb()
{
    if(ans.length() == r)
    {
        cout << ans << endl;
        return;
    }

    for(int i=0; i<len; i++)
    {
        if(ans != "" && ans[ans.length()-1]>s[i])  continue;

        if(!taken[i])
        {

            ans+=s.substr(i,1);
            taken[i] = true;
            comb();
            ans.erase(ans.length()-1, 1);
            taken[i] = false;
            while(s[i]==s[i+1]) i++;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);


    while(cin >> s >> r)
    {
        len = s.length();
        ans = "";
        sort(s.begin(), s.end());
        comb();
    }

    return 0;
}
