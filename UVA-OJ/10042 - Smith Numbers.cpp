#include <bits/stdc++.h>

using namespace std;

long long int sum1, sum2;
vector<int>primeNos;

int digitSum(long long int n)
{
    if(n == 0)
    {
        return 0;
    }
    else return n%10 + digitSum(n/10);
}

void sieve(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for (long long int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (long long int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (long long int p=2; p<=n; p++)
    {
        if (prime[p])
        {
            primeNos.push_back(p);
        }
    }

}

int main()
{
    freopen("in.txt","r",stdin);

    sieve(100000);

    long long int t,n; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {

        cin >> n;

        for(long long int i=n+1; ; i++)
        {
            sum1 = sum2 = 0;
            sum1 = digitSum(i);

            long long int k=0,temp = i;

            while(primeNos[k] <= sqrt(temp))
            {
                if(temp % primeNos[k] == 0)
                {
                    sum2 += digitSum(primeNos[k]);

                    temp/=primeNos[k];
                    //k=0;

                }
                else k++;
            }
            //cout << endl;
            //cout << temp << endl;
            if(temp < i)
            {
                sum2 += digitSum(temp);

                if(sum1 == sum2)
                {
                    cout << i << endl;
                    break;
                }


            }

        }
    }

    return 0;
}
