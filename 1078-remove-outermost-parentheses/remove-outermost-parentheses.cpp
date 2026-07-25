class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string temp="";
        stack<char>st;

        for(char c:s){

            if(c=='('){

                if(!st.empty()){
                    temp+=c;
                }
                st.push(c);
            }else{
                st.pop();
                if(!st.empty()){
                    temp+=c;
                }
            }
        }

        return temp;
    }
};