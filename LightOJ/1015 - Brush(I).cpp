#include <iostream>
using namespace std;

int main()
{
        int t,n,sum,x; cin >> t;

        for(int i=1; i<=t; i++)
        {

            cin >> n;
            sum = 0;

            while(n>0)
            {

                cin >> x;
                if(x > 0) sum += x;

                n--;
            }

            cout << "Case " << i << ": " << sum << endl;;
        }

    return 0;
}
