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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> level;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;
        while (!q.empty()) {
            int sz = q.size();
            level.clear();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node);

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        vector<vector<TreeNode*>> ancestors;
        int smallest = INT_MAX;
        for (TreeNode* node : level) {
            vector<TreeNode*> path;
            while (node) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            ancestors.push_back(path);
            smallest = min(smallest, (int)path.size());
        }

        TreeNode* lastsuccess = nullptr;
        for (int i = 0; i < smallest; i++) {
            TreeNode* tocompare = ancestors[0][i];
            for (int j = 1; j < ancestors.size(); j++) {
                if (ancestors[j][i] != tocompare) {
                    return lastsuccess;
                }
            }
            lastsuccess = tocompare;
        }

        return lastsuccess;
    }
};