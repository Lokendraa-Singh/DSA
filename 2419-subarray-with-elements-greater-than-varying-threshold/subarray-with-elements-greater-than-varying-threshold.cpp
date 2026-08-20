class Solution {
public:
    vector<int>getPSE(vector<int>&nums,int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            ans[i]=!st.empty()?st.top():-1;
            st.push(i);
        }

        return ans;
    }

    vector<int>getNSE(vector<int>&nums,int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }

            ans[i]=!st.empty()?st.top():n;
            st.push(i);
        }

        return ans;
    }

    int validSubarraySize(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        vector<int>PSE=getPSE(nums,n);
        vector<int>NSE=getNSE(nums,n);

        int ans=-1;

        for(int i=0;i<nums.size();i++){
            int size=NSE[i]-PSE[i]-1;
            double cal=(threshold/size);

            if(cal<nums[i]){
                ans=size;
                break;
            }
        }

        return ans;
    }
};