#include <bits/stdc++.h>
using namespace std;

struct pairr
{
    char c;
    int freq;
};

bool comp(pairr p1, pairr p2)
{
    if(p1.freq > p2.freq) return true;
    else if(p1.freq == p2.freq)
    {
        if((int)p1.c < (int)p2.c) return true;
        else return false;
    }
    else return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n; cin >> n; cin.ignore();
    char s[1000];
    vector<pairr>v;

    map<char,int>m;
    m.insert(make_pair('A',0)); m.insert(make_pair('B',1)); m.insert(make_pair('C',2)); m.insert(make_pair('D',3));
    m.insert(make_pair('E',4)); m.insert(make_pair('F',5)); m.insert(make_pair('G',6)); m.insert(make_pair('H',7));
    m.insert(make_pair('I',8)); m.insert(make_pair('J',9)); m.insert(make_pair('K',10)); m.insert(make_pair('L',11));
    m.insert(make_pair('M',12)); m.insert(make_pair('N',13)); m.insert(make_pair('O',14)); m.insert(make_pair('P',15));
    m.insert(make_pair('Q',16)); m.insert(make_pair('R',17)); m.insert(make_pair('S',18)); m.insert(make_pair('T',19));
    m.insert(make_pair('U',20)); m.insert(make_pair('V',21)); m.insert(make_pair('W',22)); m.insert(make_pair('X',23));
    m.insert(make_pair('Y',24)); m.insert(make_pair('Z',25));


    for(int i=1; i<=n; i++)
    {
        gets(s);

        for(int i=0; i<26; i++)
        {
            pairr p;
            p.c = (char)(i+65);
            p.freq = 0;
            v.push_back(p);
        }


        for(int i=0; i<strlen(s); i++)
        {
           if(isalpha(s[i]))
            {
                s[i] = toupper(s[i]);
                v[m[s[i]]].freq++;

            }
        }
    }

    sort(v.begin(), v.end(), comp);

    for(int i=0; i<26; i++)
    {
        if(v[i].freq > 0) cout << v[i].c << " " << v[i].freq << endl;
    }

    return 0;
}
