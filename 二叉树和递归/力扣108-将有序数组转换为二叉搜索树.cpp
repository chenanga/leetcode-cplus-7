#include<iostream>
#include<vector>

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
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         //把一个数组的中间值创建一个根节点，
//         return binaryArray(nums, 0, nums.size()-1);
//     }
// private:
//     TreeNode* binaryArray(vector<int>& nums, int left, int right){
//         if(left > right) return NULL; //当left==right时候，还可以创建节点，然后进去左右节点递归时候，都返回NULL，符合
//         //创建一个节点，左右指针指向两部分，最后返回该节点
//         //把 nums[left,right]的部分二分为 middle = left + (right - left)/2 + 1;
//         //nums[left,middle-1] 和nums[left,middle+1]
//         int middle = left + (right - left) / 2 ; //长度为奇数时候，取中间的数字，偶数时候取中间靠前的数字
//         TreeNode* node = new TreeNode(nums[middle]);
//         node->left = binaryArray(nums, left, middle - 1);
//         node->right = binaryArray(nums, middle + 1, right);
//         return node;

//     }

// };
//优化1  当当前数组范围为1时候，直接返回即可，不需要进去子递归，减少耗时
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //把一个数组的中间值创建一个根节点，
        return binaryArray(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* binaryArray(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new TreeNode(nums[left]);//当当前数组范围为1时候，直接返回即可，不需要进去子递归，减少耗时
        //创建一个节点，左右指针指向两部分，最后返回该节点
        //把 nums[left,right]的部分二分为 middle = left + (right - left)/2 + 1;
        //nums[left,middle-1] 和nums[left,middle+1]
        int middle = left + (right - left) / 2; //长度为奇数时候，取中间的数字，偶数时候取中间靠前的数字
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = binaryArray(nums, left, middle - 1);
        node->right = binaryArray(nums, middle + 1, right);
        return node;

    }

};
int main() {

	system("pause");
	return 0;
}