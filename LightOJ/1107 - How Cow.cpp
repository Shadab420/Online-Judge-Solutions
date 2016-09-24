#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t,x1,x2,y1,y2,M,a,b;
    string result="";
    cin >> t;

    for(int i=1; i<=t; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> M;

        while(M>0)
        {
            cin >> a >> b;

            if((a >= x1 && a<=x2) && (b >= x1 && b <= y2))
            {
                result+="Yes\n";
            }
            else result+="No\n";

            M--;
        }

        cout << "Case " << i << ":\n";
        cout << result;
        result = "";

    }



    return 0;
}
