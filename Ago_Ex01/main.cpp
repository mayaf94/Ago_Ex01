#include <iostream>
#include <ostream>
#include "InputTest.h"
#include "Graph.h"
#include "FordFulkersonAlgorithem.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int n;
	int m;
	int s;
	int t;
	int i;
	int j;
	int c;
	vector<Edge> edges;
	int max_flow;
	

	n = InputTest::getNumberOfPointsOrArchery();
	m = InputTest::getNumberOfPointsOrArchery();
	s = InputTest::getNumberOfPointsOrArchery();
	t = InputTest::getNumberOfPointsOrArchery();
	string* strings = InputTest::GettingParams(3, false);

	for (int w = 0; w < m; w++)
	{
		i = atoi(strings[0].c_str()) - 1;
		j = atoi(strings[1].c_str()) - 1;
		c = atoi(strings[2].c_str());
		edges.push_back(Graph::makeEdge(i, j, c));
		strings = InputTest::GettingParams(3, false);
	}

	Graph graph(edges, n);

	max_flow = FordFulkersonAlgorithem::fordFulkerson(graph, s - 1, t - 1);
	cout << "Max flow is: " << max_flow << endl;
}