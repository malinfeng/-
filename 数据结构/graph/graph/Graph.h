#pragma once
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>

//���Ƿ��з���
#define DIRECTION 1
//��󶥵�����
#define MAXVERTEX 20

struct Edge
{
	Edge(int start, int end, int weight)
		:
		_startIdx(start),
		_endIdx(end),
		_weight(weight),
		_pnext(NULL)
	{}
	int _startIdx;
	int _endIdx;
	int _weight;
	Edge *_pnext;	//�ڽӱ��У�ָ����һ����
};

template <typename T>
struct Vertex
{
	Vertex() 
		:
		_data(0),
		_edge(NULL)
	{}
	Vertex(std::string &str, T d)
		:
		_data(d),
		_edge(NULL)
	{}
	std::string name;	//��������
	T _data;				//����
	Edge *_edge;			//��֮��رߵ�ָ��
};



template <typename T>
class Graph//ʹ�ñ�׼��ʽ--�ڽӱ��ʾ��ͼ
{
public:
	Graph():
		_curVertexNum(0)
	{
		_vertexs.resize(MAXVERTEX);
	}
	~Graph()//Ӧ��������Ӧ�Ķ�̬�ڴ�
	{

	}

	void dfs(std::string startVertex)
	{
		if (_name2idx.find(startVertex) == _name2idx.end())
		{
			std::cout << "���㲻����" << std::endl;
			return;
		}
		int curIdx = _name2idx[startVertex];
		std::vector<int> visited(_curVertexNum, 0);
		std::stack<int> mys;
		int visitedNum = 0;
		mys.push(curIdx);
		while (visitedNum < _curVertexNum)
		{
			if (mys.empty())
			{
				std::cout << "��ͼΪ����ͨͼ" << std::endl;
				return;
			}
			curIdx = mys.top();
			mys.pop();

			std::cout << _vertexs[curIdx].name << std::endl;	//���ʲ���
			visitedNum++;
			visited[curIdx] = 1;
			Edge *tempEdge = _vertexs[curIdx]._edge;
			while (tempEdge)
			{
				if (!visited[tempEdge->_endIdx])
				{
					mys.push(tempEdge->_endIdx);
				}
				tempEdge = tempEdge->_pnext;
			}
		}
	}

	void bfs(std::string startVertex)
	{
		if (_name2idx.find(startVertex) == _name2idx.end())
		{
			std::cout << "���㲻����" << std::endl;
			return;
		}
		int curIdx = _name2idx[startVertex];
		std::vector<int> visited(_curVertexNum, 0);
		std::queue<int> myq;
		myq.push(curIdx);	//ֻҪ��������У����൱�ڱ������ˣ���Ϊ�����ظ���ӽ�����
		visited[curIdx] = 1;
		while (!myq.empty())
		{
			curIdx = myq.front();
			myq.pop();
			std::cout << _vertexs[curIdx].name << std::endl;	//���ʲ���
			Edge *tempEdge = _vertexs[curIdx]._edge;
			while (tempEdge)
			{
				if (!visited[tempEdge->_endIdx])
				{
					myq.push(tempEdge->_endIdx);
					visited[tempEdge->_endIdx] = 1;
				}
				tempEdge = tempEdge->_pnext;
			}
		}
	}

	void modVertex(std::string name, T data)
	{
		int curidx = 0;
		if (_name2idx.find(name) != _name2idx.end())//�����Ѿ����
		{
			curidx = _name2idx[name];
		}
		else//�¶���
		{
			_name2idx[name] = _curVertexNum;
			curidx = _curVertexNum;
			_curVertexNum++;
		}
		_vertexs[curidx].name = name;
		_vertexs[curidx]._data = data;
	}

	void modEdge(std::string start, std::string end, int weight)
	{
		int startidx = 0;
		int endidx = 0;
		if (_name2idx.find(start) == _name2idx.end()	
			|| _name2idx.find(end) == _name2idx.end())	//��֤�������
		{
			return;
		}
		startidx = _name2idx[start];
		endidx = _name2idx[end];

		addedge_num(startidx, endidx, weight);
		if (!DIRECTION)//����ͼ
		{
			addedge_num(endidx, startidx, weight);
		}
	}

	std::map<std::string, int> dijsktra(std::string start)
	{
		std::map<std::string, int> retmap;
		if (_name2idx.find(start) == _name2idx.end())
		{
			std::cout << "���㲻����" << std::endl;
			return retmap;
		}
		int curIdx = _name2idx[start];

		std::vector<int> s(_curVertexNum, 0);//S��
		std::vector<int> dis(_curVertexNum, INT_MAX);//dis��
		dis[curIdx] = 0;
		Edge *tempEdge = _vertexs[curIdx]._edge;
		while (tempEdge)//��ʼ��dis��
		{
			dis[tempEdge->_endIdx] = tempEdge->_weight;
			tempEdge = tempEdge->_pnext;
		}

		int visitedNum = 1;
		while (visitedNum < _curVertexNum)
		{
			int curmindis = INT_MAX; 
			curIdx = -1;
			for (int i = 0; i < _curVertexNum; ++i)
			{
				if (!s[i] && dis[i] < curmindis)
				{
					curIdx = i;
				}
			}
			if (curIdx == -1)//����ͨͼ�������Ѿ�������
			{
				for (unsigned int i = 0; i < _vertexs.size(); ++i)
				{
					retmap[_vertexs[i].name] = dis[i];
				}
				return retmap;
			}

			tempEdge = _vertexs[curIdx]._edge;
			while (tempEdge)//����dis
			{
				//dis����ǰ�� + ��ǰ�㵽�µ� < dis���µ�
				if (dis[curIdx] + tempEdge->_weight < dis[tempEdge->_endIdx])
				{
					dis[tempEdge->_endIdx] = dis[curIdx] + tempEdge->_weight;
				}
				tempEdge = tempEdge->_pnext;
			}
			
			visitedNum++;
		}

		for (int i = 0; i < _curVertexNum; ++i)
		{
			retmap[_vertexs[i].name] = dis[i];
		}
		return retmap;
	}

