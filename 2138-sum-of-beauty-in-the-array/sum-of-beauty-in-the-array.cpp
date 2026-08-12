class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        // int sum=0;
        // for (int i = 1; i <= nums.size() - 2; i++) {

        //     bool check1 = false;
        //     bool check2=false;
        //     int temp = nums[i];
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < temp) {
        //             check1 = true;
        //         } else {
        //             check1 = false;
        //             break;
        //         }
        //     }

        //     for (int k = i + 1; k <= nums.size() - 1; k++) {
        //         if (nums[k] > temp) {
        //             check2 = true;
        //         } else {
        //             check2 = false;
        //             break;
        //         }
        //     }

        //     if (check1 && check2) {
        //         sum = sum + 2;
        //     }else{
        //         if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
        //             sum = sum + 1;
        //         } else {
        //             sum = sum + 0;
        //         }
        //     }
        // }

        // return sum; 
        int sum = 0;
        int n = nums.size();
        vector<int> rightMin(n);
        vector<int> leftMax(n);

        leftMax[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        for (int i = 1; i <= nums.size() - 2; i++) {

            int temp = nums[i];
            if (temp > leftMax[i-1] && temp < rightMin[i+1]) {
                sum = sum + 2;
            } else if (temp > nums[i - 1] && temp < nums[i + 1]) {
                sum = sum + 1;
            } else {
                sum = sum + 0;
            }
        }

        return sum;
    }
};