#include <bits/stdc++.h>
using namespace std;

#define read(str) scanf("%s", str)

bool prime[201];
long long int t,n;

void sieve()
{

    memset(prime,true,sizeof prime);

    for(int i=2; i<=14; i++)
    {
        if(prime[i])
        {
            for(int j=i+i; j<=200; j+=i) prime[j] = false;
        }
    }
}

int main()
{
    sieve();
    map<char,int>m;
    for(int i=97; i<=122; i++) m[(char)i] = i-'a'+1;
    for(int i=65; i<=90; i++) m[(char)i] = i-'A'+27;

    char word[20];
    int sum;

    while(read(word)!=EOF)
    {
        sum=0;
        for(int i=0; i<strlen(word); i++) sum+=m[word[i]];
        if(prime[sum]) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }

    return 0;
}
