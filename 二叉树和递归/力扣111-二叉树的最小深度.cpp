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

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root == NULL)
//             return 0;

//         if(root->left != NULL && root->right != NULL)
//             return min(minDepth(root->left), minDepth(root->right)) +1;

//         else if(root->left != NULL)
//             return minDepth(root->left) +1;

//         else//root->right != NULL
//             return minDepth(root->right) +1;



//     }
// };


//优化
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        if (root->left != NULL && root->right != NULL)
            return min(minDepth(root->left), minDepth(root->right)) + 1;

        else//root->right != NULL
            return minDepth(root->left) + minDepth(root->right) + 1;
        ////这里其中一个节点为空，说明m1和m2有一个必然为0，所以可以返回m1 + m2 + 1;






    }
};

int main() {

	system("pause");
	return 0;
}
