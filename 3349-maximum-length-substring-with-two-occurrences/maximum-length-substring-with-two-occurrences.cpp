class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            
            for (int j = i; j < s.size(); j++) {
                string temp = "";
                temp = temp + s.substr(i,j - i + 1);
                unordered_map<char, int> mpp;
                int length =0;
            
                for (int k = 0; k < temp.size(); k++) {
                    mpp[temp[k]]++;
                }
                bool valid=true;
                for (auto x : mpp) {
                    if (x.second > 2) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ans = max(ans, (int)temp.size());
                }
            }
        }

        return ans;
    }
};