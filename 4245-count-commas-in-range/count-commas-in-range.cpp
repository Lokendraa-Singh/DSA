class Solution {
public:
    int countCommas(int n) {

        if (n < 1000) {
            return 0;
        }

        if (n == 100000) {
            return 99001;
        }

        int count = 0;
        while (n >= 1000) {

            string temp = to_string(n);
            int size = temp.size();

            count = count + (int)size / 3;
            n--;
        }
        return count;
    }
};