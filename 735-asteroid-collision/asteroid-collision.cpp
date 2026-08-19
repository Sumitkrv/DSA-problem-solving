class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int current : asteroids) {

            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && current < 0) {

                if (st.top() < -current) {
                    // Top asteroid is smaller
                    st.pop();
                }
                else if (st.top() == -current) {
                    // Both are destroyed
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(current);
            }
        }

        vector<int> ans(st.size());

        // Stack is in reverse order
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};