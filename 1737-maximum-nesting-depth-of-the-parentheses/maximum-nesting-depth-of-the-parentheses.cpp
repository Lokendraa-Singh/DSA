class Solution {
public:
    int maxDepth(string s) {
        
        unordered_map<char,int>mpp;
        int count=0;
        int temp=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]==')'){
                mpp[')']++;
                temp=mpp[s[i]];
                continue;
            }

            if(s[i]=='(' && temp!=0){
                temp--;
                mpp[')']--;
                continue;
            }

            if(s[i]=='('){
                count++;
            }
        }

        return count;
    }
};