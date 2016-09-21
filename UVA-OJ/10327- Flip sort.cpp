#include <bits/stdc++.h>

using namespace std;

int arr[1005];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n,c;
    while(scanf("%d", &n) != EOF)
    {
        c=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
        }

        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                    c++;
                }
            }
        }
        cout << "Minimum exchange operations : " << c << endl;
    }



    return 0;
}
