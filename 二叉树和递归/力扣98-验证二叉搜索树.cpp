
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
// ac
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         //���ÿһ��Ҷ�ӽڵ㶼������������������ʣ��ҵ�ǰ�ڵ������Ҷ�ڵ㣬С����Ҷ�ӽڵ�
//         if(root == NULL) 
//             return true;
//         return __isValidBST(root, LONG_MIN, LONG_MAX);
//     }
// private:
//     bool __isValidBST(TreeNode* node, long lower, long upper){
//         //�жϵ�ǰ�ڵ��ڲ��� ��lower,upper����Χ
//         if(node == NULL)
//             return true;
//         if(node->val <= lower || node->val >= upper)
//             return false;
//         return __isValidBST(node->left, lower, node->val) && __isValidBST(node->right, node->val, upper);
//     }
// };
//�����������Ϊ˳������ ��С����
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //���ÿһ��Ҷ�ӽڵ㶼������������������ʣ��ҵ�ǰ�ڵ������Ҷ�ڵ㣬С����Ҷ�ӽڵ�
        if (root == NULL)
            return true;
        return inOrder(root);
    }
private:
    long pre = LONG_MIN;
    //pre ��¼�ϸ��ڵ��ֵ
    bool inOrder(TreeNode* node) {
        //�жϵ�ǰ�ڵ��ڲ��� ��lower,upper����Χ
        if (node == NULL)
            return true;
        bool leftBool = inOrder(node->left);
        if (node->val <= pre) return false;
        pre = node->val;//�����pre���ܴ���������Ϊ��һ�еݹ��pre��ֵ��䣬����û�з��أ�����ʹ���˺���ȫ�ֱ���
        bool rightBool = inOrder(node->right);
        return  leftBool && rightBool;
    }
};

int main() {

    system("pause");
    return 0;
}