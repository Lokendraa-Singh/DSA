class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum=0;
        int prod=1;
        int temp=n;

        while(n!=0){
            int r=n%10;
            sum=sum+r;
            prod=prod*r;
            n=n/10;
        }

        sum=sum+prod;

        return temp%sum==0;
    }
};