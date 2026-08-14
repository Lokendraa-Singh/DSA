class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int j = 0;
        int ans = 0;
        unordered_map<char, int> mpp;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;

            if (mpp[s[i]] > 2) {
                while (mpp[s[i]] > 2) {
                    mpp[s[j]]--;
                    j++;
                }
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};