#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }

};

class MyQueue{
    private:
    node* back;
    node* front;

    public:
    MyQueue()
    {
        back=nullptr;
        front=nullptr;
    }

    void enqueue(int value)
    {
        node *newNode = new node(value);
        if(isEmpty())
        {
            front=back=newNode;
        }
        else{
            back->next=newNode;
            back=newNode;
        }
        
    }

    bool isEmpty()
    {
        return front=nullptr;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;

        if(front==nullptr)
        {
            back=nullptr;
        }
    }

    ~MyQueue()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }

};

int main()
{
    MyQueue que;
    que.enqueue(5);
    cout<< que.isEmpty()<<endl;
    return 0;
}