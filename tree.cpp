#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
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

    void inOrder(Node* root)
    {
         if(root==NULL)
        {
            return;
        }
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);

    }

    void postOrder(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    int main()
    {
        Node* root = createTree();
        postOrder(root);
        return 0;
    }



    //N aate hi print krlo
    