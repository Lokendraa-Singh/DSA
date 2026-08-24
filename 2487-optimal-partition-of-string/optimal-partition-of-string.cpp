class Solution {
public:
    int partitionString(string s) {

        unordered_map<char, int> mpp;

        int count = 1;

        for (int i = 0; i < s.size(); i++) {

            if (mpp.find(s[i]) != mpp.end()) {
                count++;

                mpp.clear();
            }

            mpp[s[i]] = i;
        }

        return count;
    }
};