
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return true;
		}
		return HelpisSymmetrical(pRoot->left, pRoot->right);
	}
	
	bool HelpisSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL && pRoot2 == NULL)
		{
			return true;
		}
		else if (pRoot1 && pRoot2  && pRoot1->val == pRoot2->val)
		{
			return HelpisSymmetrical(pRoot1->left, pRoot2->right) && HelpisSymmetrical(pRoot1->right, pRoot2->left);
		}
		else
		{
			return false;
		}
	}
};

//请实现一个函数，用来判断一颗二叉树是不是对称的。
//注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

int main()
{
	TreeNode *pnode = new TreeNode(1);
	pnode->left = new TreeNode(2);
	pnode->right = new TreeNode(2);
	
	Solution a;
	bool ret = a.isSymmetrical(pnode);
	
	return 0;
}


