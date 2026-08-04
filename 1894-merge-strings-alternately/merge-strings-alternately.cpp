class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int i = 0;
        int j = 0;
        string temp = "";

        while (i < word1.size() && j < word2.size()) {

            temp = temp + word1[i];
            temp = temp + word2[j];

            i++;
            j++;
        }

        if (i < word1.size()) {
            while (i < word1.size()) {
                temp = temp + word1[i];
                i++;
            }
        }

        if (j < word2.size()) {
            while (j < word2.size()) {
                temp = temp + word2[j];
                j++;
            }
        }

        return temp;
    }
};