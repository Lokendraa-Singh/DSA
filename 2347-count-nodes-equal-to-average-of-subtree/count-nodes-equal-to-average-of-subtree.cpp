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
    int count;

    pair<int, int> dfsAvg(TreeNode* root) {

        if (root == NULL) {

            return {0, 0};
        }

        auto left = dfsAvg(root->left);
        auto right = dfsAvg(root->right);

        int sum = left.first + right.first + root->val;
        int count1 = left.second + right.second + 1;

        double avg = floor(double(sum) / count1);

        if (avg == root->val) {

            count++;
        }

        return {floor(sum), count1};
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        dfsAvg(root);
        return count;
    }
};