
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
//         //如果每一个叶子节点都满足二叉搜索树的性质，且当前节点大于左叶节点，小于又叶子节点
//         if(root == NULL) 
//             return true;
//         return __isValidBST(root, LONG_MIN, LONG_MAX);
//     }
// private:
//     bool __isValidBST(TreeNode* node, long lower, long upper){
//         //判断当前节点在不在 （lower,upper）范围
//         if(node == NULL)
//             return true;
//         if(node->val <= lower || node->val >= upper)
//             return false;
//         return __isValidBST(node->left, lower, node->val) && __isValidBST(node->right, node->val, upper);
//     }
// };
//中序遍历，因为顺序数组 从小到大
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //如果每一个叶子节点都满足二叉搜索树的性质，且当前节点大于左叶节点，小于又叶子节点
        if (root == NULL)
            return true;
        return inOrder(root);
    }
private:
    long pre = LONG_MIN;
    //pre 记录上个节点的值
    bool inOrder(TreeNode* node) {
        //判断当前节点在不在 （lower,upper）范围
        if (node == NULL)
            return true;
        bool leftBool = inOrder(node->left);
        if (node->val <= pre) return false;
        pre = node->val;//这里的pre不能传参数，因为上一行递归后，pre的值会变，但是没有返回，所有使用了函数全局变量
        bool rightBool = inOrder(node->right);
        return  leftBool && rightBool;
    }
};

int main() {

    system("pause");
    return 0;
}