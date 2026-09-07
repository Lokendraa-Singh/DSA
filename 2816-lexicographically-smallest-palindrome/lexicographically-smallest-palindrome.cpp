class Solution {
public:
    string makeSmallestPalindrome(string s) {

        int i = 0;
        int j = s.size() - 1;
        string temp = s;

        while (i < j) {
            if (s[i] < s[j]) {
                temp[j] = s[i];

            } else if (s[j] < s[i]) {
                temp[i] = s[j];
            }
            i++;
            j--;
        }

        return temp;
    }
};