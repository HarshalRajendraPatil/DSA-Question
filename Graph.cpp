// Minimum Multiplications to reach End
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        queue<pair<int, int>>q;
        q.push({0, start}); // {dis, node}
        vector<int>distance(1000, 1e9);
        distance[start] = 0;
        
        while(!q.empty()){
            int currDis = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for(auto nei: arr){
                int newNode = (nei*node)%1000;
                if (currDis + 1 < distance[newNode]){
                    distance[newNode] = currDis+1;
                    q.push({distance[newNode], newNode});
                }
            }
        }
        return distance[end] == 1e9 ? -1 : distance[end];
    }
};

// Cheapest Flights Within K Stops
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>>q; // {stop, {price, dest}};
        q.push({0, {0, src}});
        
        vector<int>prices(n, 1e9);
        prices[src] = 0;
        

        while(!q.empty()){
            int currStops = q.front().first;
            int currPrice = q.front().second.first;
            int currNode = q.front().second.second;
            q.pop();
            if (currStops > k) break;

            for(auto nei: adj[currNode]){
                int edgePrice = nei.second;
                int adjNode = nei.first;

                if (edgePrice + currPrice < prices[adjNode]){
                    prices[adjNode] = edgePrice + currPrice;
                    q.push({currStops+1, {prices[adjNode], adjNode}});
                }
            }
        }
        return prices[dst] == 1e9 ? -1 : prices[dst];
    }
};

// Shortest Path in an Undirected Graph
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>distance(n+1, 1e9);
        vector<vector<pair<int, int>>>adj(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>parent(n+1);
        vector<int>ans;
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        distance[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (dis > distance[node]) continue;
            for(auto nei: adj[node]){
                int edgeDis = nei.second;
                int adjNode = nei.first;
                
                if (dis + edgeDis < distance[adjNode]){
                    distance[adjNode] = dis+edgeDis;
                    parent[adjNode] = node;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        if (distance[n] == 1e9) return {-1};
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        ans.insert(ans.begin(), distance[n]);
        return ans;
    }
};

// Word Ladder II
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>used;
        used.push_back(beginWord);
        int level = 0;
        vector<vector<string>>ans;

        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            if (vec.size() > level){
                level++;
                for(auto word: used){
                    st.erase(word);
                }
            }

            string word = vec.back();
            if (word == endWord){
                if (ans.size() == 0) ans.push_back(vec);
                else if (ans[0].size() == vec.size()) ans.push_back(vec); 
                continue;
            }

            for(int i = 0; i < word.size(); i++){
                char ori = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if (st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = ori;
            }
        }
        return ans;
    }
};

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
