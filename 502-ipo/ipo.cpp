class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int, int>> temp;
        for(int i=0; i<n; i++){
            temp.push_back({capital[i], profits[i]});
        }
        sort(temp.begin(), temp.end());
        priority_queue<int> pq;
        int ind=0;
        while(k--){
            while(ind<n){
                if(temp[ind].first>w){
                    break;
                }
                pq.push(temp[ind].second);
                ind++;
            }
            if(pq.empty()){
                return w;
            }
            w=w+pq.top();
            pq.pop();
        }
        return w;
    }
};