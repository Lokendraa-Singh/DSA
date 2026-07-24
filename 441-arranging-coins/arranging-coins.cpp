class Solution {
public:
    int arrangeCoins(int n) {
        
        int low=1;
        int high=n;
        int ans;

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(1LL*(mid*(mid+1))/2>n){
                high=mid-1;
            }else{
                ans=mid;
                low=mid+1;
            }
        }

        return ans;
    }
};