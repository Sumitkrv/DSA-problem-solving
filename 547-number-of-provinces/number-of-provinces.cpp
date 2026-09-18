class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& isConnected){
        vis[node]=1;
        for(int it=0; it<isConnected.size(); it++){
            if(isConnected[node][it]==1 && !vis[it]){
                dfs(it, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};