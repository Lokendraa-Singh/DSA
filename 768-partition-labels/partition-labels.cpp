class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> mpp;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }

        int i = 0;
        int j =  mpp[s[i]];
        int l = 0;
        vector<int>ans;

        while (i < s.size()) {


            j=max(j,mpp[s[i]]);

            if(mpp[s[i]]<=mpp[s[j]]){
                i++;
            }

            if(i>j){
                ans.push_back(j-l+1);
                l=i;
            }
        }

        return ans;
    }
};