#include <bits/stdc++.h>

using namespace std;

vector <int> ages;


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    long long int n;


    while(cin >> n)
    {
        if(n==0) break;

        ages.clear();

        for(long long int i=0; i<n; i++)
        {
            int age;
            scanf("%d", &age);
            ages.push_back(age);
        }

        sort(ages.begin(), ages.end());

        for(long long int i=0; i<n; i++)
        {
            if(i==n-1) printf("%d\n", ages[i]);
            else printf("%d ", ages[i]);
        }

    }




    return 0;
}
