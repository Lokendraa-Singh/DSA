class Solution {
public:
    int half1(int n, string& s) {
        int count = 0;
        for (int i = 0; i < n; i++) {

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                count++;
            }
        }

        return count;
    }
    int half2(int n, string& s) {
        int count = 0;
        for (int i = n; i <s.size(); i++) {

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                count++;
            }
        }

        return count;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;

        int temp1=half1(n/2,s);
        int temp2=half2(n/2,s);

        return temp1==temp2;
    }
};