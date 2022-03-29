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
//  //�Զ�����
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL) return true;

//         return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//         //����ע�⣬ȷ�����������߶Ȳ�С��1��Ȼ��������������ƽ��������Ϊ��
//     }
// private:
//     int height(TreeNode* root){
//         //���ظýڵ�����������
//         if(root == NULL) return 0;
//         int leftDepth = height(root->left);
//         int rightDepth = height(root->right);
//         return max(leftDepth, rightDepth) + 1;
//     }
// };

//�Ե�����
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        return height(root) >= 0;
        //����ע�⣬ȷ�����������߶Ȳ�С��1��Ȼ��������������ƽ��������Ϊ��
    }
private:
    int height(TreeNode* root) {
        //���ظýڵ�����������
        if (root == NULL) return 0;
        int leftDepth = height(root->left);
        int rightDepth = height(root->right);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
            return -1;
        else return max(leftDepth, rightDepth) + 1;
    }
};

int main() {

	system("pause");
	return 0;
}