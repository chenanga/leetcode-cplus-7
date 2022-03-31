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

// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(root == NULL) return 0;
//         return __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);

//     }

//     int __sumOfLeftLeaves(TreeNode* root, int flag){
//         //flag = 0 Wei zuo   flag为1  为右节点
//         if(root == NULL)
//             return 0;
//         if(root->left == NULL && root->right == NULL && flag == 0) //说明该节点是左叶子节点
//             return root->val;
//         else if(root->left == NULL && root->right == NULL && flag == 1) //说明该节点是左叶子节点
//             return 0;
//         else if(root->left != NULL && root->right != NULL)
//             return   __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);
//         else if(root->left != NULL)
//             return   __sumOfLeftLeaves(root->left, 0);
//         else //(root->right != NULL)
//             return 0 + __sumOfLeftLeaves(root->right, 1);
//     }
// };

//简化代码
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        return __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);

    }

    int __sumOfLeftLeaves(TreeNode* root, int flag) {
        //flag = 0 Wei zuo   flag为1  为右节点
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL && flag == 0) //说明该节点是左叶子节点
            return root->val;
        else //其他所有情况，只要不是左叶子节点，最终都会进入root==null，返回0，
            return   __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);

    }
};

int main() {

	system("pause");
	return 0;
}


