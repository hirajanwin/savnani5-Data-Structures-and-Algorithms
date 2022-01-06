#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
        int parent;
        int rank;
};

// Optimized with path compression
int find_op(int x, vector<Node> &dsuf)
{
    if(dsuf[x].parent == -1)
        return x;
    return dsuf[x].parent = find_op(dsuf[x].parent, dsuf);
}

// Optimized union with rank
void union_op(int from, int to, vector<Node> &dsuf)
{
    int AR_from = find_op(from, dsuf);
    int AR_to = find_op(to, dsuf);

    if(dsuf[AR_from].rank > dsuf[AR_to].rank)
        dsuf[AR_to].parent = AR_from;
    else if(dsuf[AR_from].rank < dsuf[AR_to].rank)
        dsuf[AR_from].parent = AR_to;
    else
    {
        dsuf[AR_from].parent = AR_to;
        dsuf[AR_to].rank +=1;
    }
}

bool isCyclic(vector<pair<int, int>> &edge_list, vector<Node> &dsuf)
{   
    // Note: Disjoint set cannot detect cycle in a directed graph
    for(auto p: edge_list)
    {
        int AR_from = find_op(p.first, dsuf);
        int AR_to = find_op(p.second, dsuf);

        if(AR_from == AR_to)
            return true;
        
        union_op(AR_from, AR_to, dsuf);
    }
    return false;
}

int main()
{
    int E;                  // No. of edges
    int V;                  // No. of vertices
    cin >> E >> V;

    // disjoint set data structure 
    vector<Node> dsuf;
    dsuf.resize(V);

    for(int i=0; i<V; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<pair<int, int>> edge_list;
    for(int i=0; i<E; i++)
    {
        int from, to;
        cin >> from >> to;
        edge_list.push_back({from, to});
    }

    if(isCyclic(edge_list, dsuf))
        cout << "\nTRUE";
    else
        cout << "\nFALSE";
    
    return 0;
}
