#include <bits/stdc++.h>

using namespace std;

bool maxLength(string s1, string s2)
{
    return s1.length() > s2.length();
}

int main()
{
    freopen("i.txt","r",stdin);
    int t; cin >> t; cin.ignore();

    vector<string>v;
    string s;

    while(t>0)
    {

        getline(cin,s);



        size_t index = s.find(" ");

        while(index != string::npos)
        {
            string part = s.substr(0,index);
            v.push_back(part);
            s.erase(0,index+1);
            index = s.find(" ");
        }

        v.push_back(s);

        stable_sort(v.begin(),v.end(),maxLength);

        for(int i=0; i<v.size(); i++)
        {
            cout << v[i];
            if(i<v.size()-1) cout << " ";
        }

        cout << endl;

        v.clear();

        t--;
    }

    return 0;
}
