#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(to_string(root->val));
            return res;
        }

        vector<string> leftStr = binaryTreePaths(root->left);
        for (int i = 0; i < leftStr.size(); i++)
            res.push_back(to_string(root->val) + "->" + leftStr[i]);

        vector<string> rightStr = binaryTreePaths(root->right);
        for (int i = 0; i < rightStr.size(); i++)
            res.push_back(to_string(root->val) + "->" + rightStr[i]);

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}