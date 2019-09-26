
#include <iostream>

using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        str += ch;
        count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i = 0; i < str.size();++i)
        {
            if(count[str[i]]==1)
            {
                return str[i];
            }
        }
        return '#';
    }
    string str;
    char count[256]={0};
};

//请实现一个函数用来找出字符流中第一个只出现一次的字符。
//例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
//当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
//如果当前字符流没有存在出现一次的字符，返回#字符。

int main()
{

	return 0;
}


