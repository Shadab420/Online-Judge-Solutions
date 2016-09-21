#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int n,c,day,total_given,givePerDay,back_;

    while(cin >> n)
    {
        if(n == 0) break;
        c=0;
        total_given=0;
        givePerDay = 1;
        back_=0;

        for(day=1; day<=n; day++)
        {
            if(back_ > 0)
            {
                back_--;
                total_given++;
                n--;
            }
            else
            {
                if(back_ == 0 && day < n) c++;
                back_ = total_given;
                givePerDay = day;
                n--;
                total_given = givePerDay;
            }
        }

        cout << c << endl;

    }

    return 0;
}
