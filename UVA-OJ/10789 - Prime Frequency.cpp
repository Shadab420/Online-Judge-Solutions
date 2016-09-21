#include <bits/stdc++.h>
using namespace std;

bool prime[2001];

void sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i=2; i<=2000; i++)
    {
        if(prime[i])
        {
            for(int p = i*i; p<=2000; p+=i) prime[p] = false;
        }
    }
}

int main()
{
    sieve();

    int t,cs=0; scanf("%d",&t);
    string s;

    while(cin >> s)
    {
        cs++;
        map<char,int>freq;

        for(int i=0; i<s.length(); i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                freq[s[i]]++;
            }
        }

        printf("Case %d: ", cs);

        bool found = false;

        for(int i=48; i<=122; i++)
        {
            if(prime[freq[(char)i]])
            {
                printf("%c", (char)i);
                found = true;
            }
        }
        if(!found) cout << "empty";
        printf("\n");
    }

    return 0;
}
