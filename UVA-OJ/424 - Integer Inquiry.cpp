#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string num,result="";
    vector<string>v;
    int len=0;
    while(cin >> num)
    {
        if(num == "0") break;
        v.push_back(num);
        if(num.length() > len) len = num.length();
    }

    int sum,carry = 0;
    for(int a = len; a>=0; a--)
    {
        sum = 0;
        for(int i=0; i<v.size(); i++)
        {
            sum+=atoi(v[i].substr(a,1).c_str());
        }
        sum += carry;
        //cout << sum << endl;
        if(sum < 10)
        {
            carry = 0;
            stringstream convert;
            convert << sum;
            result += convert.str();
        }
        else
        {
            carry = sum/10;
            sum %= 10;
            stringstream convert;
            convert << sum;
            result += convert.str();
        }

    }
    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}
