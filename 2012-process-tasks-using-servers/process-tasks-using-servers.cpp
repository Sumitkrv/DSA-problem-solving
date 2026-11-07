
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int i = 0; i < m; i++) {

            // Maintain current processing time
            time = max(time, (long long)i);

            // Release completed servers
            while(!busy.empty() && get<0>(busy.top()) <= time) {

                auto [freeTime, weight, idx] = busy.top();
                busy.pop();

                available.push({weight, idx});
            }

            // If all servers are busy, wait
            if(available.empty()) {

                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, idx] = busy.top();
                    busy.pop();

                    available.push({weight, idx});
                }
            }

            // Assign the best available server
            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;

            // Update server's completion time
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};
