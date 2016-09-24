#include <bits/stdc++.h>
using namespace std;

int noOfdivisors[1001];
int numbers[1001];


void getNoOfDevisors()
{
    for(int i=2; i<=1000; i++)
    {
        for(int j=2; j<=1000; j++)
        {
            if(i<=j && j%i==0) noOfdivisors[j]++;
        }
    }
}

bool comp(int a, int b)
{
    if(noOfdivisors[a] < noOfdivisors[b]) return true;
    else if(noOfdivisors[a] == noOfdivisors[b] && a > b) return true;
    else return false;
}

int main()
{
    int t,n,cs=0; cin >> t;
    for(int i=1; i<=1000; i++)
    {
        noOfdivisors[i] = 1;
        numbers[i-1] = i;
    }
    getNoOfDevisors();
    sort(numbers,numbers+1000,comp);

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;

        cout << "Case " << cs << ": " << numbers[n-1] << endl;
    }




    return 0;
}
