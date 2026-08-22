class Solution {
public:
    int M=1e9+7;
    int numSubseq(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        long long ans = 0;
        int n=nums.size();
        vector<int>power(n);

        sort(nums.begin(), nums.end());

        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%M;
        }

        while (l <= r) {

            if (nums[l] + nums[r] > target) {
                r--;
            }
            else {
                int diff = r - l;
                ans = (ans%M + power[diff])%M;

                l++;
            }
        }

        int M = 1e9 + 7;

        return ans % M;
    }
};