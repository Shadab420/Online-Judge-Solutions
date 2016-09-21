#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int t; cin >> t;
    string s;

    for(int i=1; i<=t; i++)
    {
        cin >> s;

        if(s == "1" || s == "4" || s == "78") cout << "+\n";
        else if(s.substr(s.length()-2) == "35") cout << "-\n";
        else if(s.substr(0,3) == "190") cout << "?\n";
        else if(s[0] == '9' && s[s.length()-1] == '4')cout << "*\n";
        else cout << "?\n";

    }

    return 0;
}
