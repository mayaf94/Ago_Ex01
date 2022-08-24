#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "Edge.h"
using namespace std;

typedef pair<int, int> Pair;

typedef class Graph{
private:
	vector<vector<Pair>> adjList;

public:
	Graph(vector<Edge> const& points, int n);
};

#endif
