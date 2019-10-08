
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) 
	{
		vector<string> tempvecs(numRows, "");
		if (numRows == 1)
		{
			return s;
		}
		string ret;
		for (int i = 0; i < s.size(); ++i)
		{
			int line = i % (2 * (numRows - 1));
			if (line < numRows)
			{
				tempvecs[line] += s[i];
			}
			else
			{
				tempvecs[2 * (numRows - 1) - line] += s[i];
			}
		}
		for (int i = 0; i < numRows; ++i)
		{
			ret += tempvecs[i];
		}
		return ret;
	}
};

/*
��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�

L   C   I   R
E T O E S I I G
E   D   H   N


֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);

ʾ�� 1:

����: s = "LEETCODEISHIRING", numRows = 3
���: "LCIRETOESIIGEDHN"


ʾ�� 2:

����: s = "LEETCODEISHIRING", numRows = 4
���: "LDREOEIIECIHNTSG"
����:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/zigzag-conversion
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


int main()
{
	Solution a;
	auto ret = a.convert("LEETCODEISHIRING", 4);
	return 0;
}
