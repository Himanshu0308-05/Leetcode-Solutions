class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        vector<int> s(3),l(3);

        std::ranges::partial_sort_copy(nums,s);
        std::ranges::partial_sort_copy(nums,l,greater{});

        return min({
            l[0] - s[2],

            l[1] - s[1],

            l[2] - s[0]

        });
        
    }
};