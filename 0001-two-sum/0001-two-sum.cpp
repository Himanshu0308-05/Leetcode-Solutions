class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0 ; i<n; i++){
            mp[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
            int val = target - nums[i];

            if( mp.find(val) != mp.end() ){
                auto it = mp.find(val);

                int key = it->second;

                if(key == i) continue;

                if( key > i){
                    ans.push_back(i);
                    ans.push_back(key);
                    break;
                }
                else{
                    ans.push_back(key);
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};