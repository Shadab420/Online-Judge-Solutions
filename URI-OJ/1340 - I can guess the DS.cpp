#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,cmd,val;

    while(read(n) != EOF)
    {
            queue<int>q;
            stack<int>st;
            priority_queue<int>pq;

            int qc=1, stc=1, pqc=1;

            for(int i=0; i<n; i++)
            {
                read(cmd); read(val);

                if(cmd == 1)
                {
                    q.push(val); st.push(val); pq.push(val);
                }
                else
                {
                    if(q.front() != val) qc=0;
                    if(st.top() != val) stc=0;
                    if(pq.top() != val) pqc=0;
                    q.pop(); st.pop(); pq.pop();
                }
            }

            int cnt = qc+stc+pqc;

            if(cnt == 0) printf("impossible\n");
            else if(cnt > 1) printf("not sure\n");
            else if(cnt == 1)
            {
                if(qc==1) printf("queue\n");
                else if(stc==1) printf("stack\n");
                else printf("priority queue\n");
            }
    }

    return 0;
}
