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

    void levelOrder(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* front= q.front();
            q.pop();
            if(front==NULL)
            {
                cout<<endl;
                if(!q.empty())
                {
                q.push(NULL);
                }
            }
            else{
            cout<<front->data<<" ";
            
            if(front->left!=NULL)
            {
                q.push(front->left);
            }
            if(front->right!=NULL)
            {
                q.push(front->right);
            }
            }
        }
    }

    vector<vector<int>> levelOrderLEET(Node* root) {
        queue<Node*> q;
        vector<int> subans;
        subans.push_back(root->data);
        vector<vector<int>> ans;
        q.push(root);
        q.push(NULL);
        while (q.size()>1) {
            Node* front = q.front();
            q.pop();
            if (front == NULL) {
                ans.push_back(subans);
                subans.clear();
                q.push(NULL);
            } else {
                subans.push_back(front->data);

                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
        }
        return ans;
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
    void printVectorOfVectors(const vector<vector<int>>& vec) {
    for (const auto& subvec : vec) {
        for (int val : subvec) {
            cout << val << " ";
        }
        cout << endl; // Print a newline after each subvector
    }
}

    int main()
    {
        Node* root = createTree();
        vector<vector<int>> answer=levelOrderLEET(root);
        printVectorOfVectors(answer);
        return 0;
    }



    //N aate hi print krlo
    