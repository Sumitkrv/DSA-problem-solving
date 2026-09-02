class Solution {
public:
    int maxArea(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        int maxiArea=0;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxiArea=max(maxiArea, arr[element]*(nse-pse-1));
            }
            st.push(i);

        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxiArea=max(maxiArea, arr[element]*(nse-pse-1));
        }
        return maxiArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m));
        
        for(int j=0; j<m; j++){
            int sum=0;
            for(int i=0; i<n; i++){
                if(matrix[i][j]=='1'){
                    sum++;
                }
                else{
                    sum=0;
                }
                prefixSum[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans, maxArea(prefixSum[i]));
        }
        return ans;
        
    }
};