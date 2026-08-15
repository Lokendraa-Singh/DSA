class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>deq;
        set<int>st;
        deq.push_back(0);
        for(int i=1;i<nums.size();i++){
            
            while(!deq.empty() && deq.front()<i-k){
                deq.pop_front();
            }
            nums[i] = nums[i] + nums[deq.front()]; 
            while(!deq.empty() && nums[deq.back()]<=nums[i]){
                deq.pop_back();
            }

            deq.push_back(i);

        }

        return nums[nums.size()-1];
    }
};