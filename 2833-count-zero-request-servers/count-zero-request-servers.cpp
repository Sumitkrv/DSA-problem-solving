
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Step 1: Sort logs by time
        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        // Step 2: Store queries with original indices
        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // Step 3: Frequency map and answer
        unordered_map<int,int> mp;
        vector<int> ans(queries.size());

        int left = 0, right = 0;

        // Step 4: Process sorted queries
        for(auto &[time, idx] : q) {

            // Add requests entering the window
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                mp[logs[right][0]]++;
                right++;
            }

            // Remove requests outside the window
            while(left < right &&
                  logs[left][1] < time - x) {

                int id = logs[left][0];

                mp[id]--;

                if(mp[id] == 0) {
                    mp.erase(id);
                }

                left++;
            }

            // Count inactive servers
            ans[idx] = n - mp.size();
        }

        return ans;
    }
};
