#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,term1,term2,finall,attendence,ct[3]; cin >> t;
    double sum,avg;
    for(int cs=1; cs<=t; cs++)
    {
        cin >> term1 >> term2 >> finall >> attendence >> ct[0] >> ct[1] >> ct[2];
        sum = 0.0;
        sort(ct, ct+3);
        avg = (ct[1]+ct[2])/2;
        sum += term1+term2+finall+attendence+avg;



        cout << "Case " << cs << ": ";
        if(sum >= 90.00) cout << "A\n";
        else if(sum >= 80.00 && sum < 90.00) cout << "B\n";
        else if(sum >= 70.00 && sum < 80.00) cout << "C\n";
        else if(sum >= 60.00 && sum < 70.00) cout << "D\n";
        else cout << "F\n";

    }

    return 0;
}
