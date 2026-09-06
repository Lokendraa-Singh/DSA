class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        vector<pair<float, vector<int>>> v;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                float fraction = (float)arr[i] / arr[j];

                v.push_back({fraction, {arr[i], arr[j]}});
            }
        }

        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.first < b.first; });

        return v[k - 1].second;
    }
};