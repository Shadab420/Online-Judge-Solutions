#include <bits/stdc++.h>
using namespace std;

vector<char>ans;
int t,totalChar;
char var,var1,var2;
map<char,int>m;
map<int,char>revMap;
int rulesMat[30][30];
bool foundOrder,invalidRule,taken[30];

void getComb()
{
    if(ans.size() == totalChar)
    {
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=i+1; j<ans.size(); j++)
            {
                if(rulesMat[m[ans[i]]][m[ans[j]]] == -1)
                {
                    return;
                }
            }
        }

        for(int i=0; i<ans.size(); i++)
        {
            cout << ans[i];
            if(i<ans.size()-1) cout << " ";
        }
        cout << endl;
        foundOrder = true;
        return;
    }

    for(int i=0; i<totalChar; i++)
    {

        if(!taken[i])
        {
            ans.push_back(revMap[i]);
            taken[i] = true;
            getComb();
            ans.pop_back();
            taken[i] = false;
        }

    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        totalChar = 0;
        m.clear(); revMap.clear();
        memset(rulesMat,0,sizeof rulesMat);
        while(cin >> var)
        {
            if(var == ' ') continue;
            if(isalpha(var))
            {
                m[var] = totalChar;
                revMap[totalChar] = var;
                totalChar++;
                if(cin.peek() == '\n') break;
            }

        }

        invalidRule = false;

        while(cin >> var1 && cin>>var && cin >> var2)
        {

            if(var1 == ' ') continue;
            if(rulesMat[m[var1]][m[var2]] == -1)
            {
                invalidRule = true;
                break;
            }
            rulesMat[m[var1]][m[var2]] = 1;
            rulesMat[m[var2]][m[var1]] = -1;
            for(int i=0; i<totalChar; i++)
            {
                if(i != m[var1] && rulesMat[i][m[var1]] == 1)
                {
                    if(rulesMat[m[i]][m[var2]] == -1)
                    {
                        invalidRule = true;
                        break;
                    }
                    rulesMat[i][m[var2]] = 1;
                    rulesMat[m[var2]][i] = -1;
                }
            }
            if(cin.peek()=='\n') break;
        }

        foundOrder = false;
        if(!invalidRule)
        {

            memset(taken,false,sizeof taken);
            ans.clear();
            getComb();
        }

        if(!foundOrder) cout << "NO\n";
        if(cs < t) cout << endl;

    }

    return 0;
}
