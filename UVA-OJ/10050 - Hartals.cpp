#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);

    int t, n, parties, hartalParam, workingDays[3655];
    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(parties);

        for(int i=1; i<=n; i++) workingDays[i] = 0;

        for(int i=6, j=7; i<=n || j<=n; i+=7, j+=7)
        {
            workingDays[i] = workingDays[j] = 2;
        }

        int cntLose = 0;

        for(int i=0; i<parties; i++)
        {
            read(hartalParam);

            for(int j=hartalParam; j<=n; j+=hartalParam)
            {
                if(workingDays[j] == 0)
                {
                    workingDays[j] = 1;
                    cntLose++;
                }
            }
        }
        printf("%d\n", cntLose);
    }

    return 0;
}
