
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	//������ɢ�����������㷨�Ƚ��鷳��Ŀǰû��ʵ��
	string longestPalindrome(string s)
	{
		int maxLen = 0;
		int left = 0;
		int right = 0;
		int maxleft = 0;
		for (int i = 0; i < s.size(); i++)
		{
			left = i;
			right = i;
			while (right + 1 < s.size() && s[right + 1] == s[right])
			{
				right++;
			}
			while (left >= 0 && right < s.size() && s[left] == s[right])
			{
				left--;
				right++;
			}
			if (right - left - 1 > maxLen)
			{
				maxLen = right - left - 1;
				maxleft = left + 1;
			}
		}
		return s.substr(maxleft, maxLen);
	}
};

/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�


ʾ�� 2��

����: "cbbd"
���: "bb"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-palindromic-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


int main()
{

	return 0;
}
