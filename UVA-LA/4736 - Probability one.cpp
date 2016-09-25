#include <iostream>

using namespace std;

int main()
{
    int n,c=0;

    while(cin >> n)
    {
        if(n == 0) break;
        c++;

        cout << c << ". ";

        n *= 3;

        if(n%2 == 0)
        {
            cout << "even ";
            n/=2;
        }
        else
        {
            cout << "odd ";
            n = (n+1)/2;
        }
        n *=3;
        n/=9;
        cout << n << endl;
    }

    return 0;
}
