#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*l,*r,*p;
    string c;
    Node(int d)
    {
        data=d;
        l=r=p=NULL;
        c="red";
    }
};
Node* BSTinsert(Node* root,Node* newnode)
{
    if(root==NULL)
        return root;
    if(newnode->data<root->data)
    {
        root->l=BSTinsert(root->l,newnode);
        root->l->p=root;
    }
    else if(newnode->data>root->data)
    {
        root->r=BSTinsert(root->r,newnode);
        root->r->p=root;
    }
    return root;
}
class RBT
{
public:
    Node* root;
    RBT()
    {
        root=NULL;
    }
    void RotateRight(Node*& root,Node*& node)

    {
        Node* left=node->l;
        node->l=left->r;
        if(node->l!=NULL)
            node->l->p=node;
        left->p=node->p;
        if(node->p==NULL)
            root=left;
        else if(node->p->l=node)
            node->p->l=left;
        else
            node->p->r=left;
        left->r=node;
        node->p=left;
    }
    void RotateLeft(Node* root,Node* node)
    {
        Node* right=node->r;
        node->r=right->l;
        if(node->r!=NULL)
            node->r->p=node;
        right->p=node->p;
        if(node->p=NULL)
            root=node;
        else if(node->p->l=node)
            node->p->l=right;
        else
            node->p->r=right;
        right->l=node;
        node->p=right;
    }
    void fix(Node*& root,Node*& node)
    {
        Node* parent=NULL;
        Node* grand=NULL;
        while(node!=root&&node->c!="black"&&node->p->c=="red")
        {
            parent=node->p;
            grand=node->p->p;
            if(node->p->l=grand->l)
            {
                Node* uncle=grand->r;
                if(uncle!=NULL&&uncle->c=="red")
                {
                    grand->c="red";
                    parent->c="black";
                    uncle->c="black";
                    node=grand;
                }
                else
                {
                    if(node=parent->r)
                    {
                        RotateLeft(root,parent);
                        node=parent;
                        parent=node->p;
                    }
                    else
                    {
                        RotateRight(root,grand);
                        swap(grand->c,parent->c);
                        node=parent;
                    }
                }
            }
            else
            {
                Node* uncle=grand->l;
                if(uncle!=NULL&&uncle->c=="red")
                {
                    grand->c="red";
                    parent->c="black";
                    uncle->c="black";
                    node=grand;
                }
                else
                {
                    if(node=parent->l)
                    {
                        RotateRight(root,parent);
                        node=parent;
                        parent=node->p;
                    }
                    else
                    {
                        RotateLeft(root,grand);
                        swap(grand->c,parent->c);
                        node=parent;
                    }
                }
            }
        }
        root->c="black";
    }
    void RBTinsert(const int& data)
    {
        Node* node=new Node(data);
        root=BSTinsert(root,node);
        fix(root,node);
    }
    void PrintInorder(Node *root)
    {
        if (root == NULL)
            return;

        PrintInorder(root->l);
        cout << root->data << "  ";
        PrintInorder(root->r);
    }

};

int main()
{
    RBT t;
    t.RBTinsert(7);
    t.RBTinsert(6);
    t.RBTinsert(5);
    t.RBTinsert(4);
    t.PrintInorder(t.root);
    return 0;
}
