#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        left=NULL;
        right=NULL;
    }
};

int diameter(Node* root, int & res)
{
    if(root==NULL)
        return 0;

    int l = diameter(root->left, res);
    int r = diameter(root->right, res);

    int temp = 1 + max(l,r);
    int ans = max(temp, 1+l+r);
    res = max(res, ans);

    return temp;
}

int max_path_sum(Node* root, int & res)
{
    // Fromn any node to any node
    if(root==NULL)
        return 0;
    int l = max_path_sum(root->left, res);
    int r = max_path_sum(root->right, res);
    int temp = max(max(l,r)+root->val, root->val);
    int ans = max(temp, l+r+root->val);
    res = max(ans, res);
    return temp;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(12);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    
    int res = INT_MIN;
    cout << diameter(root, res) << endl;
    cout << max_path_sum(root, res);
}