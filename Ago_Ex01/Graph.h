#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "Edge.h"
using std::pair;
using std::vector;

typedef pair<int, int> Pair;

typedef class Graph{
private:
	vector<vector<Pair>> adjList;
	vector<int> S;
	vector<int> T;

public:
	Graph(vector<Edge> const& points, int n);
	void printGraph(Graph const& graph, int n);
	vector<Pair> GetAdjList(int u) { return adjList[u]; }
	void MakeEmptyGraph(int n);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	int GraphSize() { return adjList.size(); }
	void ChangeCapacity(int u, int v, int c, bool operation);
	static Edge makeEdge(int u, int v, int c);
	void MinCut(vector<int> parent, int s, int t, int n);
	void PrintGroup(bool flage);
};

#endif
