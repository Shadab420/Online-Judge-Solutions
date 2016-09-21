#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

bool prefixFound;

class Trie
{
    public:
    bool endmark;
    Trie *next[10];
    Trie()
    {
        endmark=false;
        for(int i=0; i<=9; i++) next[i] = NULL;
    }

};

Trie *root=NULL;

void insertTrie(string s)
{
    Trie *p = root;

    for(int i=0; i<s.length(); i++)
    {
        int currCharId = s[i]-'0';

        if(p->next[currCharId] == NULL) p->next[currCharId] = new Trie();

        p = p->next[currCharId];
        if(p->endmark == true && i<s.length()-1) prefixFound = true;
    }
    p->endmark = true;

    for(int i=0; i<=9; i++)
    {
        if(p->next[i] != NULL)
        {
            prefixFound = true; return;
        }
    }

}

void deleteTrie(Trie *r)
{

    for(int i=0; i<=9; i++)
    {
        if(r->next[i] != NULL) deleteTrie(r->next[i]);
    }
    delete r;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,n; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n);
        root = new Trie();
        prefixFound = false;
        string phoneNo;
        vector<string>phone;

        for(int i=0; i<n; i++)
        {
            cin >> phoneNo; phone.push_back(phoneNo);
            insertTrie(phoneNo);
        }

        if(prefixFound) printf("NO\n");
        else printf("YES\n");
        deleteTrie(root);
    }

    return 0;
}
