#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long int v;
    node *left;
    node *right;
};

void insrt_tree(node *&root, long long int val)
{
    if(root == NULL)
    {
        root = new node;
        root->v = val;
        root->left = NULL;
        root->right = NULL;
    }
    else if(val < root->v)
    {
        insrt_tree(root->left,val);
    }
    else if(val >= root->v)
    {
        insrt_tree(root->right,val);
    }
}

void preorder(node *&root)
{
    cout << root->v;
    if(root->left!= NULL)
    {
        cout << " ";
        preorder(root->left);
    }
    if(root->right!= NULL)
    {
        cout << " ";
        preorder(root->right);
    }
}

void inorder(node *&root)
{
    if(root->left!= NULL)
    {
        inorder(root->left);
        cout << " ";
    }
    cout << root->v;
    if(root->right!= NULL)
    {
        cout << " ";
        inorder(root->right);

    }
}

void postorder(node *&root)
{

    if(root->left!= NULL)
    {

        postorder(root->left);
        cout << " ";
    }
    if(root->right!= NULL)
    {

        postorder(root->right);
        cout << " ";
    }
    cout << root->v;


}

void display(node *&root)
{
    cout << root->v << " ";
    if(root->left!= NULL) display(root->left);
    if(root->right!= NULL) display(root->right);
}

int main()
{
    freopen("i.txt", "r", stdin);

    node *root;
    long long int val;
    int t,n;
    cin >> t;

    for(int i=1; i<=t; i++)
    {
        root = NULL;
        cin >> n;
        for(int j=1; j<=n; j++)
        {
            cin >> val;
            insrt_tree(root,val);

        }
        cout << "Case " << i << ":\n";
        cout << "Pre.: "; preorder(root);cout<<endl;
        cout << "In..: "; inorder(root);cout<<endl;
        cout << "Post: "; postorder(root);cout << endl << endl;
        //display(root);

        //delete root;

    }



    return 0;
}

