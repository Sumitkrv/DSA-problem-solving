class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= heights.size(); i++) {

            int currHeight = (i == heights.size()) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currHeight) {

                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }
};