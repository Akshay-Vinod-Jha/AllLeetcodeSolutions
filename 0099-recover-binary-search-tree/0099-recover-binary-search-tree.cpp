class Solution {
public:
    void lrootr(TreeNode* root, vector<int>& v) {
        if (!root) return;
        lrootr(root->left, v);
        v.push_back(root->val);
        lrootr(root->right, v);
    }

    TreeNode* getNode(TreeNode* root, int value, bool &used) {
        if (!root) return nullptr;
        TreeNode* left = getNode(root->left, value, used);
        if (left) return left;
        if (!used && root->val == value) {
            used = true;
            return root;
        }
        return getNode(root->right, value, used);
    }

    void recoverTree(TreeNode* root) {
        vector<int> before;
        lrootr(root, before);
        vector<int> after = before;
        sort(after.begin(), after.end());
        int length = before.size();
        int first = INT_MIN, second = INT_MIN;
        for (int i = 0; i < length; i++) {
            if (before[i] != after[i]) {
                if (first == INT_MIN) first = before[i];
                else second = before[i];
            }
        }
        if (second == INT_MIN)
            second = first;
        bool used1 = false, used2 = false;
        TreeNode* n1 = getNode(root, first, used1);
        TreeNode* n2 = getNode(root, second, used2);
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};
