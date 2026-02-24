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
    int helperfun(TreeNode* root,string s){

        if(root->left==nullptr && root->right==nullptr){

            s = s+to_string(root->val);
            int len = s.length();
            long long res = 0;
            for(int i=len-1;i>=0;i--){
                res += pow(2,i)*(s[len-1-i]-'0');
            }
            return res;
        }

        int res1 = 0 , res2 = 0;
        if(root->left){
            res1 = helperfun(root->left,s+to_string(root->val));
        }
        if(root->right){
            res2 = helperfun(root->right,s+to_string(root->val));
        }

        return res1 + res2;

    }

    int sumRootToLeaf(TreeNode* root) {
        
        if(root==nullptr) return 0;

        return helperfun(root,"");
    }
};