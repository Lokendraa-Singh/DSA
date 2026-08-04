class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        vector<int> result;
        sort(nums.begin(), nums.end());

        for (int i = min; i <= max; i++) {
            bool temp = false;
            for (int j = 0; j < nums.size(); j++) {
                if(i==nums[j]){
                    temp=true;
                    break;
                }
            }

            if(temp==false){
                result.push_back(i);
            }
        }

        return result;
    }
};