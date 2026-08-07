class Solution {
public:
    int trap(vector<int>& height) {
        
        int left=0;
        int right=height.size()-1;
        int sum=0;

        int leftMax=height[0];
        int rightMax=height[height.size()-1];

        while(left<right){

            if(leftMax<rightMax){
                left++;
                leftMax=max(leftMax,height[left]);
                sum=sum+leftMax-height[left];
            }else{
                right--;
                rightMax=max(rightMax,height[right]);
                sum=sum+rightMax-height[right];
            }
        }

        return sum;

    }
};