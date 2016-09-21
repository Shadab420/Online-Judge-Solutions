#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int k,arr[13], printed = 0;

    while(read(k))
    {
        if(k == 0) break;
        if(printed) printf("\n");

        for(int i=0; i<k; i++) read(arr[i]);

        for(int a=0; a<k; a++)
        {
            for(int b=a+1; b<k; b++)
            {
                for(int c = b+1; c<k; c++)
                {
                    for(int d=c+1; d<k; d++)
                    {
                        for(int e=d+1; e<k; e++)
                        {
                            for(int f = e+1; f<k; f++)
                            {
                                printf("%d %d %d %d %d %d\n", arr[a],arr[b],arr[c],arr[d],arr[e],arr[f]);
                            }
                        }
                    }
                }
            }
        }
        printed = 1;

    }



    return 0;
}
