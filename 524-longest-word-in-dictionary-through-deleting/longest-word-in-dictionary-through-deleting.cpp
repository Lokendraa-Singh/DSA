#include <algorithm>

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        unordered_map<string, int> mpp;
        int maxSize = INT_MIN;
        for (int i = 0; i < dictionary.size(); i++) {

            string temp = dictionary[i];
            string store = s;
            int j = 0;
            int k = 0;
            int count = 0;

            while (j < store.size() && k < temp.size()) {
                if (store[j] == temp[k]) {
                    j++;
                    k++;
                } else {
                    count++;
                    j++;
                }
            }

            if (k == temp.size()) {
                mpp[temp] = count;
                maxSize = max(maxSize, (int)temp.size());
            }
        }

        string ans = "";
        bool check = false;
        for (auto x : mpp) {
            if (x.first.size() == maxSize && x.second >= 0 && check == false) {

                ans = x.first;
                check = true;
            } else if (x.first.size() == maxSize && x.second >= 0 &&
                       check == true) {

                if (x.first < ans) {
                    ans = x.first;
                }
            }
        }

        return ans;
    }
};