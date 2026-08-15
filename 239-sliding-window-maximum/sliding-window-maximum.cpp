class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>deq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {

            // new ele ke liye window meh space bnana front ele ko remove krke
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // check krna back ele dequeu meh chota hh toh pop krdo
            while (!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }

            deq.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};