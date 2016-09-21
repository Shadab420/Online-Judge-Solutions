#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text;

    while(getline(cin,text))
    {
        map<char,int>charFreq;
        int maxx = INT_MIN;

        for(int i=0; i<text.length(); i++)
        {
            if(isalpha(text[i]))
            {
                charFreq[text[i]]++;
                maxx = max(maxx, charFreq[text[i]]);
            }
        }

        for(int i=65; i<=122; i++)
        {
            if(charFreq[(char)i] == maxx) cout << (char)i;
        }
        cout << " " << maxx << endl;
    }

    return 0;
}
