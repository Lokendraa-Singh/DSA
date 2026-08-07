class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
       int n=prices.size(); 
       stack<int>st;

       for(int i=n-1;i>=0;i--){
        int c=prices[i];
        while(!st.empty() && st.top()>c){
            st.pop();
        }

        if(!st.empty()){
            prices[i]=prices[i]-st.top();
        }

        st.push(c);
       }

       return prices;
    }
};