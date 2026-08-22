class Solution {
public:
    string reverseWords(string s) {

        string temp = "";
        string result = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } else {

                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());

                    if (!result.empty()) {
                        result = result + ' ';
                    }
                    result = result + temp;
                    temp = "";
                }
            }
        }

        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());

            if (!result.empty())
                result += ' ';

            result += temp;
        }

        return result;
    }
};