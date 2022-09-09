#include "Graph.h"
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;

Graph::Graph(vector<Edge> const& points, int n) {
	adjList.resize(n);

	for (auto &point : points)
	{
		adjList[point.start].push_back(make_pair(point.dest, point.capacity));
	}
}

void Graph::printGraph(Graph const& graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (Pair v : graph.adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        cout << endl;
    }
}

void Graph::MakeEmptyGraph(int n)
{
    for (int i = 0; i < n; i++) 
    {
        adjList[i].clear();
    }
}

void Graph::AddEdge(int u, int v, int c)
{
    adjList[u].push_back(make_pair(v, c));
}

void Graph::RemoveEdge(int u, int v)//Check
{
    int position = FindPosition(adjList[u], v);

    if (position != -1) 
    {
        adjList[u].erase(adjList[u].begin() + position);
    }
}

int FindPosition(vector<Pair> const &AdjListU, int v)
{
    int position = 0;
    bool flag = false;

    for (Pair w : AdjListU) 
    {
        if (w.first == v) 
        {
            flag = true;
            break;
        }
        else 
        {
            position++;
        }
    }
    return flag ? position : -1;
}