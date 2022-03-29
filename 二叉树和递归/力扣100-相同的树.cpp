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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL)
            return false;
        else if (q == NULL)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
        // 确保左子树相同，在判断右子树相同 ，最后判断根节点相同
    }
};

int main() {

	system("pause");
	return 0;
}