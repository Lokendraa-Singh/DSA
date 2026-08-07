class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        for(int i=0;i<arr.size()-1;i++){

            int maxi=*max_element(arr.begin()+i+1,arr.end());
            arr[i]=maxi;
        }

        arr[arr.size()-1]=-1;
        return arr;
    }
};