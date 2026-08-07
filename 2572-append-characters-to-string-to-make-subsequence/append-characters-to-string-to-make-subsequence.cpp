class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int i=0;
        int j=0;
        int count=0;

        while(i<s.size() && j<t.size()){

            if(s[i]!=t[j]){
              i++;
            }else{
                i++;
                j++;
            }
        }

        return t.size()-j;

        
    }
};