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
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);

    // create left subtree using rec
    root->left = createTree();

    // create right subtree using rec
    root->right = createTree();
    return root;
}

void levelOrder(Node *root)
{
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

// vector<vector<int>> levelOrderLEET(Node* root) {
//     queue<Node*> q;
//     vector<int> subans;
//     subans.push_back(root->data);
//     vector<vector<int>> ans;
//     q.push(root);
//     q.push(NULL);
//     while (q.size()>1) {
//         Node* front = q.front();
//         q.pop();
//         if (front == NULL) {
//             ans.push_back(subans);
//             subans.clear();
//             q.push(NULL);
//         } else {
//             subans.push_back(front->data);

//             if (front->left != NULL) {
//                 q.push(front->left);
//             }
//             if (front->right != NULL) {
//                 q.push(front->right);
//             }
//         }
//     }
//     return ans;
// }

 void zigzag(Node* root,vector<vector<int>> &answer)
    {
        vector<int> subans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(q.size()>1)
        {
            Node* front = q.front();
            q.pop();
            if(front==NULL)
            {
                answer.push_back(subans);
                q.push(NULL);
                subans.clear();
                cout<<endl;
            }
            else{
                subans.push_back(front->data);
                cout<<front->data<<"ese hi";
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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>>  result;
        zigzag(root,result);
        return result;
        
    }

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // N
    cout << root->data << " ";

    // L
    preOrder(root->left);

    // R
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
// void printVectorOfVectors(const vector<vector<int>> &vec)
// {
//     for (const auto &subvec : vec)
//     {
//         for (indata : subvec)
//         {
//             cout << val << " ";
//         }
//         cout << endl; // Print a newline after each subvector
//     }
// }

int heightOfTree(Node *root)
{
    int count = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            count++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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
    return count;
}
int heightRec(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=heightRec(root->left);
    int rh= heightRec(root->right);
    int ans = max(rh,lh) +1;
    return ans;
}
bool isBalanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    int lheight=heightRec(root->left);
    int rheight = heightRec(root->right);
    int diff = abs(lheight-rheight);
    bool curr = diff<=1;

    bool leftSub = isBalanced(root->left);
    bool rightSub = isBalanced(root->right);
    if(curr and leftSub and rightSub)
    {
        return true;
    }
    else{
        return false;
    }
}
void printVectorOfVectors(const vector<vector<int>>& vecOfVecs) {
    for (const auto& innerVec : vecOfVecs) {
        for (int val : innerVec) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node* root = createTree();
    vector<vector<int>>  result;
   result= zigzagLevelOrder(root);
   printVectorOfVectors(result);
    return 0;
    
}

// N aate hi print krlo