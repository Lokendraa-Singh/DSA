class Solution {
public:
    int maxProduct(int n) {
        
        vector<int>ans;
        while(n!=0){
            int temp=n%10;
            ans.push_back(temp);
            n=n/10;
        }

        sort(ans.begin(),ans.end());
        int m=ans.size();
        return ans[m-1]*ans[m-2];
    }
};