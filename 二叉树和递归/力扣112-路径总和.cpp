#include<iostream>


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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) return targetSum == root->val;//注意递归终止条件，如果左右子树都为空，说明是叶子节点

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);


    }
};

int main() {

	system("pause");
	return 0;
}