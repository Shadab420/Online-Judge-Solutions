#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    string d,n;
    while(cin>>d>>n)
    {
        if(d=="0" && n=="0") break;

        int dInd = n.find(d);
        while(dInd != string::npos)
        {
            n.replace(dInd,1,"");
            dInd = n.find(d);
        }

        if(n.length()==0) printf("0\n");
        else
        {
            if(n[0] == '0')
            {
                int i=0;
                while(n[i] == '0') i++;
                n.replace(0,i,"");
            }
            if(n.length()==0) printf("0\n");
            else cout << n << "\n";
        }
    }

    return 0;
}
