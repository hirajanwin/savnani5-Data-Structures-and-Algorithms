// SPOJ username: madara_op
// Status : https://www.spoj.com/status/madara_op/

// Note : If deletions are rare use lazydelete i.e keep an attribute dead/alive node in the node class
// Summary of AVL trees :

// Similar to BST - Just include update height and rebalance at end of insert and delete functions
//  Rebalance calls respective rotations using balance factor of the node 

#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
        long long data;
        int height;
        Node* left;
        Node* right;

        Node(long long data)
        {
            this->data=data;
            height=1;
            left=NULL;
            right=NULL;
        }
};

class AVL
{
    public:

        Node* root=NULL;
        int index_counter=1;
        
        int height(Node *p)
        {
            if (p == NULL)
                return 0;
            return p->height;
        }

        int balanceFactor(Node* p)
        {
            if (p == NULL)
                return 0;
            return height(p->right) - height(p->left); 
        }

        int max(int a, int b)
        {
            return (a > b)? a : b;
        }

        void updateHeight(Node *p)
        {
            p->height = 1 + max(height(p->left), height(p->right));
        }

        Node* rotateRight(Node* p)
        {
            Node* q = p->left;
            p->left = q->right;
            q->right = p;
            updateHeight(p);
            updateHeight(q);
            if(root==p)
                root=q;
            return q;
        }

        Node* rotateLeft(Node* p)
        {
            Node* q = p->right;
            p->right = q->left;
            q->left = p;
            updateHeight(p);
            updateHeight(q);
            if(root==p)
                root=q;
            return q;
        }

        Node* rotateLeftRight(Node* p)
        {
            p->left = rotateLeft(p->left);
            return rotateRight(p);
        }

        Node* rotateRightLeft(Node* p)
        {
            p->right = rotateRight(p->right);
            return rotateLeft(p);
        }
        
        // Rebalance
        Node* rebalance(Node* p)
        {
            if(p==NULL)
                return p;

            int balance = balanceFactor(p);
            if(balance<-1)
            {
                if(height(p->left->left) >= height(p->left->right))
                    p = rotateRight(p);
                else
                    p = rotateLeftRight(p);
            }
            else if(balance>1)
            {
                if(height(p->right->right) >= height(p->right->left))
                    p = rotateLeft(p);
                else
                    p = rotateRightLeft(p);
            }
            return p;
        }

        // Function to insert the node
        Node* insert(long long x, Node* p)
        {
            if(p==NULL)
                p = new Node(x);
            else if(x < p->data)
                p->left=insert(x,p->left);
            else if(x > p->data)
                p->right=insert(x,p->right);  
            else
                return p;

            updateHeight(p);
            return rebalance(p);

        }

        Node* find(long long x, Node* p)
        {
            if(p==NULL)
                return NULL;
            else if(x<p->data)
                return find(x,p->left);
            else if(x>p->data)
                return find(x,p->right);
            else 
                return p;
        }

        Node* find_replacement(Node* p)
        {
            Node* r = p->right;
            while(r->left!=NULL)
            {
                r = r->left;
            }
            return r;
        }

        Node* Delete(long long key, Node* p)
        {
            if(p==NULL)
                return NULL;
            else
            {
                if(key < p->data)
                    p->left = Delete(key, p->left);
                else if(key > p->data)
                    p->right = Delete(key, p->right);
                else if(p->left==NULL || p->right==NULL)  // 0 child and 1 child case
                {
                    if(p->left==NULL)
                        return p->right;
                    else
                        return p->left;
                }
                else                                      // 2 child case
                {
                    Node* r;
                    r = find_replacement(p);
                    p->data = r->data;
                    p->right = Delete(key, p->right);
                }        
            }
            if(p == NULL)
                return p;
                
            updateHeight(p);
            return rebalance(p); 
        }
};

int main()
{
    AVL b;
    b.insert(10, b.root);
    b.insert(20, b.root);
    // b.delete(10,b.root);
    return 0;
}
