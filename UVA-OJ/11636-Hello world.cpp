#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    for(int cs = 1;; cs++)
    {
        cin >> n;
        if (n < -1) break;

        n -= 1;
        int moves = 0;
        while (n > 0)
        {
            n = n >> 1;
            cout << n << endl;
            moves += 1;
        }
        cout << "Case " << cs << ": " << moves << endl;
    }

    return 0;
}
