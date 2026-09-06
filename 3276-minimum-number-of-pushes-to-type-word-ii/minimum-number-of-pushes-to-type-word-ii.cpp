class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char, int> mp;
        for(char ch: word){
            mp[ch]++;
        }
        vector<int> freq;
        for(auto it: mp){
            freq.push_back(it.second);
        }
        sort(freq.rbegin(), freq.rend());

        int ans=0;
        int cnt=0;
       for(int i=0; i<freq.size(); i++){
        int pushes=cnt/8+1;
        ans+=pushes*freq[i];
        cnt++;
       }
        return ans;
    }
};