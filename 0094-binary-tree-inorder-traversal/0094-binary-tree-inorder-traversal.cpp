/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> pre;
        vector<int> post;
        vector<int> in;
        stack<pair<TreeNode*, int> > s;
        s.push({root, 1});

        if(root == nullptr) return in;


        while(!s.empty()){

            auto it = s.top();
            s.pop();
            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                s.push(it);
                if(it.first->left != nullptr) 
                s.push({it.first->left ,1});
            }
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                s.push(it);
                if(it.first->right != nullptr) 
                s.push({it.first->right ,1 });
            }
            else{
                post.push_back(it.first->val);
            }
        }

    return in;

    }
};