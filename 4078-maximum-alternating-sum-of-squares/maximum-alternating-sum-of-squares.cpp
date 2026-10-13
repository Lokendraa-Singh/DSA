class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());
        long long greater = 0;
        long long smaller = 0;
        long long i = 0;
        long long j = nums.size() - 1;

        while (i <= j) {
            if (i == j) {
                greater = greater + nums[j];
            }
            greater = greater + nums[j];
            smaller = smaller + nums[i];

            i++;
            j--;
        }

        return greater - smaller;
    }
};