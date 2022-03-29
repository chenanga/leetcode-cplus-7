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
//容易理解
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(root == NULL ) return 0;
//         int leftNodes = countNodes(root->left); //左树的节点个数
//         int rightNodes = countNodes(root->right); // 右树的节点个数

//         return leftNodes + rightNodes + 1; //加上根节点本身
//     }

// };

//优化2
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        return countNodes(root->left) + countNodes(root->right) + 1; //加上根节点本身
    }

};

int main() {

	system("pause");
	return 0;
}