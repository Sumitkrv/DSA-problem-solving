class Solution {
public:
    char findTheDifference(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        int n=s.size(), m=t.size();
        //int i=0, j=0;
        unordered_map<char, int> mp;
        for(int i=0; i<m; i++){
            mp[t[i]]++;
        }
        for(int i=0; i<n; i++){
            mp[s[i]]--;
        }
        for(auto it: mp){
            if(it.second!=0){
                return it.first;
            }
        }


        
        
        return 'a';
    }
};