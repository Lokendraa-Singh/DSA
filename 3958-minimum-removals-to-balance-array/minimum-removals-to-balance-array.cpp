class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int i = 0;
        int j = i+1;
        int ans=1;
        sort(nums.begin(), nums.end());

        while (i < nums.size() && j<nums.size()) {
            
            if(nums[j]<=1LL*nums[i]*k){
                ans=max(ans,j-i+1);
                j++;
            }else{
                i++;
            }
        }

        return nums.size()-ans;
    }
};