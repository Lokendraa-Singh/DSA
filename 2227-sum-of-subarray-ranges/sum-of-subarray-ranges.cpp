class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long totalSum=0;
        for(int i=0;i<nums.size();i++){
            int mini=nums[i];
            int maxi=nums[i];

            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);

                long long diff=(maxi-mini);
                totalSum=totalSum+diff;
            }
        }

        return totalSum;
    }
};