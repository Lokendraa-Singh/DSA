class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        long long maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                if (((1LL * nums[i] * nums[j]) /
                     pow(gcd(nums[i], nums[j]), 2)) > maxi) {

                    maxi = (1LL * nums[i] * nums[j]) /
                           pow(gcd(nums[i], nums[j]), 2);
                }
            }
        }

        return maxi;
    }
};