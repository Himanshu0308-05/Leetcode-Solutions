
class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& mp) {

        if (root == NULL)
            return 0;

        if (mp.count(root))
            return mp[root];

      
        int take = root->val;

        if (root->left) {
            take += solve(root->left->left, mp);
            take += solve(root->left->right, mp);
        }

        if (root->right) {
            take += solve(root->right->left, mp);
            take += solve(root->right->right, mp);
        }

       
        int notTake = solve(root->left, mp)
                    + solve(root->right, mp);

        return mp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return solve(root, mp);
    }
};
