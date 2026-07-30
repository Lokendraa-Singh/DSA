class Solution {
public:
    int minimumPushes(string word) {
        
        if(word.size()<=8){
            return word.size();
        }
        
        int temp=1;
        int count=0;
        for(int i=0;i<word.size();i++){

           if(i==8){
            temp=2;
           }else if(i==16){
            temp=3;
           }else if(i==24){
            temp=4;
           }
            count=count+temp;
           
        }

        return count;
    }
};