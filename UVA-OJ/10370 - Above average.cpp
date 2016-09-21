#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n; cin >> t;
    vector<double>marks;
    double avg,x,sum;
    int cnt;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;
        sum = 0.0;
        cnt = 0;
        for(int i=0; i<n; i++)
        {
            cin >> x; sum+=x;
            marks.push_back(x);
        }
        avg = sum/n;
        sort(marks.begin(),marks.end());
        for(int i=n-1; marks[i] > avg; i--) cnt++;
        cout << fixed << setprecision(3) << (float)cnt/n*100 << "%\n";
        marks.clear();
    }

    return 0;
}
