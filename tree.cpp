#include <bits/stdc++.h>>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

 Node *createTree()
    {
        cout << "Enter the value of node:" << endl;
        int data;
        cin>>data;
        if(data==-1)
        {
            return NULL;
        }
        Node* root= new Node(data);

        //create left subtree using rec
        root->left= createTree();

        //create right subtree using rec
       root->right= createTree();
       return root;
    }

    void preOrder(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        //N
        cout<<root->data<<" ";

        //L
        preOrder(root->left);

        //R
        preOrder(root->right);
    }

    int main()
    {
        Node* root = createTree();

        cout<<"ye rhi value"<<endl<<root->left->data;
        preOrder(root);
        return 0;
    }