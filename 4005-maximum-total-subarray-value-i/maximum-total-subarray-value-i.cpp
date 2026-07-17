class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        int maxElement=*max_element(nums.begin(),nums.end());
        int minElement=*min_element(nums.begin(),nums.end());

        long long diff=maxElement-minElement;

        return diff*k;
    }
};