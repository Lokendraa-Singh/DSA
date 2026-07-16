class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt = 0;
        vector<int> ans;
        ans.push_back(currAlt);
        for (int i = 0; i < gain.size(); i++) {
            currAlt = currAlt + gain[i];
            ans.push_back(currAlt);
        }
        int Max = *max_element(ans.begin(), ans.end());
        return Max;
    }
};