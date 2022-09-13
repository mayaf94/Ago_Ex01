#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include "FordFulkersonAlgorithem.h"

using namespace std;
int getCapacityFromPair(vector<Pair> const& AdjListU, int v);


/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool bfs(Graph &rGraph, int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not
    // visited
    bool* visited = new bool[rGraph.GraphSize()];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Pair v: rGraph.GetAdjList(u)) {
            if (visited[v.first] == false &&  v.second > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v.first == t) {
                    parent[v.first] = u;
                    return true;
                }
                q.push(v.first);
                parent[v.first] = u;
                visited[v.first] = true;
            }
        }
    }

    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}

// Returns the maximum flow from s to t in the given graph
int FordFulkersonAlgorithem::fordFulkerson(Graph graph, int s, int t)
{
    int n = graph.GraphSize();
    int u, v;

    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    vector<Edge> points;
    for (int u = 0; u < n; u++)
    {
        for (Pair v : graph.GetAdjList(u)) 
        {
            points.push_back(Graph::makeEdge(u, v.first, v.second));
            points.push_back(Graph::makeEdge(v.first, u, 0));
        }
    }
    Graph rGraph(points, n);
        // Residual graph where rGraph
             // indicates residual capacity of edge
             // from i to j (if there is an edge. If
             // rGraph[i][j] is 0, then there is not)
    int* parent = new int[n]; // This array is filled by BFS and to
                   // store path

    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to
    // sink
    while (bfs(rGraph, s, t, parent)) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, getCapacityFromPair(rGraph.GetAdjList(u), v));
        }

        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph.ChangeCapacity(u, v, path_flow, false);
            rGraph.ChangeCapacity(v, u, path_flow, true);
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}

int getCapacityFromPair(vector<Pair> const& AdjListU, int v)
{
    int capacity = 0;
    for (Pair w : AdjListU)
    {
        if (w.first == v)
        {
            capacity = w.second;
        }
    }
    return capacity;
}