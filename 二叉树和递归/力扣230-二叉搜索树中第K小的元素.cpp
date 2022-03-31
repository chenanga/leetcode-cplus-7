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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
private:
    int curIndex = 1;

    int inorder(TreeNode* root, int k) {
        //���ظ�Ԫ�ص�ֵ
        if (root == NULL) return -1;

        int leftRet = inorder(root->left, k);
        if (leftRet != -1)
            return leftRet; //������-1��˵���ҵ���

        if (curIndex == k)
            return root->val;
        curIndex++;

        int rightRet = inorder(root->right, k);
        if (rightRet != -1)
            return rightRet; //������-1��˵���ҵ���

        return -1; //û�ҵ�������-1
    }

};

int main() {

	system("pause");
	return 0;
}