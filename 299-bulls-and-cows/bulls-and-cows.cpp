class Solution {
public:
    string getHint(string secret, string guess) {

        unordered_map<char, int> mpp;
        int bulls = 0;
        int cows = 0;

        for (int i = 0; i < secret.size(); i++) {

            if(secret[i]==guess[i]){
                bulls++;
            }else{
                mpp[secret[i]]++;
            }
        }
        for (int i = 0; i < guess.size(); i++) {

            if(guess[i]!=secret[i]){
            if (mpp.find(guess[i]) != mpp.end() && mpp[guess[i]]>0) {
                cows++;
                mpp[guess[i]]--;
            }
            }
        }
        string temp=to_string(bulls)+'A'+to_string(cows)+'B';
        return temp;
    }
};