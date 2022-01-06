// SPOJ username: madara_op
// Status : https://www.spoj.com/status/madara_op/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Node
{
    public:
        long long data;
        Node* left;
        Node* right;

        Node(long long data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

class BST
{
    public:

        Node* root=NULL;
        
        // Function to insert the node
        Node* insert(long long x, Node* p)
        {
            if(p==NULL)
                p = new Node(x);
            else if(x < p->data)
                p->left=insert(x,p->left);
            else if(x > p->data)
                p->right=insert(x,p->right);
            return p;
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
                else if(p->left==NULL || p->right==NULL)
                {
                    if(p->left==NULL)
                        return p->right;
                    else
                        return p->left;
                }
                else
                {
                    Node* r;
                    r = find_replacement(p);
                    p->data = r->data;
                    p->right = Delete(key, p->right);
                }        
            }
            return p;
        }
};

int main()
{
    BST b;
    b.insert(10, b.root);
    b.insert(20, b.root);
    b.Delete(10, b.root);

    return 0;
}


// class Node
// {
//     public:
//         long long data;
//         Node* left;
//         Node* right;

//         Node(long long data)
//         {
//             this->data=data;
//             left=NULL;
//             right=NULL;
//         }
// };

// class BST
// {
//     public:

//         Node* root=NULL;
//         int index;
        
//         // Function to insert the node
//         Node* insert(long long x, Node* p)
//         {
//             if(p==NULL)
//                 p = new Node(x);
//             else if(x < p->data)
//                 p->left=insert(x,p->left);
//             else if(x > p->data)
//                 p->right=insert(x,p->right);
//             return p;
//         }

//         bool CheckElement(long long x, Node* p)
//         {
//             if(p==NULL)
//                 return false;
//             else if(x<p->data)
//                 return CheckElement(x,p->left);
//             else if(x>p->data)
//                 return CheckElement(x,p->right);
//             else 
//                 return true;
//         }

//         // Inorder traversal in decreasing order
//         void find(long long x, Node* p)
//         {
//             if(p==NULL || (p->data==x && p->right==NULL))
//                 return;
//             find(x, p->right);
//             if(p->data<=x)
//                 return;
//             index++;
//             if(p->data >x)
//                 find(x,p->left);
//         }
// };

// int main()
// {
//     int n, type,ind;
//     long long x;
//     cin >> n;
//     BST b;
//     vector<pair<int,long long>> v;
//     for(int i=0; i<n; i++)
//     {
//         cin >> type >> x;
//         v.push_back(make_pair(type,x));
//     }
//     for(auto q:v)
//     {
//         if(q.first==1)
//             b.root = b.insert(q.second, b.root);
//         else
//         {
//             if(b.CheckElement(q.second, b.root))
//             {
//                 b.index=1;
//                 b.find(q.second, b.root);
//                 cout << b.index << endl;
//             }
//             else
//                 cout << "Data tidak ada" << endl;
//         }
//     }
//     return 0;
// }
