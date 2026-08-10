class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(),asteroids.end());
        bool temp=false;
        long long ans=mass;

        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=ans){
            ans=ans+asteroids[i];
                temp=true;
            }else{
               temp=false;
            }
        }

        return temp;
    }
};