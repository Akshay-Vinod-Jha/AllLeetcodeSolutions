/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	bool returnpath(
		TreeNode* root,
		TreeNode* tofind,
		vector<TreeNode*>& temp,
		vector<TreeNode*>& hehe
	){


		if(root==nullptr) return false;

		temp.push_back(root);

		if(root==tofind){
			hehe = temp;
            temp.pop_back();
			return true;
		}

		if(returnpath(root->left,tofind,temp,hehe)){
			temp.pop_back();
            return true;
		}


		if(returnpath(root->right,tofind,temp,hehe)){
			temp.pop_back();
            return true;
		}


        temp.pop_back();
            return false;

	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp1;
		vector<TreeNode*> temp2;
		vector<TreeNode*> first;
		vector<TreeNode*> second;

		returnpath(root,p,temp1,first);
		returnpath(root,q,temp2,second);

		int min_length_is = min(first.size(),second.size());

		TreeNode* retme = nullptr;

		for(int i=0;i<min_length_is;i++){
			if(first[i]==second[i]) retme = first[i];
			else break;
		}


		return retme;



    }
};