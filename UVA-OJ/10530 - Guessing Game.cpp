#include <bits/stdc++.h>
using namespace std;

struct pairr
{
    int val;
    string indicator;
};

bool comp(pairr p1, pairr p2)
{
    if(p1.val <= p2.val) return true;
    else return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    pairr p, prev;
    bool cheating;
    vector<pairr>v;

    while(cin >> p.val)
    {
        if(p.val == 0 && prev.indicator == "right on") break;

        cin.ignore();
        getline(cin,p.indicator);
        cheating = false;


        if(p.indicator != "right on")
        {
            v.push_back(p);
        }
        else
        {
            v.push_back(p);

            sort(v.begin(),v.end(),comp);


            for(int i=0; i<v.size(); i++)
            {
                //cout << v[i].val << endl;
                for(int j= i+1; j<v.size(); j++)
                {
                    if(v[i].val < v[j].val)
                    {
                        if((v[j].val - v[i].val)<=1 && ((v[i].indicator == "too low" && v[j].indicator == "too high") || (v[i].indicator == "too high" && v[j].indicator == "too low")))
                        {
                            cheating = true;
                            break;
                        }
                        else if((v[i].indicator == "too high" || v[i].indicator == "right on") && (v[j].indicator == "too low" || v[j].indicator == "right on"))
                        {
                            cheating = true;
                            break;
                        }
                    }
                    else
                    {
                        if(v[i].indicator != v[j].indicator)
                        {
                            cheating = true;
                            break;
                        }
                    }
                }
                if(cheating) break;
            }
            //cout << endl;

            if(cheating) cout << "Stan is dishonest\n";
            else cout << "Stan may be honest\n";
            v.clear();
        }
    }



    return 0;
}
