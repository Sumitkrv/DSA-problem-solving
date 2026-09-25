class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it: times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        dist[k]=0;
        pq.push({0, k});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjNode]){
                    dist[adjNode]=dis+edw;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxi=-1;
        for(int i=1; i<=n; i++){
            if(dist[i]==1e9){
                return -1;
            }
            maxi=max(maxi, dist[i]);
        }
        
        
        return maxi;


    }
};