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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        //��������������
        if (p->val < root->val && q->val < root->val) //p q��zuo��
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)// p q ���Ҳ�
            return lowestCommonAncestor(root->right, p, q);

        return root;//��ʱ�����ֿ���
        //1��p��qһ��һ�ң���������ڵ����root
        //2��p��������ң� qΪroot����������ڵ����root
        //3��q��������ң� pΪroot����������ڵ����root

    }
};

int main() {

	system("pause");
	return 0;
}