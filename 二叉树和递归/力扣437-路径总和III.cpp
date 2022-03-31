#include<iostream>
#include<unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};


// class Solution {
// public:
//     int count = 0;
//     //在以root为根节点的二叉树中，寻找和为sum的路径，返回这样的路径的个数
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root == NULL) return 0;

//         int res = findPath(root, targetSum);
//         res += pathSum(root->left, targetSum);
//         res += pathSum(root->right, targetSum);

//         return res;



//     }
// private:
//     //在以node为根节点的二叉树中，寻找包含node路径,返回路径个数
//     int findPath(TreeNode* node, int targetSum){
//         if(node == NULL) return 0;
//         int res = 0;

//         if(node->val == targetSum) res += 1;//此时不能return，因为后续可能还会有满足题意的，数字有负数

//         res += findPath(node->left, targetSum - node->val);

//         res += findPath(node->right, targetSum - node->val);

//         return res;

//     }
// };

//优化：前缀和思路,
class Solution {
public:

    //在以root为根节点的二叉树中，寻找和为sum的路径，返回这样的路径的个数
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        unordered_map<int, int>hashMap; //<前缀和,个数>
        hashMap[0] = 1;//自己到自己的节点路径，即单节点.
        //对于空路径我们也需要保存预先处理一下，此时因为空路径不经过任何节点，因此它的前缀和为 0


        int curSum = 0; //记录下根节点 root 到当前节点 node 的路径上除当前节点以外所有节点的前缀和
        return __pathSum(root, targetSum, curSum, hashMap);

    }
private:
    //注意，这里unordered_map使用引用传递 &
    //curSum 记录下根节点 root 到当前节点 node 的路径上除当前节点以外所有节点的前缀和
    int __pathSum(TreeNode* node, int targetSum, int curSum, unordered_map<int, int>& hashMap) {
        //
        if (node == NULL) return 0;
        int res = 0;
        curSum += node->val;

        res += hashMap[curSum - targetSum];//如果不存在key为curSum - targetSum，默认为空，res+0 =res，不影响

        hashMap[curSum] ++;
        res += __pathSum(node->left, targetSum, curSum, hashMap);
        res += __pathSum(node->right, targetSum, curSum, hashMap);
        hashMap[curSum] --;
        return res;
    }

};

int main() {

	system("pause");
	return 0;
}