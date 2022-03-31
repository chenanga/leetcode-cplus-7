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
//         //flag = 0 Wei zuo   flagΪ1  Ϊ�ҽڵ�
//         if(root == NULL)
//             return 0;
//         if(root->left == NULL && root->right == NULL && flag == 0) //˵���ýڵ�����Ҷ�ӽڵ�
//             return root->val;
//         else if(root->left == NULL && root->right == NULL && flag == 1) //˵���ýڵ�����Ҷ�ӽڵ�
//             return 0;
//         else if(root->left != NULL && root->right != NULL)
//             return   __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);
//         else if(root->left != NULL)
//             return   __sumOfLeftLeaves(root->left, 0);
//         else //(root->right != NULL)
//             return 0 + __sumOfLeftLeaves(root->right, 1);
//     }
// };

//�򻯴���
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        return __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);

    }

    int __sumOfLeftLeaves(TreeNode* root, int flag) {
        //flag = 0 Wei zuo   flagΪ1  Ϊ�ҽڵ�
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL && flag == 0) //˵���ýڵ�����Ҷ�ӽڵ�
            return root->val;
        else //�������������ֻҪ������Ҷ�ӽڵ㣬���ն������root==null������0��
            return   __sumOfLeftLeaves(root->left, 0) + __sumOfLeftLeaves(root->right, 1);

    }
};

int main() {

	system("pause");
	return 0;
}


