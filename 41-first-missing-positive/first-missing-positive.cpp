class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        vector<int>stores;
        for(int i=0;i<nums.size();i++){

            if(nums[i]>0 && nums[i]!=0){    
                stores.push_back(nums[i]);
            }
        }
      
        sort(stores.begin(),stores.end());

        int temp=1;

        for(int i=0;i<stores.size();i++){

            if(stores[i]==temp){
                temp++;
            }
        }

        return temp;
    }
};