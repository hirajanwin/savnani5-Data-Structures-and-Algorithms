#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int maxNode, minNode, maxSize;

    Node(int maxNode, int minNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:

    // Post Order Traversal
    Node largestBSTHelper(TreeNode* root) {
        
        // An empty tree is a BST of size 0
        if(!root) {
            return Node(INT_MAX, INT_MIN, 0);
        }
        // Get values from left and right subtrees
        Node left = largestBSTHelper(root->left);
        Node right = largestBSTHelper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST
            return Node(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        } 
        // Otherwise return [-inf, inf] so that parent canot be valid BST !
        return Node(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));    
    }

public:
    int LargetBST(TreeNode* root) {
        return largestBSTHelper(root).maxSize;
    }
};


int main() {

    
}
