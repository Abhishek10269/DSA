#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if(this->top== this->capacity-1)
        {
            cout<<"stack overflow";
            return;
        }
        this->top++;
        this->arr[this->top]==data;
    }

    int pop()
    {
        if(this->top==-1)
        {
            cout<<"underflow";
            return INT_MIN;
        }
        this->top--;
    }

    int getTop()
    {
        return this->arr[this->top];
    }

    bool isEmpty()
    {
        if(this->top==-1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        cout<<"full called";
        if(this->top==this->capacity-1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack st(5);
    st.isEmpty();
    st.isFull();


    return 0;
}