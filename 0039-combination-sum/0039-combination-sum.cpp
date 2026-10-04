class Solution {
public:
    void solve(int idx, int target, vector<int>&temp,vector<vector<int>> &ans,vector<int>&candidates , int n){
        if(idx == n || target == 0){
            if(target == 0){
                ans.push_back(temp);
            }

            return;
        }
        if( candidates[idx] <= target){
        temp.push_back(candidates[idx]);
        solve(idx, target-candidates[idx],temp,ans,candidates,n);
        temp.pop_back();
        }
        solve(idx+1, target,temp,ans,candidates,n);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(0,target,temp,ans,candidates,n);

        return ans;
    }
};