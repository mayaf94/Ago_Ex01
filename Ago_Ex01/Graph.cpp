#include "Graph.h"

Graph::Graph(vector<Edge> const& points, int n) {
	adjList.resize(n);

	for (auto &point : points)
	{
		adjList[point.start].push_back(make_pair(point.dest, point.capacity));
	}
}