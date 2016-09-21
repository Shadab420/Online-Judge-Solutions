#include <iostream>
using namespace std;

int main()
{
    int t,c1,c2;

    cin >> t;

    for(int i=1; i<=t; i++)
    {
        cin >> c1 >> c2;
        cout << "Case "<< i << ": " << c1+c2 << endl;
    }

    return 0;
}