	//����ͼ�㷨
	Graph<T> prim()
	{
		Graph<T> retg;
		if (_curVertexNum == 0)
		{
			return retg;
		}
		if (!DIRECTION)
		{
			return retg;
		}
		std::vector<int> visited(_curVertexNum, 0);
		visited[0] = 1;
		retg.modVertex(_vertexs[0].name, _vertexs[0]._data);
		int vertexnum = 1;

		while (vertexnum < _curVertexNum)
		{
			int curminWeight = INT_MAX;
			Edge *nextEdge = NULL;
			for (int i = 0; i < _curVertexNum; ++i)
			{
				if (visited[i])//���visit
				{
					Edge *tempEdge = _vertexs[i]._edge;
					while (tempEdge)
					{
						if (!visited[tempEdge->_endIdx] && tempEdge->_weight < curminWeight)
						{
							curminWeight = tempEdge->_weight;
							nextEdge = tempEdge;
						}
						tempEdge = tempEdge->_pnext;
					}
				}
			}
			if (nextEdge)
			{
				retg.modVertex(_vertexs[nextEdge->_endIdx].name, _vertexs[nextEdge->_endIdx]._data);
				retg.modEdge(_vertexs[nextEdge->_startIdx].name, _vertexs[nextEdge->_endIdx].name, nextEdge->_weight);
				visited[nextEdge->_endIdx] = 1;
				vertexnum++;
			}
			else
			{
				std::cout << "��ͼΪ����ͨͼ" << std::endl;
				break;
			}
		}
		return retg;
	}

	//����ͼ�㷨
	Graph<T> kruskal()
	{
		Graph<T> retg;
		if (!DIRECTION)
		{
			return retg;
		}
		std::vector<Edge*> edges;	//�߱�
		std::vector<int> fathers(_curVertexNum, -1);	//���鼯

		for (int i = 0; i < _curVertexNum; ++i)
		{
			retg.modVertex(_vertexs[i].name, _vertexs[i]._data);//Ĭ��������ж���
			Edge *tempEdge = _vertexs[i]._edge;
			while (tempEdge)
			{
				edges.push_back(tempEdge);
				tempEdge = tempEdge->_pnext;
			}
		}
		sort(edges.begin(), edges.end(), CMP);

		unsigned int degesIdx = 0;
		Edge *curEdge = NULL;
		int edgenum = 0;

		while (edgenum < _curVertexNum - 1 && degesIdx < edges.size())
		{
			curEdge = edges[degesIdx];
			int startf = familyFather(fathers, curEdge->_startIdx);
			int endf = familyFather(fathers, curEdge->_endIdx);

			if (startf != endf)//�ߺ���
			{
				fathers[endf] = startf;
				retg.modEdge(_vertexs[curEdge->_startIdx].name, _vertexs[curEdge->_endIdx].name, curEdge->_weight);
				edgenum++;
			}
			degesIdx++;
		}
		return retg;
	}
	

	//ʹ�þ���ʽ��ӡͼ
	void printGraph()
	{
		std::vector<std::vector<int> > tempgraph(_curVertexNum, std::vector<int>(_curVertexNum, 0));
		
		// ��һ�д�ӡ����
		std::cout << '\t';
		for (int i = 0; i < _curVertexNum; ++i)
		{
			std::cout << _vertexs[i].name << '\t';
		}
		std::cout << std::endl;

		for (int i = 0; i < _curVertexNum; ++i)//iΪ���
		{
			Edge *pcurEdge = _vertexs[i]._edge;
			while (pcurEdge)
			{
				tempgraph[pcurEdge->_startIdx][pcurEdge->_endIdx] = pcurEdge->_weight;
				pcurEdge = pcurEdge->_pnext;
			}
		}
		for (unsigned int i = 0; i < tempgraph.size(); ++i)
		{
			std::cout << _vertexs[i].name << '\t';
			for (unsigned int j = 0; j < tempgraph[i].size(); ++j)
			{
				std::cout << tempgraph[i][j] << '\t';
			}
			std::cout << std::endl;
		}
	}
private:
	//���һ�������
	void addedge_num(int startIdx, int endIdx, int weight)
	{
		Vertex<T> &curV = _vertexs[startIdx];
		Edge *pedge = curV._edge;
		if (pedge)
		{
			while (pedge->_pnext)
			{
				if (pedge->_endIdx == endIdx)//˵���ñߴ���
				{
					pedge->_weight = weight;
					return;
				}
				pedge = pedge->_pnext;
			}
			pedge->_pnext = new Edge(startIdx, endIdx, weight);
			return;
		}
		else
		{
			curV._edge = new Edge(startIdx, endIdx, weight);
			return;
		}
	}

	static bool CMP(Edge *e1, Edge *e2)
	{
		return e1->_weight < e2->_weight;
	}

	int familyFather(const std::vector<int> &father, int idx)
	{
		while (father[idx] != -1 && father[idx] != idx)
		{
			idx = father[idx];
		}
		return idx;
	}
private:
	std::vector<Vertex<T>> _vertexs;
	std::map<std::string, int> _name2idx;
	int _curVertexNum;
};

