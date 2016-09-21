#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int initPos,a,b,c,ans;
    while(cin >> initPos >> a >> b >> c)
    {
        if(initPos == 0 && a == 0 && b==0 && c==0) break;
        ans = 1080;
        ans += initPos>a?(initPos-a)*9:(40-a+initPos) * 9;
        ans += a>b?(40-a+b)*9:(b-a) * 9;
        ans += b>c?(b-c)*9:(40-c+b) * 9;
        cout << ans << endl;
    }
    return 0;
}
