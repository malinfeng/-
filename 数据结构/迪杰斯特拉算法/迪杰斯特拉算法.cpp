
#include <iostream>
#include <vector>

using namespace std;

#define MD 65535


//记住要点
//一个S集用来表示已知的到达start最短路径的点的集合
//ret  记录当前start到达各点的最短路径，即返回值

class Solution
{
public:
	std::vector<int> Dijkstra(const vector<vector<int> > &mygraph, int start)
	{
		int pointsMax = mygraph.size();
		vector<int> vecs(pointsMax, 0);
		vector<int> ret(mygraph[start]);
		vecs[start] = 1;
		int pointcount = 1;
		while (pointcount < pointsMax)
		{
			int tempmin = MD;
			int curpos = 0;
			for (int i = 0; i < pointsMax; ++i)//剩下的集中找最小
			{
				if (vecs[i] == 0 && 0 < ret[i] && ret[i] < tempmin)//tempmin 指start到curpos的最小值
				{
					tempmin = ret[i];
					curpos = i;
				}
			}

			vecs[curpos] = 1;//加入S集

			for (int i = 0; i < pointsMax; ++i)//从curpos中转，比较近
			{
				if (vecs[i] == 0 && tempmin + mygraph[curpos][i] < ret[i])//更新最小值
				{
					ret[i] = tempmin + mygraph[curpos][i];
				}
			}

			pointcount++;
		}
		return ret;
	}
};


int main()
{
	vector<vector<int> > mygraph =
	{	{0,  MD,10,MD,30,100},
		{MD, 0, 5, MD,MD,MD},
		{10, 5, 0, 50,MD,MD},
		{MD, MD,50,0, 20,10},
		{30, MD,MD,20,0, 60},
		{100,MD,MD,10,60,0} };
	Solution a;
	auto ret = a.Dijkstra(mygraph, 0);
	return 0;
}