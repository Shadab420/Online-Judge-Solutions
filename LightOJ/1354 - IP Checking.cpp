#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t,dec1,dec2,dec3,dec4,bin1,bin2,bin3,bin4;
    char dot;
    long long int binary;

    cin >> t;

    for(int i=1; i<=t; i++)
    {
        cin >> dec1 >> dot >> dec2 >> dot >> dec3 >> dot >> dec4;
        cin >> bin1 >> dot >> bin2 >> dot >> bin3 >> dot >> bin4;

        if(bin1 == atoi(bitset<8>(dec1).to_string().c_str())
           && bin2 == atoi(bitset<8>(dec2).to_string().c_str())
           && bin3 == atoi(bitset<8>(dec3).to_string().c_str())
            && bin4 == atoi(bitset<8>(dec4).to_string().c_str())) cout << "Case " << i << ": " << "Yes\n";
        else cout << "Case " << i << ": "  "No\n";
    }


    return 0;
}
