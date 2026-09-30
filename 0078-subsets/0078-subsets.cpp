class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

      
        solve(idx + 1, nums, temp);

        
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp);

        temp.pop_back(); 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        // sort(ans.begin() , ans.end());

        return ans;
    }
};