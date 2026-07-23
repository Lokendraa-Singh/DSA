class Solution {
public:
    bool calTrips(vector<int>& time, long long mid, int totalTrips) {

        long long trips = 0;

        for (int t : time) {
            trips += mid / t;

            if (trips >= totalTrips)
                return true;
        }

        return false;
    }

    long long sum(vector<int>&time){
        long long summ=0;

        for(int i=0;i<time.size();i++){
            summ=summ+time[i];
        }
        return summ;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long low =1;
       long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long ans;

        while (low <= high) {
            long long mid = low+(high-low) / 2;

            if (calTrips(time, mid, totalTrips) == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};