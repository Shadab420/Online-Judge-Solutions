#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    map<char,int>m;
    char c[30];

    m.insert(make_pair('A',2));
    m.insert(make_pair('B',2));
    m.insert(make_pair('C',2));
    m.insert(make_pair('D',3));
    m.insert(make_pair('E',3));
    m.insert(make_pair('F',3));
    m.insert(make_pair('G',4));
    m.insert(make_pair('H',4));
    m.insert(make_pair('I',4));
    m.insert(make_pair('J',5));
    m.insert(make_pair('K',5));
    m.insert(make_pair('L',5));
    m.insert(make_pair('M',6));
    m.insert(make_pair('N',6));
    m.insert(make_pair('O',6));
    m.insert(make_pair('P',7));
    m.insert(make_pair('Q',7));
    m.insert(make_pair('R',7));
    m.insert(make_pair('S',7));
    m.insert(make_pair('T',8));
    m.insert(make_pair('U',8));
    m.insert(make_pair('V',8));
    m.insert(make_pair('W',9));
    m.insert(make_pair('X',9));
    m.insert(make_pair('Y',9));
    m.insert(make_pair('Z',9));

    while(gets(c))
    {
        for(int i=0; i<strlen(c); i++)
        {
            if(c[i] != '-' && !isdigit(c[i])) cout << m[c[i]];
            else cout << c[i];
        }
        cout << endl;
    }





    return 0;
}
