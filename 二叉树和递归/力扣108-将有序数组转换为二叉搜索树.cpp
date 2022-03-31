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
//         //��һ��������м�ֵ����һ�����ڵ㣬
//         return binaryArray(nums, 0, nums.size()-1);
//     }
// private:
//     TreeNode* binaryArray(vector<int>& nums, int left, int right){
//         if(left > right) return NULL; //��left==rightʱ�򣬻����Դ����ڵ㣬Ȼ���ȥ���ҽڵ�ݹ�ʱ�򣬶�����NULL������
//         //����һ���ڵ㣬����ָ��ָ�������֣���󷵻ظýڵ�
//         //�� nums[left,right]�Ĳ��ֶ���Ϊ middle = left + (right - left)/2 + 1;
//         //nums[left,middle-1] ��nums[left,middle+1]
//         int middle = left + (right - left) / 2 ; //����Ϊ����ʱ��ȡ�м�����֣�ż��ʱ��ȡ�м俿ǰ������
//         TreeNode* node = new TreeNode(nums[middle]);
//         node->left = binaryArray(nums, left, middle - 1);
//         node->right = binaryArray(nums, middle + 1, right);
//         return node;

//     }

// };
//�Ż�1  ����ǰ���鷶ΧΪ1ʱ��ֱ�ӷ��ؼ��ɣ�����Ҫ��ȥ�ӵݹ飬���ٺ�ʱ
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //��һ��������м�ֵ����һ�����ڵ㣬
        return binaryArray(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* binaryArray(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new TreeNode(nums[left]);//����ǰ���鷶ΧΪ1ʱ��ֱ�ӷ��ؼ��ɣ�����Ҫ��ȥ�ӵݹ飬���ٺ�ʱ
        //����һ���ڵ㣬����ָ��ָ�������֣���󷵻ظýڵ�
        //�� nums[left,right]�Ĳ��ֶ���Ϊ middle = left + (right - left)/2 + 1;
        //nums[left,middle-1] ��nums[left,middle+1]
        int middle = left + (right - left) / 2; //����Ϊ����ʱ��ȡ�м�����֣�ż��ʱ��ȡ�м俿ǰ������
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