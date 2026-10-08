class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<n; i++){
            minHeap.push(arr[i]);
        }
        unordered_map<int, int> mp;
        int rank=1;
        while(!minHeap.empty()){
            int x=minHeap.top();
            minHeap.pop();
            if(mp.find(x)==mp.end()){
                mp[x]=rank;
                rank++;
            }
        }
        for(int i=0; i<n; i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};