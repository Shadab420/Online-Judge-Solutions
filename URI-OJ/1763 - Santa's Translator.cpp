#include <bits/stdc++.h>

using namespace std;

string countries[24] = {"brasil","alemanha","austria","coreia","espanha","grecia","estados-unidos",
                        "inglaterra","australia","portugal","suecia","turquia","argentina","chile","mexico","antardida","canada",
                        "irlanda","belgica","italia","libia","siria","marrocos","japao"};

map<string,string>m;

bool exist(string country)
{
    for(int i=0; i<24; i++)
    {
        if(countries[i] == country) return true;
    }
    return false;
}

int main()
{


    m.insert(make_pair("brasil","Feliz Natal!"));
    m.insert(make_pair("alemanha","Frohliche Weihnachten!"));
    m.insert(make_pair("austria","Frohe Weihnacht!"));
    m.insert(make_pair("coreia","Chuk Sung Tan!"));
    m.insert(make_pair("espanha","Feliz Navidad!"));
    m.insert(make_pair("grecia","Kala Christougena!"));
    m.insert(make_pair("estados-unidos","Merry Christmas!"));
    m.insert(make_pair("inglaterra","Merry Christmas!"));
    m.insert(make_pair("australia","Merry Christmas!"));
    m.insert(make_pair("portugal","Feliz Natal!"));
    m.insert(make_pair("suecia","God Jul!"));
    m.insert(make_pair("turquia","Mutlu Noeller"));
    m.insert(make_pair("argentina","Feliz Navidad!"));
    m.insert(make_pair("chile","Feliz Navidad!"));
    m.insert(make_pair("mexico","Feliz Navidad!"));
    m.insert(make_pair("antardida","Merry Christmas!"));
    m.insert(make_pair("canada","Merry Christmas!"));
    m.insert(make_pair("irlanda","Nollaig Shona Dhuit!"));
    m.insert(make_pair("belgica","Zalig Kerstfeest!"));
    m.insert(make_pair("italia","Buon Natale!"));
    m.insert(make_pair("libia","Buon Natale!"));
    m.insert(make_pair("siria","Milad Mubarak!"));
    m.insert(make_pair("marrocos","Milad Mubarak!"));
    m.insert(make_pair("japao","Merii Kurisumasu!"));

    string country;

    while(cin >> country)
    {
        if(!exist(country)) cout << "--- NOT FOUND ---\n";
        else cout << m[country] << endl;
    }


    return 0;
}
