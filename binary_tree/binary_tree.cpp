#include <iostream>
#include <stdio.h>
#include <utils.h>

using namespace std;

class Tree
{
    public:
        Node* root;
        Tree();
        void CreateTree();
        void Preorder(Node* p);
        void Postorder(Node* p);
        void Inorder(Node* p);
        void Levelorder(Node* p);
        void iPreorder(Node* p);
        void iPostorder(Node* p);
        void iInorder(Node* p);
        int Height(Node* root);
};

Tree::Tree()
{
    root=NULL;
}

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue Q(100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node(x);
    Q.enqueue(root);

    while(!Q.isEmpty())
    {
        p = Q.dequeue();
        cout << "Enter Left Child of " << p->data << ": ";
        cin >> x;
        if(x!=-1)
        {
            t = new Node(x);
            p->lchild = t;
            Q.enqueue(t);
        }
        cout << "Enter Right Child of " << p->data << ": ";
        cin >> x;
        if(x!=-1)
        {
            t = new Node(x);
            p->rchild = t;
            Q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node* p)
{
    if(p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Postorder(Node* p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::iPreorder(Node* p)
{
    Stack S(100);
    while(p != NULL || !S.isEmpty())
    {
        if(p!=NULL)
        {
            cout << p->data << " ";
            S.push(p);
            p = p->lchild;
        }
        else
        {
            p = S.pop();
            p = p->rchild;
        }
    }
}

void Tree::iInorder(Node* p)
{
    Stack S(100);
    while(p != NULL || !S.isEmpty())
    {
        if(p!=NULL)
        {
            S.push(p);
            p = p->lchild;
        }
        else
        {
            p = S.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}


// void Tree::iPostorder(Node* p)
// {
//     Stack S(100);
//     long temp;
//     while(p != NULL || !S.isEmpty())
//     {
//         if(p!=NULL)
//         {
//             S.push(p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = (int)S.pop();
//             if(temp > 0)
//             {
//                 S.push((Node*)(-temp));
//                 p = ((Node*)temp)->rchild;
//             }
//             else
//             {
//                 cout << ((Node*)temp)->data;
//                 p = NULL;
//             }
//         }
//     }
// }


void Tree::Levelorder(Node* p)
{
    Queue q(100);
    cout << p->data << " ";
    q.enqueue(p);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        if(p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        } 
    }
}

int Tree::Height(Node* root)
{
    int x=0, y=0;
    if(root==0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x>y) 
        return x+1;
    else
        return y+1;
}

int main()
{
    Tree t;
    t.CreateTree();
    t.iInorder(t.root);
    // t.Postorder(t.root);
    // t.Levelorder(t.root);
    // t.Inorder(t.root);
}