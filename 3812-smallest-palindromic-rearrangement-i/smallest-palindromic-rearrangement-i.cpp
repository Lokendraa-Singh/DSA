class Solution {
public:
    string smallestPalindrome(string s) {

        if (s.size() == 1) {

            return s;
        }
        string s1 = "";

        int n = s.size();
        
        for(int i=0;i<n/2;i++){
            s1+=s[i];
        }
        sort(s1.begin(),s1.end());
        
        string rev=s1;
        reverse(rev.begin(),rev.end());

        if(n%2!=0){

            return s1+s[n/2]+rev;
        }
        return s1+rev;
    }
};