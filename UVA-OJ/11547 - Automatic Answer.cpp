#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n; cin>>t;
    while(t>0)
    {
        cin>>n; n= (((((n*567)/9)+7492)*235)/47)-498; cout<<abs(n/10)%10<<endl; t--;
    }

    return 0;
}
