#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

    void dfs(string source,  
         unordered_map<string, priority_queue<string, vector<string>, greater<string> > > &adj, 
         vector<string> & ans ){

        while(!adj[source].empty()){
            string newSource = adj[source].top();
            adj[source].pop();
            dfs(newSource, adj, ans);
        }  
        ans.push_back(source);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        vector<string> ans;
        
        // Adj list 
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        
        // Representing the graph
        for(auto ticket: tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        
        // DFS + Backtracking
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        
        
        return ans;
        
    }

int main()
{
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<string> ans = findItinerary(tickets);
    for(auto str: ans)
        cout << str << " ";

}