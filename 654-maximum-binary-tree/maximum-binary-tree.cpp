/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaxTree(vector<int>& nums, int start, int end) {

        if (start > end) {
            return NULL;
        }
        int index = -1;
        int val = -1;
        for (int i = start; i <= end; i++) {
            if (nums[i] > val) {
                index = i;
                val = nums[i];
            }
        }

        TreeNode* root = new TreeNode(val);
        root->left = constructMaxTree(nums, start, index - 1);
        root->right = constructMaxTree(nums, index + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return constructMaxTree(nums, 0, nums.size() - 1);
    }
};