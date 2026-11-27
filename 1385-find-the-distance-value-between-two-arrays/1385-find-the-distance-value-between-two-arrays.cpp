class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for (int i = 0; i < arr1.size(); i++) {
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);

            int idx = it - arr2.begin();

            bool valid = true;

            if (idx < arr2.size() && abs(arr1[i] - arr2[idx]) <= d)
                valid = false;

            if (idx > 0 && abs(arr1[i] - arr2[idx - 1]) <= d)
                valid = false;

            if (valid)
                ans++;
        }

        return ans;
    }
};