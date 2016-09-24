#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    int t; read(t);
    string cmd,url;

    for(int cs=1; cs<=t; cs++)
    {
        stack<string>forwardd,backward;
        backward.push("http://www.lightoj.com/");
        printf("Case %d:\n", cs);
        while(cin>>cmd)
        {
            if(cmd == "QUIT") break;
            else if(cmd == "VISIT")
            {
                cin>>url;
                cout << url << endl;
                backward.push(url);
                while(!forwardd.empty()) forwardd.pop();
            }
            else if(cmd == "BACK")
            {
                if(backward.empty()) printf("Ignored\n");
                else
                {
                    if(backward.size() > 1)
                    {
                        forwardd.push(backward.top());
                        backward.pop();
                        cout<<backward.top()<<endl;
                    }
                    else printf("Ignored\n");
                }
            }
            else if(cmd == "FORWARD")
            {
                if(forwardd.empty()) printf("Ignored\n");
                else
                {
                    int print = 0;
                    if(backward.empty())
                    {
                        for(int i=1; i<=2; i++)
                        {
                            backward.push(forwardd.top()); forwardd.pop();

                            if(forwardd.empty())
                            {
                                printf("Ignored\n"); print=1; break;
                            }
                        }
                    }
                    else
                    {
                        backward.push(forwardd.top()); forwardd.pop();
                    }
                    if(print == 0) cout << backward.top() << endl;
                }
            }
        }
    }

    return 0;
}
