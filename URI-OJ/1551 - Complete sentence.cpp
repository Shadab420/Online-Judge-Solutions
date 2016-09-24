#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("i.txt","r",stdin);
    int t,c; cin >> t; cin.ignore();
    string s;

    for(int i=1; i<=t; i++)
    {
        getline(cin,s);

        size_t ind[30];

        ind[0] = s.find("a");
        ind[1] = s.find("b");
        ind[2] = s.find("c");
        ind[3] = s.find("d");
        ind[4] = s.find("e");
        ind[5] = s.find("f");
        ind[6] = s.find("g");
        ind[7] = s.find("h");
        ind[8] = s.find("i");
        ind[9] = s.find("j");
        ind[10] = s.find("k");
        ind[11] = s.find("l");
        ind[12] = s.find("m");
        ind[13] = s.find("n");
        ind[14] = s.find("o");
        ind[15] = s.find("p");
        ind[16] = s.find("q");
        ind[17] = s.find("r");
        ind[18] = s.find("s");
        ind[19] = s.find("t");
        ind[20] = s.find("u");
        ind[21] = s.find("v");
        ind[22] = s.find("w");
        ind[23] = s.find("x");
        ind[24] = s.find("y");
        ind[25] = s.find("z");

        c = 0;
        for(int j=0; j<26; j++)
        {
            if(ind[j] != string::npos) c++;
        }

        if(c == 26) cout << "frase completa\n";
        else if(c >= 13 && c<=25) cout << "frase quase completa\n";
        else cout << "frase mal elaborada\n";

    }

    return 0;
}
