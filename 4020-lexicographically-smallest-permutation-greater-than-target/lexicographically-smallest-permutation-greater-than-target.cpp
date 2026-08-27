class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int freq[26] = {};

        // Frequency of characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        int pivot = -1;
        char bigger;

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Check if we can make target[0...i-1]
            if (freq[x] == 0) {

                // We cannot match target[i],
                // but we can still try to make this
                // position bigger.
                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        pivot = i;
                        bigger = 'a' + c;
                        break;
                    }
                }

                break;
            }

            // Before consuming target[i],
            // check if we can make this position bigger.
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    pivot = i;
                    bigger = 'a' + c;
                    break;
                }
            }

            // Use target[i] to continue matching the prefix
            freq[x]--;
        }

        // No possible permutation
        if (pivot == -1) {
            return "";
        }

        // Recreate frequency array
        int cnt[26] = {};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans;

        // Keep target prefix unchanged
        for (int i = 0; i < pivot; i++) {
            ans += target[i];
            cnt[target[i] - 'a']--;
        }

        // Put the smallest character greater than target[pivot]
        ans += bigger;
        cnt[bigger - 'a']--;

        // Put remaining characters in sorted order
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                ans += char('a' + c);
                cnt[c]--;
            }
        }

        return ans;
    }
};