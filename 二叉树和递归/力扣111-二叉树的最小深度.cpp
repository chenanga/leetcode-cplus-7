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


//�Ż�
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
        ////��������һ���ڵ�Ϊ�գ�˵��m1��m2��һ����ȻΪ0�����Կ��Է���m1 + m2 + 1;






    }
};

int main() {

	system("pause");
	return 0;
}
