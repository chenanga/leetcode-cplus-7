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
//�������
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(root == NULL ) return 0;
//         int leftNodes = countNodes(root->left); //�����Ľڵ����
//         int rightNodes = countNodes(root->right); // �����Ľڵ����

//         return leftNodes + rightNodes + 1; //���ϸ��ڵ㱾��
//     }

// };

//�Ż�2
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        return countNodes(root->left) + countNodes(root->right) + 1; //���ϸ��ڵ㱾��
    }

};

int main() {

	system("pause");
	return 0;
}