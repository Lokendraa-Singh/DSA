class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        vector<int> maxArray(n);

        maxArray[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxArray[i] = max(maxArray[i + 1], nums[i]);
        }

        int i = 0;
        int j = 0;
        int ans=INT_MIN;

        while (i < n && j < n) {
            if (nums[i] <= maxArray[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};