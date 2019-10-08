
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int len1 = nums1.size();
		int len2 = nums2.size();
		if ((len1 + len2) & 1)
		{
			return helpfindKth(nums1, 0, nums2, 0, (len1 + len2) / 2 + 1);
		}
		else
		{
			return (helpfindKth(nums1, 0,  nums2, 0, (len1 + len2) / 2 + 1) 
				+ helpfindKth(nums1, 0,  nums2, 0, (len1 + len2 ) / 2)) / 2.0;
		}
	}

	double helpfindKth(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k)
	{
		if (s1 >= nums1.size())
		{
			return nums2[s2 + k - 1];
		}
		if (s2 >= nums2.size())
		{
			return nums1[s1 + k - 1];
		}
		if (k == 1)
		{
			return min(nums1[s1], nums2[s2]);
		}
		//�Ƿ���k/2��������һ�����鲻����ʱ����ֱ����̭���һ�����K/2������
		int midVal1 = (s1 + k / 2 - 1 < nums1.size()) ? nums1[s1 + k / 2 - 1] : INT_MAX;
		int midVal2 = (s2 + k / 2 - 1 < nums2.size()) ? nums2[s2 + k / 2 - 1] : INT_MAX;

		if (midVal1 < midVal2)
		{
			return helpfindKth(nums1, s1 + k / 2, nums2, s2, k - k / 2);
		}
		else
		{
			return helpfindKth(nums1, s1, nums2, s2 + k / 2, k - k / 2);
		}
	}
};


/*
����������СΪ m �� n ���������� nums1 �� nums2��

�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��

����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�

ʾ�� 1:

nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0


ʾ�� 2:

nums1 = [1, 2]
nums2 = [3, 4]

����λ���� (2 + 3)/2 = 2.5

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/median-of-two-sorted-arrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


int main()
{
	Solution a;
	vector<int> vec1 = { 1, 2 };
	vector<int> vec2 = { 3, 4 };
	auto ret = a.findMedianSortedArrays(vec1, vec2);
	return 0;
}

