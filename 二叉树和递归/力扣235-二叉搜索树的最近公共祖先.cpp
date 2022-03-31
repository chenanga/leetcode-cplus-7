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

        //讨论清楚具体情况
        if (p->val < root->val && q->val < root->val) //p q在zuo侧
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)// p q 在右侧
            return lowestCommonAncestor(root->right, p, q);

        return root;//此时有三种可能
        //1、p和q一左一右，最近公共节点就是root
        //2、p在左或者右， q为root，最近公共节点就是root
        //3、q在左或者右， p为root，最近公共节点就是root

    }
};

int main() {

	system("pause");
	return 0;
}