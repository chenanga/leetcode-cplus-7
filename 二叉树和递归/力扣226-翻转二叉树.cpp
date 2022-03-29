#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //反转以root为节点的二叉树
        if (root == NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        return root;
    }
};

int main() {

	system("pause");
	return 0;
}