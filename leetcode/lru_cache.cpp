#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node
    {
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            
            Node(int key, int val)
            {
                this->key = key;
                this->val = val;
            }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> ma;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity =  capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deletenode(Node* curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    
    void addnode(Node* curr)
    {
        Node* temp = head->next;
        head->next = curr;
        temp->prev = curr;
        curr->next = temp;
        curr->prev = head;
    }
    
    
    int get(int key) 
    {
        if(ma.find(key)!=ma.end())
        {
            Node* curr = ma[key];
            int ans = curr->val;
            ma.erase(key);
            deletenode(curr);
            addnode(curr);
            ma[key] = head->next;
            return ans;
        }
        else
            return -1;
    }
    
    void put(int key, int value) 
    {
        if(ma.find(key)!=ma.end())
        {
            Node* curr = ma[key];
            ma.erase(key);
            deletenode(curr);
        }
        if(ma.size()==capacity)
        {
            ma.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        ma[key] = head->next;
        
    }
};

int main()
{}