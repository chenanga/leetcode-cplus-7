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

//  //暴力解法
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //根据题意，待找的节点一定存在于二叉树中
//         if(findNode(root->left, p) && findNode(root->left, q))  //如果能在左子树找到
//             return lowestCommonAncestor(root->left, p, q);

//         if(findNode(root->right, p) && findNode(root->right, q))//如果能在右子树找到
//             return lowestCommonAncestor(root->right, p, q);

//         return root; //左右子树都没找到，当前root为最近的  
//     }
// private:
//     bool findNode(TreeNode* root, TreeNode* node){
//         //表示能否在当前以root为根的二叉树中，找到node节点
//         if(root == NULL) 
//             return false;
//         if(root->val == node->val)
//             return true;
//         return findNode(root->left, node) || findNode(root->right, node);
//     }
// };

//  //k神 DFS， 此类问题是LCA问题 
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //在以root为根节点的树中，寻找p，q的最近公共祖先，若无 返回空
//         //若有，3种情况
//         //1、p和q分别位于root的左右两侧
//         //2、p为root，q为左右两侧
//         //3、q为root，p为左右两测
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

//         //两者都不为空
//         return root;

//     }
// };

//k神 DFS--优化部分代码结构， 此类问题是LCA问题 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //在以root为根节点的树中，寻找p，q的最近公共祖先，若无 返回空
        //若有，3种情况
        //1、p和q分别位于root的左右两侧
        //2、p为root，q为左右两侧
        //3、q为root，p为左右两测
        if (root == NULL || root == q || root == p) //合并三个if
            return root;

        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        // if(leftNode == NULL && rightNode == NULL) return NULL; //此处这个可省略，因为如果leftNode为NULL，进入下一个if语句，然后返回rightNode，但是rightNode为空，所有效果一样
        if (leftNode == NULL)
            return rightNode;
        if (rightNode == NULL)
            return leftNode;

        //两者都不为空
        return root;

    }
};

int main() {

	system("pause");
	return 0;
}