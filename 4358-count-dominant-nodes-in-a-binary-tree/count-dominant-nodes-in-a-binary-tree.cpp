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
int count=0;
    int countleafNodes(TreeNode*root){
        
        if(root==NULL){
            return 0;
        }

       int left=  countleafNodes(root->left);
       int right= countleafNodes(root->right);

       int maxx=max(root->val,max(left,right));

       if(root->val==maxx){
        count++;
       }

       return maxx;


    } 

    int countDominantNodes(TreeNode* root) {
        
        countleafNodes(root);
        // maxvalNode(root);

        return count;
    }
};