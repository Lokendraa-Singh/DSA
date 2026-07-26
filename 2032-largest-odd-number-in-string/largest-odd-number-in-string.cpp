class Solution {
public:
    string largestOddNumber(string num) {
        
        int i=0;
        string temp="";

       
        for(int j=num.size()-1;j>=0;j--){

            if((num[j]-'0')%2!=0){
               return temp+=num.substr(i,j-i+1);
            }
        }

        return temp;

    }
};