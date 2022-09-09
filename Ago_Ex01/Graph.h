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

public:
	Graph(vector<Edge> const& points, int n);
	void printGraph(Graph const& graph, int n);
	vector<Pair> GetAdjList(int u) { return adjList[u]; }
	void MakeEmptyGraph(int n);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
};

#endif
