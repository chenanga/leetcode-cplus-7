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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return __isSymmetric(root->left, root->right);
    }

private:
    bool __isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL)
            return false;
        else if (right == NULL)
            return false;
        //˼���Ǻ��ж������������Ƿ���ͬһ�������������һ�����������������������������������Ա�
        return left->val == right->val && __isSymmetric(left->left, right->right) && __isSymmetric(left->right, right->left);

    }

};

int main() {

	system("pause");
	return 0;
}