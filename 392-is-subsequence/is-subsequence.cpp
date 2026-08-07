class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        bool temp=false;
        unordered_map<char,int>mpp;

        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){

            if(s[i]!=t[j]){
               j++;
            }else{
                mpp[s[i]]--;
                i++;
                j++;
            }
        }

        for(auto x:mpp){
            if(x.second!=0){
                return false;
            }
        }

        return true;
    }
};