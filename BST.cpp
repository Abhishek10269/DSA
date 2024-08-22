#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertBST(Node* root,int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
    }
    if(data<root->data)
    {
        root->left=insertBST(root->left,data);
    }
    else{
        root->right=insertBST(root->right,data);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"ENTER THE VALUE:";
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertBST(root,data);
        cout<<"ENTER THE VALUE:";
        cin>>data;
    }

}
void levelOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int max (Node * root)
{
    Node* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp->data;
}

int main()
{
    Node* root=NULL;
    createBST(root);
    levelOrder(root);
    int x=max(root);
    cout<<"The maximum value is"<<x;
    return 0;
}