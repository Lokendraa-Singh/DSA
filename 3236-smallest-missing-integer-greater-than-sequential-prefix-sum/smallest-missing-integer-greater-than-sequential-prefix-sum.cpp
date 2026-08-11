class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0]+1;
        }
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int j;
        vector<int> ans;
        int sum = 0;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1] + 1) {
                j = i;
            } else {
                break;
            }
        }

        for (int i = 0; i <= j; i++) {
            sum = sum + nums[i];
            ans.push_back(nums[i]);
        }

        bool temp=true;  
        while(temp){
            if(mpp.find(sum)==mpp.end()){
                return sum;
            }

            sum++;
        }

        return -1;
    }
};