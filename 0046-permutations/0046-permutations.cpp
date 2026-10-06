class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums , vector<int> &ds, vector<int> &vis){
        if(ds.size() == nums.size()){
            ans.push_back(ds);

            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(vis[i] == 0){
                vis[i] = 1;
                ds.push_back(nums[i]);
                solve(nums,ds,vis);
                ds.pop_back();
                vis[i] = 0;

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<int> vis(n,0);
        solve(nums,ds,vis);
        return ans;


        
    }
};