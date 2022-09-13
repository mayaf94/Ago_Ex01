#ifndef AGO_EX01_FORDFULKERSONALGORITHM_H
#define AGO_EX01_FORDFULKERSONALGORITHM_H
#include "Graph.h"
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include "Edge.h"
using namespace std;


class FordFulkersonAlgorithm {
private:
    std::priority_queue<pair<int, int>> MaxQueue;
    vector<bool> ignoreVertexCopy;
    void buildPriorityQueue(vector<int>& d, vector<int>& p, int s, int t);
public:
    int fordFulkerson(Graph & graph, int s, int t, bool searchMode);

    bool bfs(Graph& rGraph, int s, int t, vector<int> & parent);

    bool DijkstraModificationToFindMaximumFlowPath(Graph rGraph, int s, int t, vector<int>& parent);

    void initDijkstra(vector<int>& d, vector<int>& p, int s, int t);

    Edge makeEdge(int u, int v, int c);

    int getCapacityFromPair(vector<Pair> const& AdjListU, int v);




};
#endif
