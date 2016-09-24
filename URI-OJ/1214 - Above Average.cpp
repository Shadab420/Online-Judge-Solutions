#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int c,n,cnt=0,sum=0,marks;
    vector<int>m;
    float result;

    cin >> c;

    while(c>0)
    {
        cin >> n;

        for(int i=0; i<n; i++)
        {
            cin >> marks;
            sum+=marks;
            m.push_back(marks);
        }

        float avg = (sum*1.0)/n;


        for(int j=0; j<m.size(); j++)
        {
            if(m[j] > avg)
            {
                cnt++;
            }
        }
        result = (cnt*1.0)/n;
        cout << fixed << setprecision(3) << result*100 << "%\n";

        cnt=0;
        sum=0;
        m.clear();
        c--;

    }

    return 0;
}
