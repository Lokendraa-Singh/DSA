class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int len = INT_MAX;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            int count = 0;
            for (int j = i; j < s.size(); j++) {

                if (s[j] == '1') {
                    count++;
                }

                if (count == k) {
                    int ansLen = j - i + 1;
                    string curr = s.substr(i, j - i + 1);

                    if (ansLen < len || (ansLen == len && curr < temp)) {
                        len = ansLen;
                        temp = s.substr(i, j - i + 1);
                    }
                    break;
                }
            }
        }

        return temp;
    }
};