#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>
using namespace std;


class LRUCache
{
    private:
        list<int> dq;
        unordered_map<int, list<int>::iterator> ma;
        int csize;

    public:
        LRUCache(int);
        void refer(int);
        void display();
};

LRUCache::LRUCache(int n)
{
    csize = n;
}

void LRUCache::refer(int x)
{
    if(ma.find(x) == ma.end())
    {
        if(dq.size() == csize)
        {
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    else
    {
        dq.erase(ma[x]);
    }
    dq.push_front(x);
    ma[x] = dq.begin();
}

void LRUCache::display()
{
    for(auto it = dq.begin(); it!=dq.end(); it++)
    {
        cout << (*it) << " ";
    }
}

int main()
{
    LRUCache lru(4);
    lru.refer(1);
    lru.refer(2);
    lru.refer(3);
    lru.refer(1);
    lru.refer(4);
    lru.refer(5);
    lru.display();
}