class Solution {
public:
    bool isBalanced(unordered_map<char, int>& mpp) {

        int temp = mpp.begin()->second;

        for (auto it : mpp) {
            if (it.second != temp) {
                return false;
            }
        }

        return true;
    }
    int longestBalanced(string s) {

        int n = s.size();

        int maxLen = INT_MIN;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;

            for (int j = i; j < n; j++) {
                mpp[s[j]]++;

                if (isBalanced(mpp)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};