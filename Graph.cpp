// Shortest path in Directed Acyclic Graph
class Solution {
  public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& st, int node){
        visited[node] = true;
        for(auto nei: adj[node]){
            if (!visited[nei.first]) dfs(adj, visited, st, nei.first);
        }
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(V);
        stack<int>st;
        vector<bool>visited(V);
        vector<int>distance(V, 1e9);
        distance[0] = 0;
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        for(int i = 0; i < V; i++){
            if (!visited[i]) dfs(adj, visited, st, i);
        }
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if (distance[node] != 1e9) {
                for(auto nei: adj[node]){
                    if (distance[node] + nei.second < distance[nei.first]) {
                        distance[nei.first] = distance[node] + nei.second;
                    }
                }
            }
        }
        
        for(int i= 0; i < V; i++){
            if (distance[i] == 1e9 && i != 0) distance[i] = -1;
        }
        
        return distance;
    }
};
