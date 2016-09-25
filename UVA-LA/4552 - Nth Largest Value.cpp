#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int p,dset,x;
    vector<int>dataset;

    cin >> p;

    for(int i=1; i<=p; i++)
    {
        cin >> dset;

        for(int i=0; i<10; i++)
        {
            cin >> x;
            dataset.push_back(x);
        }
        sort(dataset.begin(),dataset.end());
        cout << dset << " " << dataset[7] << endl;
        dataset.clear();

    }


    return 0;
}
