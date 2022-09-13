#include "Graph.h"
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;

int FindPosition(vector<Pair> const& AdjListU, int v);

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
void Graph::RemoveEdge(int u, int v)//Check
{
    int position = FindPosition(adjList[u], v);

    if (position != -1)
    {
        adjList[u].erase(adjList[u].begin() + position);
    }
}


void Graph::ChangeCapacity(int u, int v, int c, bool operation)
{
    if (operation)
    {
        adjList[u].at(FindPosition(adjList[u], v)).second += c;
    }
    else
    {
        adjList[u].at(FindPosition(adjList[u], v)).second -= c;
    }
}

Edge Graph::makeEdge(int u, int v, int c)
{
    Edge edge = { u, v, c };
    return edge;
}

void Graph::MinCut(vector<int> parent, int s, int t, int n)
{
    for (int i = 0; i < n; i++) 
    {
        if (i == s) {
            S.push_back(s);
        }
        else if (i == t) {
            T.push_back(t);
        }
        else if (parent[i] == -1) {
            T.push_back(i);
        }
        else
        {
            S.push_back(i);
        }
    }
}

void Graph::PrintGroup(bool flag) 
{
    if (flag)
    {
        for (int i = 0; i < S.size(); i++)
        {
            if (i == S.size() - 1)
                cout << S[i] + 1 << ".";
            else
                cout << S[i] + 1 << ",";
        }
        S.clear();
    }
    else
    {
        for (int i = 0; i < T.size(); i++) {
            if (i == T.size() - 1)
                cout << T[i] + 1;
            else
                cout << T[i] + 1 << ",";
        }
        T.clear();
    }
}