#include <iostream>

using namespace std;
//stack FILO , LIFO
//queue FIFO , LILO
template<class type>
class Stack
{
public:
    virtual void push(type )=0;
    virtual type pop()=0;
    virtual type recent()=0;
    virtual ~Stack(){};
};

template<class type>
class StackSA : public Stack<type>
{
    int top;
    type arr [100];
public:
    StackSA ():top(-1){}
    void push(type e)
    {
        if (top<100)
            arr[++top]=e;
        else
            return;
    }
    type pop()
    {
        if (top!=-1)
            return arr[top--];
        else
            return ;
    }
    type recent()
    {
        if (top!=-1)
            return arr[top];
        else
            return ;
    }

};

template<class type>
class StackDA : public Stack<type>
{
    int cap;
    int top;
    type* arr ;
    void increase_cap()
    {
        cap*=2;
        type* narr=new type[cap];
        for (int i=0;i<=top;i++)
        {
            narr[i]=arr[i];
        }
        delete[]arr;
        arr=narr;
    }
public:
    StackDA ():top(-1),cap(10),arr(new type [cap]){}
    ~StackDA(){delete[] arr;}
    void push(type e)
    {
        if (top<cap)
            arr[++top]=e;
        else
        {
            increase_cap();
            arr[++top]=e;
        }
    }
    type pop()
    {
        if (top!=-1)
            return arr[top--];
        else
            return ;
    }
    type recent()
    {
        if (top!=-1)
            return arr[top];
        else
            return ;
    }

};
template<class type>
class StackLL:public Stack<type>
{
    int top;
    class Node
    {
    public:

        type data;
        Node* next;
        Node():next(NULL){}
        Node(type d,Node *n):data(d),next(n){}
    };
    Node * head;
public:
    StackLL():top(-1),head(NULL){}
    ~StackLL()
    {
        while(head!=NULL)
        {

            Node* n=head;
            head=head->next;
            delete[]n;
        }
    }
    void push(type e)
    {
        top++;
        Node* n=new Node(e,head);
        head=n;
    }
    type pop()
    {
        if(head!=NULL)
        {
        top--;
        Node* n=head;
        type d=n->data;
        head=head->next;
        delete[]n;
        return d;
        }


    }
    type recent()
    {
        if (head!=NULL)
            return head->data;
    }
};

int main()
{
    StackLL <int>sll;
    sll.push(4);
    sll.push(5);
    sll.pop();
    sll.pop();
    cout<<sll.pop();
    cout<<sll.pop();

    return 0;
}
