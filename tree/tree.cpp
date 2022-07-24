#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node* r;
    Node* l;
    Node(int k)
    {
        key=k;
        l=r=NULL;
    }
};
Node* ins(Node* root,int key)
{
    if(root==NULL)
        return new Node(key);
    if(key<=root->key)
    {
        root->l=ins(root->l,key);
    }
    else
    {
        root->r=ins(root->r,key);
    }
    return root;
}
int main()
{
    Node* root=NULL;
    root=ins(root,15);
    ins(root,10);
    ins(root,30);
    ins(root,8);
    cout<<root->key;
    cout<<root->l->key;
    cout<<root->r->key;
    cout<<root->l->l->key;
    return 0;
}
