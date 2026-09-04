class Solution {
public:
    int compress(vector<char>& chars) {

        int i = 0;
        int j = 0;

        vector<char> ans;
        int length;

        while (i < chars.size() && j < chars.size()) {

            if (chars[i] == chars[j]) {
                j++;
            } else {
                ans.push_back(chars[i]);
                length = j - i;
                i = j;

                if (length > 9) {

                    string s = to_string(length);
                    for (char ch : s) {
                        ans.push_back(ch);
                    }

                } else if (length > 1 && length <= 9) {
                    char ch = length + '0';
                    ans.push_back(ch);
                }
            }
        }

        ans.push_back(chars[i]);
        length = j - i;
        i = j;

        if (length > 9) {
            string s = to_string(length);

            for (char ch : s) {
                ans.push_back(ch);
            }
        } else if (length > 1 && length <= 9) {
            char ch = length + '0';
            ans.push_back(ch);
        }

        for (int k = 0; k < ans.size(); k++) {
            chars[k] = ans[k];
        }

        return ans.size();
    }
};