#include <bits/stdc++.h>
using namespace std;


vector<int>getNums(string line)
{
    vector<int>result;

    int len = line.length(), num = 0;


    for(int i=0; i<len; i++)
    {
        if(line[i] != ' ')
        {
            num*=10; num+= (line[i] -'0');
        }

        if(line[i] == ' ' || i == len-1)
        {
            if(num != 0)
            {
                result.push_back(num);
                num=0;
            }
        }
    }
    return result;

}


int GCD(int x, int y)
{
    while(x>0)
    {
        int temp = x;
        x = y%x;
        y = temp;
    }
    return y;
}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t; cin >> t;
    cin.ignore();


    for(int cs=1; cs<=t; cs++)
    {
        vector<int>arr;
        string line; getline(cin,line);

        arr = getNums(line);

        int maxGCD = 0;
        for(int i=0; i<arr.size()-1; i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                int x = arr[i], y = arr[j];
                if(x>y) swap(x,y);
                int gcd = GCD(x,y);
                if(gcd > maxGCD) maxGCD = gcd;
            }
        }
        cout << maxGCD << endl;
    }

    return 0;
}
