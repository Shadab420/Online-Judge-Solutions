#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

map<int,string> dotMap;


int main()
{
    int t,a,b; read(t);

    dotMap[1] = "Yakk";
    dotMap[2] = "Doh";
    dotMap[3] = "Seh";
    dotMap[4] = "Ghar";
    dotMap[5] = "Bang";
    dotMap[6] = "Sheesh";

    for(int cs=1; cs<=t; cs++)
    {
        read(a); read(b);
        cout << "Case " << cs << ": ";
        if(a==1 && b==1)
        {
            cout << "Habb Yakk\n";
        }

        else if(a==2 && b==2)
        {
            cout << "Dobara\n";

        }

        else if(a==3 && b==3)
        {
            cout << "Dousa\n";

        }

        else if(a==4 && b==4)
        {
            cout << "Dorgy\n";

        }

        else if(a==5 && b==5)
        {
            cout << "Dabash\n";

        }
        else if(a==5 && b==6)
        {
            cout << "Sheesh Beesh\n";

        }

        else if(a==6 && b==5)
        {
            cout << "Sheesh Beesh\n";

        }
        else if(a==6 && b==6)
        {
            cout << "Dosh\n";

        }
        else cout << dotMap[max(a,b)] << " " << dotMap[min(a,b)] << endl;

    }



    return 0;
}
