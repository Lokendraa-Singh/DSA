class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string temp=strs[0];
        
    
        for(int i=1;i<strs.size();i++){

            string ans=strs[i];
            
            int j=0;

            while(j<ans.size() && j<temp.size() && temp[j]==ans[j]){
                j++;
            }

            temp=temp.substr(0,j);

            if(temp==""){
                return "";
            }
        }

        return temp;
    }
};