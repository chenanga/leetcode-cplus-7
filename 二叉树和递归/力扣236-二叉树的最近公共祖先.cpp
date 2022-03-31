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

//  //�����ⷨ
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //�������⣬���ҵĽڵ�һ�������ڶ�������
//         if(findNode(root->left, p) && findNode(root->left, q))  //��������������ҵ�
//             return lowestCommonAncestor(root->left, p, q);

//         if(findNode(root->right, p) && findNode(root->right, q))//��������������ҵ�
//             return lowestCommonAncestor(root->right, p, q);

//         return root; //����������û�ҵ�����ǰrootΪ�����  
//     }
// private:
//     bool findNode(TreeNode* root, TreeNode* node){
//         //��ʾ�ܷ��ڵ�ǰ��rootΪ���Ķ������У��ҵ�node�ڵ�
//         if(root == NULL) 
//             return false;
//         if(root->val == node->val)
//             return true;
//         return findNode(root->left, node) || findNode(root->right, node);
//     }
// };

//  //k�� DFS�� ����������LCA���� 
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //����rootΪ���ڵ�����У�Ѱ��p��q������������ȣ����� ���ؿ�
//         //���У�3�����
//         //1��p��q�ֱ�λ��root����������
//         //2��pΪroot��qΪ��������
//         //3��qΪroot��pΪ��������
//         if(root == NULL)
//             return NULL;
//         if(root == q)
//             return q;
//         if(root == p)
//             return p;

//         TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
//         TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

//         if(leftNode == NULL && rightNode == NULL) return NULL;
//         if(leftNode == NULL)
//             return rightNode;
//         if(rightNode == NULL)
//             return leftNode;

//         //���߶���Ϊ��
//         return root;

//     }
// };

//k�� DFS--�Ż����ִ���ṹ�� ����������LCA���� 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //����rootΪ���ڵ�����У�Ѱ��p��q������������ȣ����� ���ؿ�
        //���У�3�����
        //1��p��q�ֱ�λ��root����������
        //2��pΪroot��qΪ��������
        //3��qΪroot��pΪ��������
        if (root == NULL || root == q || root == p) //�ϲ�����if
            return root;

        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        // if(leftNode == NULL && rightNode == NULL) return NULL; //�˴������ʡ�ԣ���Ϊ���leftNodeΪNULL��������һ��if��䣬Ȼ�󷵻�rightNode������rightNodeΪ�գ�����Ч��һ��
        if (leftNode == NULL)
            return rightNode;
        if (rightNode == NULL)
            return leftNode;

        //���߶���Ϊ��
        return root;

    }
};

int main() {

	system("pause");
	return 0;
}